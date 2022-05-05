#include <iostream>
#include <string>
using namespace std;

class Base {
public:
    Base(int i) :m_i(i) {}
    Base(int i, double j) :m_i(i), m_j(j) {}
    Base(int i, double j, string k) :m_i(i), m_j(j), m_k(k) {}

    int m_i;
    double m_j;
    string m_k;
};

class Child : public Base {
public:
    Child(int i) :Base(i) {}
    Child(int i, double j) :Base(i, j) {}
    Child(int i, double j, string k) :Base(i, j, k) {}
};



class Base1
{
public:
    Base1(int i) :m_i(i) {}
    Base1(int i, double j) :m_i(i), m_j(j) {}
    Base1(int i, double j, string k) :m_i(i), m_j(j), m_k(k) {}

    int m_i;
    double m_j;
    string m_k;
};

class Child : public Base1
{
public:
    /*
    在修改之后的子类中，没有添加任何构造函数，而是添加了 using Base::Base;
        这样就可以在子类中直接继承父类的所有的构造函数，通过他们去构造子类对象了。
    */
    using Base1::Base1;
};



class Base2 {
public:
    Base2(int i) :m_i(i) {}
    Base2(int i, double j) :m_i(i), m_j(j) {}
    Base2(int i, double j, string k) :m_i(i), m_j(j), m_k(k) {}

    void func(int i){
        cout << "base class: i = " << i << endl;
    }

    void func(int i, string str){
        cout << "base class: i = " << i << ", str = " << str << endl;
    }

    int m_i;
    double m_j;
    string m_k;
};

class Child : public Base2 {
public:
    /*
    子类中的 func() 函数隐藏了基类中的两个 func() 因此默认情况下通过子类对象只能调用无参的 func()，
        在上面的子类代码中添加了 using Base::func; 之后，
        就可以通过子类对象直接调用父类中被隐藏的带参 func() 函数了。
    */
    using Base2::Base2;
    using Base2::func;
    void func(){
        cout << "child class: i'am luffy!!!" << endl;
    }
};


int main()
{
    Child c(250);
    c.func();
    c.func(19);
    c.func(19, "luffy");
    return 0;
}