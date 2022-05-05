#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include "socket.h"

int main()
{
    // 1. ����ͨ�ŵ��׽���
    int fd = createSocket();
    if (fd == -1) {
        exit(0);
    }

    // 2. ���ӷ�����

    int ret = connectToHost(fd, "192.168.39.128", 10000);
    if (ret == -1) {
        exit(0);
    }

    // 3. �ͷ�������ͨ��
    int fd1 = open("123.txt", O_RDONLY);
    long int length = 0;
    char tmp[1000];
    while ((length = read(fd1, tmp, rand()%1000))>0) {
        // ��������
        sendMsg(fd, tmp, length);
        // ���tmp
        memset(tmp, 0, sizeof(tmp));
        usleep(300);   // ÿ��300us����һ������
    }
    sleep(10);
    // �ر��ļ�������
    closeSocket(fd);

    return 0;
}
