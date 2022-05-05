/*
1. 断言
断言（assertion）是一种编程中常用的手段。在通常情况下，
    断言就是将一个返回值总是需要为真的判断表达式放在语句中，
    用于排除在设计的逻辑上不应该产生的情况。

比如：一个函数总需要输入在一定的范围内的参数，那么程序员就可以对该参数使用断言，
    以迫使在该参数发生异常的时候程序退出，从而避免程序陷入逻辑的混乱
*/
#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

// 创建一个指定大小的 char 类型数组
char* createArray(int size){

    // 通过断言判断数组大小是否大于0
    assert(size > 0);	// 必须大于0, 否则程序中断
    char* array = new char[size];
    return array;
}


int main1()
{
    char* buf = createArray(0);
    // 此处使用的是vs提供的安全函数, 也可以使用 strcpy
    strcpy(buf, "hello, world!");
    cout << "buf = " << buf << endl;
    delete[]buf;

    // 静态断言：表达式必须是常量表达式
    static_assert(sizeof(long) == 8, "error, not 64-bits...");
    cout << "64bit Windows ptr_size: " << sizeof(char*) << endl;
    cout << "64bit Windows long size: " << sizeof(long) <<endl;

    return 0;
}

/*
assert 是一个运行时断言，也就是说它只有在程序运行时才能起作用 。
    这意味着不运行程序我们将无法得知某些条件是否是成立的。

静态断言 static_assert，所谓静态就是在编译时就能够进行检查的断言，使用时不需要引用头文件。
    静态断言的另一个好处是，可以自定义违反断言时的错误提示信息。
    静态断言使用起来非常简单，它接收两个参数：

    参数1：断言表达式，这个表达式通常需要返回一个 bool值
    参数2：警告信息，它通常就是一段字符串，在违反断言（表达式为false）时提示该信息

由于静态断言的表达式是在编译阶段进行检测，所以在它的表达式中不能出现变量，
    也就是说这个表达式必须是常量表达式。
*/




