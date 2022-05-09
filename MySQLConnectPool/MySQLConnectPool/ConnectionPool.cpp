#include "ConnectionPool.h"
#include <json.h>
#include <fstream>
#include <thread>

bool ConnectionPool::parseJsonFile()
{
	// 得到流对象
	std::ifstream ifs("dbconf.json");
	// 得到读对象
	Json::Reader rd;
	// 存储得到数据
	Json::Value root;
	// 将流对象的数据读入 root
	rd.parse(ifs, root);
	if (root.isObject()) { // 判断是不是 json 对象
		m_ip = root["ip"].asString();
		m_port = root["port"].asInt();
		m_user = root["userName"].asString();
		m_passwd = root["password"].asString();
		m_dbName = root["dbName"].asString();
		m_minSize = root["minSize"].asInt();
		m_maxSize = root["maxSize"].asInt();
		m_maxIdleTime = root["maxIdleTime"].asInt();
		m_timeout = root["timeout"].asInt();
		return true;
	}
	return false;
}

ConnectionPool* ConnectionPool::getConnectPool()
{
	// 创建静态局部对象, C++11 不用考虑线程安全
	static ConnectionPool pool;
	return &pool;
}

void ConnectionPool::addConnection()
{
	MySQLConn* conn = new MySQLConn;
	// 进行数据库连接
	conn->connect(m_user, m_passwd, m_dbName, m_ip, m_port);
	// 更新时间点
	conn->refreshAliveTime();
	// 该连接加入队列
	m_connectionQ.push(conn);
}

std::shared_ptr<MySQLConn> ConnectionPool::getConnection()
{
	std::unique_lock<std::mutex> locker(m_mutexQ);
	// 先判断连接池是否有连接可用
	while (m_connectionQ.empty()) {
		// 阻塞一定时间 m_timeout
		// 阻塞返回 timeout 则队列还是为空
		if (std::cv_status::timeout == m_cond.wait_for(locker, std::chrono::milliseconds(m_timeout))) {
			if (m_connectionQ.empty()) {
				// return nullptr; // 返回null
				continue; // or 继续阻塞
			}
		}
	}
	// 连接池不为空，返回头部连接并且要弹出
	// 利用共享智能指针可以进行 连接的指针回收，这里需要指定第二个参数
	std::shared_ptr<MySQLConn>connptr(m_connectionQ.front(), [this](MySQLConn* conn) {
		std::lock_guard<std::mutex> locker(m_mutexQ); // 自动加锁与解锁，但是不能控制锁定的范围
		// m_mutexQ.lock(); // 加锁 方法2
		// 更新时间节点
		conn->refreshAliveTime();
		// 加入连接池队列
		m_connectionQ.push(conn);
		// m_mutexQ.unlock();
		});
	m_connectionQ.pop();
	// 唤醒生产者
	m_cond.notify_all();
	return connptr;
}

ConnectionPool::ConnectionPool()
{
	// 加载配置文件
	if (!parseJsonFile()) {
		return;
	}
	for (int i = 0; i < m_minSize; ++i) {
		addConnection();
	}
	// 生产连接池种的连接 任务函数 = [有名函数，匿名函数，类的静态成员函数，类的非静态成员函数，可调用对象]
	std::thread producer(&ConnectionPool::produceConnection, this);
	// 检测有么有要销毁的连接
	std::thread recycler(&ConnectionPool::recycleConnection, this);
	producer.detach();
	recycler.detach();
}

void ConnectionPool::produceConnection()
{
	while (true) {
		// unique_lock 模板类 
		// locker 对象创建出来就对 m_mutexQ 自动加锁
		std::unique_lock<std::mutex> locker(m_mutexQ);
		while (m_connectionQ.size() >= m_minSize) { // 这里要用 while 重复判断是否还需要添加连接
			// 当生产者多个线程阻塞这里
			m_cond.wait(locker);
		} 
		 // 添加连接
		addConnection();
		// 唤醒消费者
		m_cond.notify_all();
	} // 作用域结束, locker 对象 析构会 m_mutexQ 自动解锁
}

void ConnectionPool::recycleConnection()
{
	while (true) {

		//500ms 周期性检测
		std::this_thread::sleep_for(std::chrono::milliseconds(500));

		std::lock_guard<std::mutex> locker(m_mutexQ);
		// 判断是否大于最小保留连接数量
		while (m_connectionQ.size() > m_minSize) {
			// 队头一定是存活最久的连接
			MySQLConn* conn = m_connectionQ.front();
			// 判断该连接的空闲时长是否超过最大空闲时长
			if (conn->getAliveTime() >= m_maxIdleTime) {
				delete conn;
			}
			else {
				break;
			}
		}
	}
}

ConnectionPool::~ConnectionPool()
{
	while (!m_connectionQ.empty()) {
		// 释放内存
		MySQLConn* conn = m_connectionQ.front();
		m_connectionQ.pop();
		delete conn;
	}
}
