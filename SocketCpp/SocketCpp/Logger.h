#pragma once
#include <cstdio>
#define LOG_BUFFSIZE 65536
class Logger{
private:
	char buff[LOG_BUFFSIZE];
	int buffLen;
	FILE* fp;
public:
	Logger();
	void Flush();
	void Log(const char* str, long unsigned int len);
	~Logger();
};
