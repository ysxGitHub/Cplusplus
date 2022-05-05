#获取.cpp文件
SrcFiles=$(wildcard *.cpp)
#使用替换函数获取.o文件
ObjFiles=$(patsubst %.cpp,%.o,$(SrcFiles))
# CC=gcc
CC=g++
#-I,添加包含路径，此处是头文件，-Wall 使gcc产生尽可能多的警告信息
CFLAGS= -Wall
# CFLAGS=-I ./include -Wall
#生成的可执行文件
Target=main
all:$(Target)
#目标文件依赖于.o文件
$(Target):$(ObjFiles)
	$(CC) -o $@ $^ $(CFLAGS)
#.o文件依赖于.cpp文件，通配使用，一条就够
%.o:%.cpp
	$(CC) -c $< -o $@ $(CFLAGS)
.PHONY:clean all

#由于win10没有rm命令,可以使用del, 参数百度
clean:
	del *.exe /q /s
	del *.o /q /s