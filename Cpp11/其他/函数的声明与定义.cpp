/*
1. pf是一个函数指针
int (*pf)(const int&, const int&);
2. 声明了一个函数pf
int *pf(const int&, const int&);

为什么有函数指针

函数与数据项相似，函数也有地址。我们希望在同一个函数中通过使用相同的形参在不同的时间使用产生不同的效果
*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    // cout是有缓冲输出
    cout << "abc " << endl;
    // flush立即强迫缓冲输出。
    cout << "abc\n "; cout <<flush;
    // printf是行缓冲输出，不是无缓冲输出。
    return 0;
}


