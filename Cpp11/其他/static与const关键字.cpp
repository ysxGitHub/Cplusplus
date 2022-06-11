#include <iostream>
using namespace std;
/*
静态成员变量
    所有对象共享同一份数据
    在编译阶段分配内存
    类内声明，类外初始化

静态成员函数
    所有对象共享同一函数
    静态成员函数只能访问静态成员变量
静态成员函数不能访问非静态成员变量，无法区分这个变量是哪个对象的


静态变量什么时候初始化
1. 在C中，初始化发生在代码执行之前，编译阶段分配好内存之后，就会进行初始化，所以我们看到在C语言中无法使用变量对静态局部变量进行初始化
2. 在C++中，初始化时在执行相关代码时才会进行初始化，是可以使用变量对静态局部变量进行初始化的。
*/

class A{
public:
    int a = 10;
    static int b;
    static void printb(){
        // cout<<a<<endl;
        cout<<b<<endl;
    }
    // const常量在定义时必须初始化，之后无法更改
    // const形参可以接收const和非const类型的实参
    const int c = 30;
    void printc() const{
        cout<<a<<endl;
        cout<<b<<endl;
        cout<<c<<endl;
    }

    // const对象不可以调用非const成员函数；
    void printa(){
        cout<<a<<endl;
    }

    mutable int d=10;
    void addd() const{
        // const对象, 用 mutable 关键字声明的变量可以在const成员函数中被修改
        cout<<++d<<endl;
        // cout<<++a<<endl; // const对象, 不可以改变非mutable数据的值
    }
};
int A::b = 20;


// C++的顶层const和底层const
void test(){
    int a = 10;
    int* const b1 = &a;        //顶层const，b1本身是一个常量
    int b = 20;
    // b1 = &b; // error 指针常量
    *b1 = b;

    const int* b2 = &a;       //底层const，b2本身可变，所指的对象是常量
    // *b2 = b; // error 常量指针
    b2 = &b;

    const int b3 = 20; 		   //顶层const，b3是常量不可变
    const int* const b4 = &a;  //前一个const为底层，后一个为顶层，b4不可变
    const int& b5 = a;		   //用于声明引用变量，都是底层const
}


int main(int argc, char const *argv[])
{
    A a;
    a.printa();
    a.printb();
    a.printc();

    const A a2;
    // a2.printa(); // const对象不可以调用非const成员函数；
    a2.printb();
    a2.printc();
    a2.addd();

    test();

    return 0;
}
