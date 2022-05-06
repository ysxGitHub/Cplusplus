#pragma once
#include <queue>
#include <string>
#include <mutex>
#include <condition_variable>
#include "MySQLConn.h"
class ConnectionPool
{
public:
	// 单例模式<懒汉模式>返回静态局部变量
	static ConnectionPool* getConnectPool();
	// 禁止 copy 构造
	ConnectionPool(const ConnectionPool& obj) = delete;
	// 禁止 = copy 构造
	ConnectionPool& operator=(const ConnectionPool& obj) = delete;
	// 得到连接池中的连接
	std::shared_ptr<MySQLConn> getConnection();
	
	~ConnectionPool();
private:
	ConnectionPool();
	// 解析json文件
	bool parseJsonFile();
	// 添加连接
	void addConnection();
	// 生成者任务函数 
	void produceConnection();
	// 回收者任务函数
	void recycleConnection();
private:
	// 连接池队列
	std::queue<MySQLConn*> m_connectionQ;
	// 连接属性
	std::string m_ip;
	std::string m_user;
	std::string m_passwd;
	std::string m_dbName;
	unsigned short m_port;

	// 连接上限与下限
	int m_minSize;
	int m_maxSize;

	// 超时时常，
	int m_timeout;
	// 最大空闲时常
	int m_maxIdleTime;
	
	// 连接池的互斥锁
	std::mutex m_mutexQ;
	// 消费者与生产者的条件锁
	std::condition_variable m_cond;
};

