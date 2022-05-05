
/*
final 关键字来限制某个类不能被继承，或者某个虚函数不能被重写。
    如果使用 final 修饰函数，只能修饰虚函数，并且要把final关键字放到类或者函数的后面。

普通函数不能使用，基类函数也最好不要使用
*/

// 使用 final 修饰函数，只能修饰虚函数，这样就能阻止子类重写父类的这个函数了：
#include<iostream>
using namespace std;

class Base{
public:
    virtual void test(){
        cout << "Base class...";
    }
};

class Child : public Base{
public:
    void test() final // 加在函数后面
    {
        cout << "Child class...";
    }
};

class GrandChild : public Child{
public:
    // 语法错误, 不允许重写
    void test(){
        cout << "GrandChild class...";
    }
};


// 使用 final 关键字修饰过的类是不允许被继承的，也就是说这个类不能有派生类。
class Base1{
public:
    virtual void test(){
        cout << "Base1 class...";
    }
};

class Child1 final: public Base1 // 加在类名后面
{
public:
    void test(){
        cout << "Child1 class...";
    }
};

// error, 语法错误
class GrandChild1 : public Child1
{
public:

};
