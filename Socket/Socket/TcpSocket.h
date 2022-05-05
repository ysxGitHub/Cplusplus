#pragma once
#include <string>
class TcpSocket
{
public:
	TcpSocket();
	TcpSocket(int socket);
	~TcpSocket();
	
	// int connectToHost(int fd, const char* ip, unsigned short port);
	int connectToHost(std::string ip, unsigned short port);

	// int sendMsg(int fd, const char* msg);
	int sendMsg(std::string msg);

	// int recvMsg(int fd, char* msg, int size);
	std::string recvMsg();

private:
	// int readn(int fd, char* buf, int size);
	int readn(char* buf, int size);

	// int writen(int fd, const char* msg, int size);
	int writen(const char* msg, int size);

private:
	int m_fd; //Í¨ÐÅÌ×½Ó×Ö
};

