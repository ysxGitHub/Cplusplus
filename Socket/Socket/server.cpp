#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <arpa/inet.h>
#include <pthread.h>
// #include "ThreadPool.h"
#include "TcpSocket.h"
#include "TcpServer.h"

struct SockInfo {
	TcpServer* s;
	TcpSocket* tcp;
	struct sockaddr_in addr;
};

void* working(void* arg) {
	struct SockInfo* pinfo = static_cast<struct SockInfo*>(arg);
	//连接建立成功，打印客户端的IP和Port信息
	char ip[32];
	std::cout << "客户端IP: "
		<< inet_ntop(AF_INET, &pinfo->addr.sin_addr, ip, sizeof(ip))
		<< ", 端口: " << ntohs(pinfo->addr.sin_family) << std::endl;
	// 5.通信
	while (1) {
		std::cout << "接收数据: ......" << std::endl;
		std::string msg = pinfo->tcp->recvMsg();
		if (!msg.empty()) {
			std::cout << msg << std::endl << std::endl << std::endl;
		}
		else {
			break;
		}
	}
	delete pinfo->tcp;
	delete pinfo;
	return nullptr;
}

int main() {
	// 1. 创建监听的套接字
	TcpServer s;
	// 2. 绑定本地IP port 并设置监听
	s.setListen(10001);
	//3.阻塞并等待客户端的连接
	while (1) {
		SockInfo* info = new SockInfo;
		TcpSocket* tcp = s.acceptConn(&info->addr);
		if (tcp == nullptr) {
			std::cout << "重试....." << std::endl;
			continue;
		}
		info->s = &s;
		info->tcp = tcp;
		// 创建子线程
		pthread_t tid;
		pthread_create(&tid, NULL, working, info);
		pthread_detach(tid);
	}
	return 0;
}

