#include <iostream>
using namespace std;

// 空类占 1个字节
class A {};

// 32为主机的 带虚函数的类占 4个字节
class B {
    virtual void test();
    virtual void test1();
};

// 32为主机的 继承带虚函数的类占 4个字节
class C :public B {

};

// 4 个字节
class D :public B {
    virtual void test2();
};

// 内存对齐 12个字节, 是将整个类内存对齐
// 对于内存对齐，主要是为了提高程序的性能，数据结构，特别是栈，应尽可能在自然边界上对齐，经过对齐后，cpu的内存访问速度大大提升。
class E {
public:

    virtual void test();
    virtual void test1();
private:
    // bool bChild; // 顺序有关 现在 16 字节
    int age;
    bool sex;
    bool bChild;
};

int main1(int argc, char const* argv[])
{
     cout<<sizeof(A)<<endl;
     cout<<sizeof(B)<<endl;
     cout<<sizeof(C)<<endl;
     cout<<sizeof(D)<<endl;
     cout<<sizeof(E)<<endl;
     return 0;
}