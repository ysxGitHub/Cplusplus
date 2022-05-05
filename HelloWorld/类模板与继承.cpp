#include<iostream>
using namespace std;
#include "person.hpp"
/*
类模板中的继承
    1.当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
    2.如果不指定，编译器无法给子类分配内存
    3.如果想要灵活指定出父类中T的类型，子类也需要变为类模板

类模板分文件编写的问题：
    类模板中成员函数创建时间在调用阶段，导致文件编写时链接不到
    解决方法：
        直接包含.cpp文件
        申明与实现都写在一个文件中， 将文件名改为.hpp

*/ 

template<class T>
class Base
{
public:
    T m;
};

// 指定父类T的类型 Base<int>
class Son: public Base<int>
{
public:
    void Sonprint()
    {
        cout<<"Son"<<endl;
    }

};

template<class T1, class T2>
class Daughter: public Base<T1>
{
public:
    T2 num;
    void Dauprint()
    {
        cout<<"Daughter"<<endl;
        cout<<"T1: "<<typeid(T1).name()<<"\t T2: "<<typeid(T2).name()<<endl;
    }
};



int main(int argc, char const *argv[])
{
    Son s1;
    s1.Sonprint();

    Daughter<char, int>d1;
    d1.Dauprint();

    // 分文件编译
    Person<string, int> p1("lisi", 25);
    p1.PersonPrint();
    
    // 友元函数
    PrintP(p1);
    PrintP1(p1);

    return 0;
}
