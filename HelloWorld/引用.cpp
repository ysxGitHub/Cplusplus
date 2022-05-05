#include<iostream>
using namespace std;

// 引用传递
int& swap(int& a, int&b)
{
    int temp = a;
    a = b;
    b = temp;
    // 不要返回局部变量的引用
    static int d = 12;
    return d;
}

// 常数引用：用来修饰形参，防止误操作
void showvalue(const int &val)
{
    // val = 1000;
    cout<<val<<endl;
}

int main(int argc, char const *argv[])
{
    // 引用给变量起别名
    // 数据类型 &别名 = 原名

    int a = 10;

    int &b = a;

    // 引用必须要初始化
    // int &b;  //错误

    b = 20;

    int c = 5;
    // 引用一旦初始化后，就不可以更改
    // int &b = c;  //错误

    // b = c; //这是赋值，不是引用

    cout<<a<<" "<<b<<endl;

    //引用传递，形参会修饰实参 
    swap(b, c);
    cout<<b<<" "<<c<<endl;

    int &d = swap(b, c);
    cout<<d<<endl;
    // 如果函数的返回值是引用，这个函数调用可以作为左值
    swap(b, c) = 100;
    cout<<d<<endl;

    // 引用的本质是指针常量，指向的地址不可修改。

    int e = 20;
    showvalue(e);

    return 0;
}
