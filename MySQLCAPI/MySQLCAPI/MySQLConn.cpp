#include "MySQLConn.h"

MySQLConn::MySQLConn()
{
	// ��ʼ�����ӻ���
	m_conn = mysql_init(nullptr);
	// ���ñ���Ϊutf-8
	mysql_set_character_set(m_conn, "utf8");
}

MySQLConn::~MySQLConn()
{
	if (m_conn != nullptr) {
		// �ͷ����ݿ���Դ
		mysql_close(m_conn);
	}
	freeResult();
}

bool MySQLConn::connect(std::string user, std::string password, std::string dbname, std::string ip, unsigned short port)
{
	// 2.�������ݿ������
	MYSQL* ptr = mysql_real_connect(m_conn,
		ip.c_str(), // mysql��������������ַ, дIP��ַ���� (localhost/NULL ����������)
		user.c_str(), // ����mysql���������û���, Ĭ��: root
		password.c_str(),   // ����mysql�������û���Ӧ������, root�û�������
		dbname.c_str(),  // Ҫʹ�õ����ݿ������
		port,  // ���ӵ�mysql�����������Ķ˿�, ���==0, ʹ��mysql��Ĭ�϶˿�3306, !=0, ʹ��ָ��������˿�
		nullptr, // �����׽���, ��ʹ��ָ��Ϊ NULL
		0);
	return ptr != nullptr;
}

bool MySQLConn::update(std::string sql)
{
	// �������ݿ�
	if (mysql_query(m_conn, sql.c_str())) {
		return false;
	}
	return true;
}

bool MySQLConn::query(std::string sql)
{
	freeResult();
	// ��ѯ���ݿ�
	if (mysql_query(m_conn, sql.c_str())) {
		return false;
	}
	// ��������
	m_result = mysql_store_result(m_conn);
	return true;
}

bool MySQLConn::next()
{
	if (m_result != nullptr) {
		// �õ�һ����Ϣ
		m_row = mysql_fetch_row(m_result);
	}
	return false;
}

std::string MySQLConn::value(int index)
{
	// �õ�������е�����
	int colNum = mysql_num_fields(m_result);
	if (index >= colNum || index < 0) {
		return std::string();
	}
	char* val = m_row[index];
	// �õ�������и��ֶεĳ��� 
	unsigned long length = mysql_fetch_lengths(m_result)[index];
	return std::string(val, length);
}

bool MySQLConn::transaction()
{
	// ��������Ϊ�ֶ��ύ
	return mysql_autocommit(m_conn, false);
}

bool MySQLConn::commit()
{
	// �ύ����
	return mysql_commit(m_conn);
}

bool MySQLConn::rollback()
{
	// ����ع�
	return mysql_rollback(m_conn);
}

void MySQLConn::freeResult()
{
	// �ͷ���Դ - �����
	mysql_free_result(m_result);
}
