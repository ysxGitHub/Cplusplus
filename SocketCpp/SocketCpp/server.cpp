#include <cstdio>
#include <cstring>
#include <cstdlib>
//#include <sys/socket.h>
#include <sys/unistd.h>
#include <sys/types.h>
#include <sys/errno.h>
//#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include "Logger.h"

#define BUFFSIZE 2048
#define DEFAULT_PORT 10001
#define MAXLINK 2048

int sockfd, connfd; // 定义服务端套接字和客户端套接字
Logger logger;

void stopServerRunning(int p) {
	close(sockfd);
	printf("Close Server\n");
	exit(0);
}


void setResponse(char* buff) {
    bzero(buff, sizeof(buff));
    strcat(buff, "HTTP/0.9 200 OK\r\n");
    strcat(buff, "Connection: close\r\n");
    strcat(buff, "\r\n");
    strcat(buff, "Hello World\n");
}

int main() {
    struct sockaddr_in servaddr;    // 用于存放服务器ip和端口的结构
    char buff[BUFFSIZE];    // 用于收发数据

    // 对应伪代码中的sockfd = socket();
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == sockfd) {
        printf("Create socket error(%d): %s\n", errno, strerror(errno));
        return -1;
    }
    // END
    
    // 对应伪代码中的bind(sockfd, ip::port和一些配置);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(DEFAULT_PORT);
    if (-1 == bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) {
        printf("Bind error(%d): %s\n", errno, strerror(errno));
        return -1;
    }
    // END
    
    // 对应伪代码中的listen(sockfd);    
    if (-1 == listen(sockfd, MAXLINK)) {
        printf("Listen error(%d): %s\n", errno, strerror(errno));
        return -1;
    }
    // END
    printf("Listening...\n");

    while (true) {
        signal(SIGINT, stopServerRunning);    // 这句用于在输入Ctrl+C的时候关闭服务器

        // 对应伪代码中的connfd = accept(sockfd);
        connfd = accept(sockfd, NULL, NULL);
        if (-1 == connfd) {
            printf("Accept error(%d): %s\n", errno, strerror(errno));
            close(sockfd); // 当connext出现错误时需要关闭套接字
            return -1;
        }
        // END

        bzero(buff, BUFFSIZE);

        // 对应伪代码中的recv(connfd, buff);
        recv(connfd, buff, BUFFSIZE - 1, 0);
        // END

        // printf("Recv: %s\n", buff);
        // 先写入缓存，缓存满了再写入文件
        logger.Log("Recv: ", 6);
        logger.Log(buff, strlen(buff));
        
        // 回复报文 
        setResponse(buff);
        // 对应伪代码中的send(connfd, buff);
        send(connfd, buff, strlen(buff), 0);
        // END

        // 对应伪代码中的close(connfd);
        close(connfd);
        // END
    }

	return 0;
}


