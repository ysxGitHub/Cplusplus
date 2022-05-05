#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include "socket.h"

// 绑定本地的IP和端口 + 设置监听
int setListen(int lfd, unsigned short port)
{
    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(port);
    saddr.sin_addr.s_addr = INADDR_ANY; //0 = 0.0.0.0
    int ret = bind(lfd, (struct sockaddr*)&saddr, sizeof(saddr));
    if (ret == -1) {
        perror("bind");
        return -1;
    }
    printf("Socket bind success!\n");
    ret = listen(lfd, 128);
    if (ret == -1) {
        perror("listen");
        return -1;
    }
    printf("Set up listen success!\n");
    return ret;
}

//// 阻塞并等待客户端的连接
//int acceptConn(int lfd, struct sockaddr_in* addr)
//{
//    int cfd = -1;
//    if (addr == NULL) {
//        cfd = accept(lfd, NULL, NULL);
//    }
//    else {
//        int addrlen = sizeof(struct sockaddr_in);
//        cfd = accept(lfd, (struct sockaddr*)addr, &addrlen);
//    }
//    if (cfd == -1) {
//        perror("accept");
//        return -1;
//    }
//    printf("成功和客户端建立连接...\n");
//    return cfd;
//}
void acceptConn(void* arg) {
    PoolInfo* info = (PoolInfo*)arg;

    // 4. 阻塞等待并接受客户端连接
    int addrlen = sizeof(struct sockaddr_in);
    while (1) {

        struct SockInfo* pinfo;
        pinfo = (struct SockInfo*)malloc(sizeof(struct SockInfo));

        int cfd = accept(info->lfd, (struct sockaddr*)&pinfo->addr, &addrlen);
        pinfo->cfd = cfd;

        if (cfd == -1) {
            perror("accept");
            break;
        }

        // 添加通信的任务
        threadPoolAdd(info->pool, working, pinfo);
    }
    close(info->lfd);
}


//连接服务器
int connectToHost(int fd, const char* ip, unsigned short port)
{
    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &saddr.sin_addr.s_addr);
    int ret = connect(fd, (struct sockaddr*)&saddr, sizeof(saddr));
    if (ret == -1) {
        perror("connect");
        return -1;
    }
    printf("Successfully established connection to the server...\n");
    return ret;
}

// 创建套接字
int createSocket()
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
        perror("socket");
        return -1;
    }
    printf("Socket set up success, fd=%d\n", fd);
    return fd;
}

// 发送指定长度的字符串
int writen(int fd, const char* msg, int size) {
    const char* buf = msg;
    int count = size;
    while (count > 0) {
        int len = send(fd, buf, count, 0);
        if (len == -1) {
            return -1;
        }
        else if (len == 0) {
            continue;
        }
        buf += len;
        count -= len;
    }
    return size;
}
// 发送数据
int sendMsg(int cfd, const char* msg, int len)
{
    if (cfd < 0 || msg == NULL || len <= 0) {
        return -1;
    }
    char* data = (char*)malloc(len + 4);
    int biglen = htonl(len);
    memcpy(data, &biglen, 4);
    memcpy(data + 4, msg, len);
    //发送数据
    int ret = writen(cfd, data, len + 4);
    //int ret = send(cfd, msg, len, 0);
    if (ret == -1) {
        close(cfd);
    }
    return ret;
}

//接收指定字节个数的字符串
int readn(int fd, char*buf, int size) {
    char* pt = buf;
    int count = size;
    while (count > 0) {
        int len = recv(fd, pt, count, 0);
        if (len == -1) {
            return -1;
        }
        else if (len == 0) {
            printf("The other party has disconnected...\n");
            return size - count;
        }
        pt += len;
        count -= len;
    }
    return size;
}
//接收数据
int recvMsg(int cfd, char** msg)
{
    int len = 0;
    readn(cfd, (char*)&len, 4);
    len = ntohl(len);
    printf("Need receive data len: %d\n", len);
    
    char* data = (char*)malloc(len + 1);
    int length = readn(cfd, data, len);
    //int len = recv(cfd, msg, size, 0);
    if (length != len) {
        printf("Receive data failure!\n");
        close(cfd);
        free(data);
        return -1;
    }
    data[len] = '\0';
    *msg = data;
    return length;
}

// 关闭套接字
int closeSocket(int fd)
{
    int ret = close(fd);
    if (ret == -1) {
        perror("close");
    }
    return ret;
}

// 服务器子线程读取数据
void working(void* arg) {
    struct SockInfo* pinfo = (struct SockInfo*)arg;

    // 打印客户端的地址信息
    char ip[24] = { 0 };
    printf("client IP addr: %s, port: %d\n",
        inet_ntop(AF_INET, &pinfo->addr.sin_addr.s_addr, ip, sizeof(ip)),
        ntohs(pinfo->addr.sin_port));

    // 5. 和客户端通信
    while (1)
    {
        // 接收数据
        char* buf;
        int len = recvMsg(pinfo->cfd, &buf);
        printf("Receive data, %d: ...\n", len);
        if (len > 0) {
            printf("%s\n\n", buf);
            free(buf);
            // write(pinfo->cfd, buf, len);
        }
        else {
            break;
        }
        sleep(1);
    }
    close(pinfo->cfd);
}