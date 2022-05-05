#include <iostream>

using namespace std;

/*
内存分区模型
c++程序在执行时，将内存大方向划分为4个区域
    代码区：存放函数体的二进制代码，由操作系统进行管理的
    全局区：存放全局变量和静态变量以及常量
    栈区：由编译器自动分配释放，存放函数的参数值，局部变量等
    堆区：由程序员分配和释放，若程序员不释放，程序结束时由操作系统回收
内存四区的意义：
    不同区域存放的数据，赋予不同的生命周期，给我们更大的灵活编程。
*/

/*
1.1 程序运行前
    程序编译后，生产了exe可执行程序，未执行该程序前分为两个区域
    代码区：
        存放CPU执行的机器指令
        代码区是共享的，共享的目的是对于频繁被执行的程序，只需要在内存中有一份代码即可
        代码区是只读的，使其只读的原因是防止程序意外地修改了它的指令
    全局区：
        全局变量和静态变量存放在此。
        全局区还包含了常量区，字符串常量和其他常量也存放在此。
        该区域的数据在程序结束后由操作系统释放。
    栈区(stack)：
        局部变量，形参数据以及函数返回地址存放在此
        ps：不要返回局部变量地址。
    堆区(heap)：
        程序运行时的动态内存分配
*/

int global_a = 10;
int global_b = 20;

const int global_const_a = 10;
const int global_const_b = 20;

int *func()
{
    // 利用new关键字，可以将数据开辟到堆区， 返回该数据类型的指针。
    int *p = new int(10);
    return p;
}

int *funclist()
{
    // 利用new个数组
    int *arr = new int[10];
    for(int i=0; i<10; i++)
    {
        arr[i] = i;
    }

    return arr;
}

int main(int argc, char const *argv[])
{
    int local_a = 10;
    int local_b = 20;

    cout << "局部变量a地址: " << (long long)&local_a << endl;
    cout << "局部变量b地址: " << (long long)&local_b << endl;

    cout << "全局变量a地址: " << (long long)&global_a << endl;
    cout << "全局变量b地址: " << (long long)&global_b << endl;

    static int static_a = 10;
    static int static_b = 20;

    cout << "静态变量a地址: " << (long long)&static_a << endl;
    cout << "静态变量b地址: " << (long long)&static_b << endl;

    const int local_const_a = 10;
    const int local_const_b = 20;

    cout << "局部常量a地址: " << (long long)&local_const_a << endl;
    cout << "局部常量b地址: " << (long long)&local_const_b << endl;

    cout << "全局常量a地址: " << (long long)&global_const_a << endl;
    cout << "全局常量b地址: " << (long long)&global_const_b << endl;

    string s = "123456";

    cout << "字符串变量s地址: " << (long long)&s << endl;
    cout << "字符串常量s地址: " << (long long)&"123456" << endl;

    int *p = func();
    cout << "new 开辟的地址在堆区: " << *p << endl;
    // 堆区的数据由程序员管理开辟和释放。利用关键字delete进行释放。
    delete p;

    int*arr = funclist();
    for (int i=0;i<10;i++)
    {
        cout<<arr[i]<<" ";
    }
    //释放数组时delete加[] 
    delete[] arr;

    return 0;
}
