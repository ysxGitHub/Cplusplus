#include <unistd.h>
#include <string.h>
#include <iostream>
#include <arpa/inet.h>
#include "TcpSocket.h"

// 其中无参构造一般在客户端使用，通过这个套接字对象再和服务器进行连接，之后就可以通信了
TcpSocket::TcpSocket() 
{
	m_fd = socket(AF_INET, SOCK_STREAM, 0); //创建通信套接字
}

// 有参构造主要在服务器端使用，当服务器端得到了一个用于通信的套接字对象之后，
// 就可以基于这个套接字直接通信，因此不需要再次进行连接操作。
TcpSocket::TcpSocket(int socket) 
{
	m_fd = socket;
}

TcpSocket::~TcpSocket()
{
	if (m_fd > 0) {
		close(m_fd); //关闭通信套接字
	}
}

int TcpSocket::connectToHost(std::string ip, unsigned short port)
{
	// 连接服务器IP port
	struct sockaddr_in saddr;
	saddr.sin_family = AF_INET; // 地址协议簇
	saddr.sin_port = htons(port); // 主机字节序转网络字节序
	inet_pton(AF_INET, ip.data(), &saddr.sin_addr.s_addr);  //IP地址转换
	int ret = connect(m_fd, (struct sockaddr*)&saddr, sizeof(saddr)); // 连接服务器
	if (ret == -1) {
		perror("connect");
		return -1;
	}
	std::cout << "成功与服务器建立连接..." << std::endl;
	return ret;
}

int TcpSocket::sendMsg(std::string msg)
{
	// 申请内存空间: 数据长度+包头4字节(存储数据长度)
	char* data = new char[msg.size() + 4];
	int bigLen = htonl(msg.size()); // 主机序转网络序
	memcpy(data, &bigLen, 4);
	memcpy(data + 4, msg.data(), msg.size());
	// 发送数据 防止粘包的写法
	int  ret = writen(data, msg.size() + 4);
	delete[] data;
	return ret;
}

std::string TcpSocket::recvMsg()
{
	// 接收数据  防止粘包的写法
	//1.读取数据头
	int len = 0;
	readn((char*)&len, 4);
	len = ntohl(len); // 网络字节序转主机字节序
	std::cout << "数据块大小: " << len << std::endl;

	//根据读出的长度分配内存
	char* buf = new char[len + 1];
	int ret = readn(buf, len);
	if (ret != len) {
		return std::string();
	}
	buf[len] = '\0'; // 以'\0'结尾
	std::string retStr(buf);
	delete[] buf;
	return retStr;
}

int TcpSocket::readn(char* buf, int size)
{
	int nread = 0;
	int left = size;
	char* p = buf;
	while (left > 0) { // 循环读取数据，直到 size 个字节
		if ((nread = read(m_fd, p, left)) > 0) {
			p += nread;
			left -= nread;
		}
		else if (nread == -1) {
			return -1;
		}
	}
	return size;
}

int TcpSocket::writen(const char* msg, int size)
{
	int left = size;
	int nwrite = 0;
	const char* p = msg;
	while (left > 0) { // 循环写入数据直到 size 字节
		if ((nwrite = write(m_fd, msg, left)) > 0) {
			p += nwrite;
			left -= nwrite;
		}
		else if (nwrite == -1) {
			return -1;
		}
	}
	return size;
}
