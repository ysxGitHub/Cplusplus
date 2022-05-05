#pragma once
#ifndef _SOCKET_H
#define _SOCKET_H
#include "threadpool.h"

///////////////////////////
///////////服务器///////////
///////////////////////////
// threadpool Info
typedef struct poolInfo {
    ThreadPool* pool;
    int lfd;
}PoolInfo;

//信息结构体
struct SockInfo {
    struct sockaddr_in addr;
    int cfd;
};

int setListen(int lfd, unsigned short port);
void acceptConn(void* arg);
void working(void* arg);
///////////////////////////
///////////客户端///////////
///////////////////////////
int connectToHost(int fd, const char* ip, unsigned short port);

///////////////////////////
///////////公用////////////
///////////////////////////
int createSocket();
int writen(int fd, const char* msg, int size);
int sendMsg(int cfd, const char* msg, int len);
int readn(int fd, char* buf, int size);
int recvMsg(int cfd, char** msg);
int closeSocket(int fd);

#endif // !_SOCKET_H
