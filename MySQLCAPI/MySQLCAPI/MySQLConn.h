#pragma once
#include <string>
#include <mysql.h>
class MySQLConn
{
public:
	// ��ʼ�����ݿ�����
	MySQLConn();
	// �ͷ����ݿ�����
	~MySQLConn();
	// �������ݿ�
	bool connect(std::string user, std::string password, std::string dbname, std::string ip, unsigned short port = 3306);
	// �������ݿ⣺insert��update��delete
	bool update(std::string sql);
	// ��ѯ���ݿ�
	bool query(std::string sql);
	// ������ѯ�õ��Ľ����
	bool next();
	// �õ�������е��ֶ�ֵ
	std::string value(int index);
	// �������
	bool transaction();
	// �ύ����
	bool commit();
	// ����ع�
	bool rollback();
private:
	MYSQL* m_conn = nullptr;
	MYSQL_RES* m_result = nullptr;
	MYSQL_ROW m_row = nullptr;
	void freeResult();
};

