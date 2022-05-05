#include "ConnectionPool.h"

ConnectionPool* ConnectionPool::getConnectPool()
{
	// 创建静态局部对象 
	static ConnectionPool pool;
	return &pool;
}
