#include <iostream>
using namespace std;

// 例子来源于: 菜鸟教程
class A
{
public:
    virtual void foo()
    {
        cout<<"A::foo() is called"<<endl;
    }
    virtual ~A(){
        cout<<"A::~A is called"<<endl;
    }
};

class B:public A
{
public:
    void foo() override
    {
        cout<<"B::foo() is called"<<endl;
    }
    ~B(){
        cout<<"B::~B is called"<<endl;
    }
};


// class Base1 {
// public:
//     virtual void v1() { cout << "Base2 virtual function v1()" << endl;}
//     virtual void v2() { cout << "Base2 virtual function v2()" << endl;}
//     virtual void v3() { cout << "Base2 virtual function v3()" << endl;}
// };

// class Base2 {
// public:
//     virtual void v1() { cout << "Base2 virtual function v1()" << endl;}
//     virtual void v2() { cout << "Base2 virtual function v2()" << endl;}
//     virtual void v3() { cout << "Base2 virtual function v3()" << endl;}
// };

// class Divide0: Base1, Base2 {
// public:
//     virtual void v1(){ cout << "Divide0 virtual function v1()" << endl;}
//     virtual void v4(){ cout << "Divide0 virtual function v4()" << endl;}
// };


// 虚拟继承（菱形继承）
class Base {
    int a;
    int b;
public:
    virtual void run();
};

class Divide1 :virtual public Base {
public:
    virtual void run();
private:
    int c;
};

class Divide2 :virtual public Base {
public:
    virtual void run();
private:
    int d;
};

class Divide :public Divide1, Divide2 {
public:
    virtual void run();
private:
    int d;
};

// cl/d1 reportSingleClassLayoutDivide 虚函数.cpp
int main(void)
{
    // A *a = new B();
    // a->foo();   // 在这里，a虽然是指向A的指针，但是被调用的函数(foo)却是B的!
    // delete a;   // 在这里，virtual ~A(), 调用 A与B 的析构函数，

    Divide d;
    return 0;
}

