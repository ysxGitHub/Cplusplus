#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include "TcpSocket.h"

int main() {
	// 1.创建通信套接字
	TcpSocket tcp;

	// 2.连接服务器IP port
	int ret = tcp.connectToHost("192.168.39.128", 10001);
	if (ret == -1) {
		return -1;
	}

	// 3.通信
	int fd1 = open("123.txt", O_RDONLY);
	int length = 0;
	char tmp[100];
	bzero(tmp, sizeof(tmp));
	while ((length = read(fd1, tmp, sizeof(tmp))) > 0) {
		// 发送数据
		tcp.sendMsg(std::string(tmp, length));
		std::cout << "send Msg: " << std::endl;
		std::cout << tmp << std::endl << std::endl << std::endl;
		bzero(tmp, sizeof(tmp));

		//接收数据 (省略)
		usleep(300);
	}
	sleep(10);
	return 0;
}
