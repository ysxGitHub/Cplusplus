/*
override 关键字确保在派生类中声明的重写函数与基类的虚函数有相同的签名，
    同时也明确表明将会重写基类的虚函数，这样就可以保证重写的虚函数的正确性，也提高了代码的可读性，
    和 final 一样这个关键字要写到方法的后面。
*/

/*
多态产生的条件：
    1.有继承关系
    2.子类重写父类虚函数
    3.父类指针或引用指向子类对象
*/


#include<iostream>
using namespace std;

class Base{
public:
    virtual void test(){
        cout << "Base class...";
    }
};

class Child : public Base
{
public:
    void test() override
    {
        cout << "Child class...";
    }
};

class GrandChild : public Child
{
public:
    void test() override
    {
        cout << "Child class...";
    }
};

/*
上述代码中第  行和第  行就是显示指定了要重写父类的 test() 方法，使用了 override 关键字之后，
    假设在重写过程中因为误操作，写错了函数名或者函数参数或者返回值编译器都会提示语法错误，
    提高了程序的正确性，降低了出错的概率。
*/
