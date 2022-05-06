
#include <iostream>
#include <memory>
#include "MySQLConn.h"
#include "ConnectionPool.h"

// 单线程：使用/不使用连接池
// 多线程：使用/不使用连接池
void op1(int begin, int end) {
	for (int i = begin; i < end; ++i) {
		MySQLConn conn;
		bool flag = conn.connect("root", "111", "mybase", "localhost", 3306);
		char sql[1024] = { 0 };
		std::sprintf(sql, "insert into t_user values(%d, 'xiaoli')", i);
		flag = conn.update(sql);
	}
}

void op2(ConnectionPool* pool, int begin, int end) {
	for (int i = begin; i < end; ++i) {
		std::shared_ptr<MySQLConn> conn = pool->getConnection();
		char sql[1024] = { 0 };
		sprintf(sql, "insert into t_user values(%d, 'xiaoli')", i);
		conn->update(sql);
	}
}

void test1() {
#if 0
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	op1(0, 5000);
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	auto length = end - begin;
	std::cout << "非连接池, 单线程, 用时: " << length.count() << " 纳秒, " <<
		length.count() / 1000000 << " 毫秒" << std::endl;
#else
	ConnectionPool* pool = ConnectionPool::getConnectPool();
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	op2(pool, 0, 5000);
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	auto length = end - begin;
	std::cout << "连接池, 单线程, 用时: " << length.count() << " 纳秒, " <<
		length.count() / 1000000 << " 毫秒" << std::endl;
#endif
}

void test2() {
#if 0
	// 几个线程同时抢连接，所以要多创建连接
	MySQLConn conn;
	bool flag = conn.connect("root", "111", "mybase", "localhost", 3306);
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	std::thread t1(op1, 0, 1000);
	std::thread t2(op1, 1000, 2000);
	std::thread t3(op1, 2000, 3000);
	std::thread t4(op1, 3000, 4000);
	std::thread t5(op1, 4000, 5000);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	auto length = end - begin;
	std::cout << "非连接池, 多线程, 用时: " << length.count() << " 纳秒, " <<
		length.count() / 1000000 << " 毫秒" << std::endl;
#else
	ConnectionPool* pool = ConnectionPool::getConnectPool();
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	std::thread t1(op2, pool, 0, 1000);
	std::thread t2(op2, pool, 1000, 2000);
	std::thread t3(op2, pool, 2000, 3000);
	std::thread t4(op2, pool, 3000, 4000);
	std::thread t5(op2, pool, 4000, 5000);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	auto length = end - begin;
	std::cout << "连接池, 多线程, 用时: " << length.count() << " 纳秒, " <<
		length.count() / 1000000 << " 毫秒" << std::endl;
#endif
}

int query() {
	MySQLConn conn;
	bool flag = conn.connect("root", "111", "mybase", "localhost", 3306);
	if (flag == 0) {
		std::cout << "数据库连接失败: " << flag << std::endl;
	}
	std::string sql = "delete from t_user where id=5";
	flag = conn.update(sql);
	if (flag == 0) {
		std::cout << "数据库更新失败: " << flag << std::endl;
	}
	sql = "insert into t_user values(5, 'xiaoli')";
	flag = conn.update(sql);
	if (flag == 0) {
		std::cout << "数据库更新失败: " << flag << std::endl;
	}
	sql = "select * from t_user";
	flag = conn.query(sql);
	while (conn.next()) {
		std::cout << conn.value(0) << ", "
			<< conn.value(1) << std::endl;
	}
	return 0;
}

int main() {
	// query();
	// test1();
	test2();
	return 0;
}