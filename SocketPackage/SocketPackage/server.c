#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include "pthread.h"
#include "socket.h"

int main()
{
    // 1. 创建通信的套接字
    int lfd = createSocket();
    if (lfd == -1) {
        exit(0);
    }
    // 2.绑定本地IP port + 设置监听
    int ret = setListen(lfd, 10000);
    if (ret == -1) {
        exit(0);
    }
    //创建线程池
    ThreadPool* pool = threadPoolCreate(3, 8, 100);
    PoolInfo* info = (PoolInfo*)malloc(sizeof(PoolInfo));
    info->pool = pool;
    info->lfd = lfd;
    threadPoolAdd(pool, acceptConn, info);
    // 主线程退出
    pthread_exit(NULL);
    return 0;
}
