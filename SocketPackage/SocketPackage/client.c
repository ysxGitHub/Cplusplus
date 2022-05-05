#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include "socket.h"

int main()
{
    // 1. 创建通信的套接字
    int fd = createSocket();
    if (fd == -1) {
        exit(0);
    }

    // 2. 连接服务器

    int ret = connectToHost(fd, "192.168.39.128", 10000);
    if (ret == -1) {
        exit(0);
    }

    // 3. 和服务器端通信
    int fd1 = open("123.txt", O_RDONLY);
    long int length = 0;
    char tmp[1000];
    while ((length = read(fd1, tmp, rand()%1000))>0) {
        // 发送数据
        sendMsg(fd, tmp, length);
        // 清空tmp
        memset(tmp, 0, sizeof(tmp));
        usleep(300);   // 每隔300us发送一条数据
    }
    sleep(10);
    // 关闭文件描述符
    closeSocket(fd);

    return 0;
}
