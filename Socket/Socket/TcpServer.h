#pragma once
#include <string>
#include "TcpSocket.h"
class TcpServer
{
public:
	TcpServer();
	~TcpServer();

	// int bindSocket(int lfd, unsigned short port) + int setListen(int lfd)
	int setListen(unsigned short port);

	// int acceptConn(int lfd, struct sockaddr_in *addr);
	TcpSocket* acceptConn(struct sockaddr_in* addr = nullptr);

private:
	int m_fd;  // 监听套接字 
	//int cfd;  // 通信套接字
   /*
		服务器端一般需要和多个客户端建立连接，因此通信的套接字就需要有 N 个，
		但是在上面封装的类里边只有一个。
		答：瘦身、减负。可以将服务器的通信功能去掉，只留下监听并建立新连接一个功能。
		将客户端类变成一个专门用于套接字通信的类即可。服务器端整个流程使用服务器类 + 通信类来处理；
		客户端整个流程通过通信的类来处理。
   */
};
