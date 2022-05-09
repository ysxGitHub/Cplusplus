#include <cstring>
#include "Logger.h"

Logger::Logger()
{
	bzero(buff, sizeof(buff));
	buffLen = 0;
	// ��/���� Server.log �ļ�
	fp = fopen("Server.log", "a");
}

void Logger::Flush()
{
	// ���ַ���д���ļ�
	fputs(buff, fp);
	bzero(buff, sizeof(buff));
	buffLen = 0;
}

void Logger::Log(const char* str, long unsigned int len)
{
	// ����������, д���ļ�
	if (buffLen + len > LOG_BUFFSIZE - 10) {
		Flush();
	}
	// ���õ�������д�뻺��
	for (long unsigned int i = 0; i < len; ++i) {
		buff[buffLen] = str[i];
		++buffLen;
	}
}

Logger::~Logger()
{
	// ��������л�������
	if (buffLen != 0) {
		Flush();
	}
	// �ر��ļ�
	fclose(fp);
}
