/*
2.1 初始化类的非静态成员
在进行类成员变量初始化的时候，C++11 标准对于 C++98 做了补充，
    允许在定义类的时候在类内部直接对非静态成员变量进行初始化，
    在初始化的时候可以使用等号 = 也可以 使用花括号 {} 。
*/
#include<iostream>
using namespace std;


class Test {
private:
    int a = 9;
    int b = {5};
    int c{12};
    double array[4] = { 3.14, 3.15, 3.16, 3.17};
    double array1[4] { 3.14, 3.15, 3.16, 3.17 };
    string s1("hello");     // error
    string s2{ "hello, world" };
};


/*
2.2 类内部赋值和初始化列表
在 C++11 之前对于非静态的类成员变量我们除了在构造函数内部进行赋值，
    也可以在类的初始化列表中进行初始化（这种方式比在构造函数内部赋值效率高）。
*/

class Init {
public:
    // 使用初始化列表对类的非静态成员进行初始化
    Init(int x, int y, int z) :a(x), b(y), c(z) {}

    int a = 1;
    int b = 2;
    int c = 3;
};

int main()
{
    Init tmp(10, 20, 30);
    cout << "a: " << tmp.a << ", b: " << tmp.b << ", c: " << tmp.c << endl;
    return 0;
}
