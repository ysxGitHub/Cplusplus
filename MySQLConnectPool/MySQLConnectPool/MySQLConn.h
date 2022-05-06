﻿#pragma once
#include <string>
#include <mysql.h>
#include <chrono>
class MySQLConn
{
public:
	// 初始化数据库连接
	MySQLConn();
	// 释放数据库连接
	~MySQLConn();
	// 连接数据库
	bool connect(std::string user, std::string password, std::string dbname, std::string ip, unsigned short port = 3306);
	// 更新数据库：insert，update，delete
	bool update(std::string sql);
	// 查询数据库
	bool query(std::string sql);
	// 遍历查询得到的结果集
	bool next();
	// 得到结果集中的字段值
	std::string value(int index);
	// 事务操作
	bool transaction();
	// 提交事务
	bool commit();
	// 事务回滚
	bool rollback();
	// 刷新起始的空闲时间点
	void refreshAliveTime();
	// 计算连接存活的总时长
	long long getAliveTime();

private:
	MYSQL* m_conn = nullptr;
	MYSQL_RES* m_result = nullptr;
	MYSQL_ROW m_row = nullptr;
	void freeResult();
	// 绝对时钟
	std::chrono::steady_clock::time_point m_alivetime;
};

