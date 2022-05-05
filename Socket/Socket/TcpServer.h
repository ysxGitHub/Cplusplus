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
	int m_fd;  // �����׽��� 
	//int cfd;  // ͨ���׽���
   /*
		��������һ����Ҫ�Ͷ���ͻ��˽������ӣ����ͨ�ŵ��׽��־���Ҫ�� N ����
		�����������װ�������ֻ��һ����
		���������������Խ���������ͨ�Ź���ȥ����ֻ���¼���������������һ�����ܡ�
		���ͻ�������һ��ר�������׽���ͨ�ŵ��༴�ɡ�����������������ʹ�÷������� + ͨ����������
		�ͻ�����������ͨ��ͨ�ŵ���������
   */
};
