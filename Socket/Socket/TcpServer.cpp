#include <unistd.h>
#include <string.h>
#include <iostream>
#include <arpa/inet.h>
#include "TcpServer.h"

TcpServer::TcpServer()
{
	m_fd = socket(AF_INET, SOCK_STREAM, 0); // 创建监听套接字
}

TcpServer::~TcpServer()
{
	close(m_fd); // 监听套接字
}

int TcpServer::setListen(unsigned short port)
{
	struct sockaddr_in saddr;
	saddr.sin_family = AF_INET; // 地址协议簇
	saddr.sin_port = htons(port); // 主机字节序转网络字节序
	saddr.sin_addr.s_addr = INADDR_ANY; // 0 = 0.0.0.0
	int ret = bind(m_fd, (struct sockaddr*)&saddr, sizeof(saddr)); // 绑定
	if (ret == -1) {
		perror("bind");
		return -1;
	}
	std::cout << "套接字绑定成功, ip: "
		<< inet_ntoa(saddr.sin_addr)
		<< ", port: " << port << std::endl;
	
	ret = listen(m_fd, 128); // 监听，同时可以处理128
	if (ret == -1) {
		perror("listen");
		return -1;
	}
	std::cout << "设置监听成功..." << std::endl;
	return ret;
}

TcpSocket* TcpServer::acceptConn(struct sockaddr_in* addr)
{
	if (addr == nullptr) {
		return nullptr;
	}
	socklen_t addrlen = sizeof(struct sockaddr_in);
	// 阻塞等待并接受客户端连接
	int cfd = accept(m_fd, (struct sockaddr*)addr, &addrlen);
	if (cfd == -1) {
		perror("accept");
		return nullptr;
	}
	std::cout << "成功和客户端建立连接..." << std::endl;
	return new TcpSocket(cfd);
}
