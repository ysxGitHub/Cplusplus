#include "ConnectionPool.h"

ConnectionPool* ConnectionPool::getConnectPool()
{
	// ������̬�ֲ����� 
	static ConnectionPool pool;
	return &pool;
}
