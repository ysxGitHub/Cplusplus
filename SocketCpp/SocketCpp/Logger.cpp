#include <cstring>
#include "Logger.h"

Logger::Logger()
{
	bzero(buff, sizeof(buff));
	buffLen = 0;
	// 打开/创建 Server.log 文件
	fp = fopen("Server.log", "a");
}

void Logger::Flush()
{
	// 把字符串写入文件
	fputs(buff, fp);
	bzero(buff, sizeof(buff));
	buffLen = 0;
}

void Logger::Log(const char* str, long unsigned int len)
{
	// 缓存中已满, 写入文件
	if (buffLen + len > LOG_BUFFSIZE - 10) {
		Flush();
	}
	// 将得到的数据写入缓存
	for (long unsigned int i = 0; i < len; ++i) {
		buff[buffLen] = str[i];
		++buffLen;
	}
}

Logger::~Logger()
{
	// 如果缓存中还有数据
	if (buffLen != 0) {
		Flush();
	}
	// 关闭文件
	fclose(fp);
}
