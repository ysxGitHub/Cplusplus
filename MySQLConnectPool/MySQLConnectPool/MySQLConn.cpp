#include "MySQLConn.h"

MySQLConn::MySQLConn()
{
	// 初始化连接环境
	m_conn = mysql_init(nullptr);
	// 设置编码为utf-8
	mysql_set_character_set(m_conn, "utf8");
}

MySQLConn::~MySQLConn()
{
	if (m_conn != nullptr) {
		// 释放数据库资源
		mysql_close(m_conn);
	}
	freeResult();
}

bool MySQLConn::connect(std::string user, std::string password, std::string dbname, std::string ip, unsigned short port)
{
	// 2.连接数据库服务器
	MYSQL* ptr = mysql_real_connect(m_conn,
		ip.c_str(), // mysql服务器的主机地址, 写IP地址即可 (localhost/NULL 代表本地连接)
		user.c_str(), // 连接mysql服务器的用户名, 默认: root
		password.c_str(),   // 连接mysql服务器用户对应的密码, root用户的密码
		dbname.c_str(),  // 要使用的数据库的名字
		port,  // 连接的mysql服务器监听的端口, 如果==0, 使用mysql的默认端口3306, !=0, 使用指定的这个端口
		nullptr, // 本地套接字, 不使用指定为 NULL
		0);
	return ptr != nullptr;
}

bool MySQLConn::update(std::string sql)
{
	// 更新数据库
	if (mysql_query(m_conn, sql.c_str())) {
		return false;
	}
	return true;
}

bool MySQLConn::query(std::string sql)
{
	freeResult();
	// 查询数据库
	if (mysql_query(m_conn, sql.c_str())) {
		return false;
	}
	// 保存结果集
	m_result = mysql_store_result(m_conn);
	return true;
}

bool MySQLConn::next()
{
	if (m_result != nullptr) {
		// 得到一行信息
		m_row = mysql_fetch_row(m_result);
		if (m_row != nullptr) {
			return true;
		}
	}
	return false;
}

std::string MySQLConn::value(int index)
{
	// 得到结果集中的列数
	int colNum = mysql_num_fields(m_result);
	if (index >= colNum || index < 0) {
		return std::string();
	}
	char* val = m_row[index];
	// 得到结果集中该字段的长度 
	unsigned long length = mysql_fetch_lengths(m_result)[index];
	return std::string(val, length);
}

bool MySQLConn::transaction()
{
	// 设置事务为手动提交
	return mysql_autocommit(m_conn, false);
}

bool MySQLConn::commit()
{
	// 提交事务
	return mysql_commit(m_conn);
}

bool MySQLConn::rollback()
{
	// 事务回滚
	return mysql_rollback(m_conn);
}

void MySQLConn::refreshAliveTime()
{
	// 得到时间点
	m_alivetime = std::chrono::steady_clock::now();
}

long long MySQLConn::getAliveTime()
{
	// 得到时间段
	std::chrono::nanoseconds res = std::chrono::steady_clock::now() - m_alivetime;
	// 将 ns 转为 ms
	std::chrono::milliseconds millsec = std::chrono::duration_cast<std::chrono::milliseconds>(res);
	
	// 返回多少个 ms
	return millsec.count();
}

void MySQLConn::freeResult()
{
	// 释放资源 - 结果集
	mysql_free_result(m_result);
}
