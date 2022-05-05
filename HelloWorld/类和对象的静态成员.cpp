#include<iostream>
using namespace std;



class Person
{
public:
    /*
    静态成员变量
        所有对象共享同一份数据
        在编译阶段分配内存
        类内声明，类外初始化

    */
    static int m_A;
    /*
    静态成员函数
        所有对象共享同一函数
        静态成员函数只能访问静态成员变量

    */
   static void func()
   {
       // 静态成员函数不能访问非静态成员变量，无法区分这个变量是哪个对象的
       // m_C = 300;
       cout<<"Static member functions"<<endl;
   }

    int m_C;

private:
    // 静态成员变量也是有访问权限的
    static int m_B;
    // 静态成员函数也是有访问权限的
    static void func2()
    {
        cout<<"Static member functions"<<endl;
    }

};

int Person::m_A = 100;
// int Person::m_B = 100;

int main(int argc, char const *argv[])
{
    Person p1;

    cout<<"m_A = "<<p1.m_A<<endl;

    // 1.静态成员变量通过对象访问
    Person p2;

    p2.m_A = 200;

    cout<<"m_A = "<<p1.m_A<<endl;

    // 2.静态成员变量通过类名进行访问
    cout<<"m_A = "<<Person::m_A<<endl;

    // 1.静态成员函数通过对象访问
    p1.func();

    // 2.静态成员变量通过类名进行访问
    Person::func();

    return 0;
}
