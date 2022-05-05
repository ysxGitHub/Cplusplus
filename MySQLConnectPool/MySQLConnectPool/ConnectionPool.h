#pragma once
class ConnectionPool
{
public:
	static ConnectionPool* getConnectPool();
private:
	ConnectionPool();
	~ConnectionPool();
};

