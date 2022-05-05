#include<iostream>
#include<string>
using namespace std;

class Student
{
public:
    Student(string s):stu_name(s)
    {
        cout<<"student name = "<<stu_name<<endl;
    }
    ~Student()
    {
        cout<<"student end"<<endl;
    }

// private:
    string stu_name;
};

class Teacher
{
public:
    Teacher(string name, string sname):tea_name(name), stu1(sname)
    {
        cout<<"teacher name = "<<tea_name<<endl;
    }
    ~Teacher()
    {
        cout<<"teacher end"<<endl;
    }
    string tea_name;
    // 当其他类对象作为本类成员，构造时先构造类对象，再构造自身，析构的顺序刚好相反。
    Student stu1;

};


class Person
{

public:

    Person(int age)
    {
        // this的作用1：解决名称冲突，this指针指向 被调用的成员函数 所属的对象
        this->age = age;
    }

    int age;

    Person& personaddage(Person & p)
    {

        this->age += p.age;

        // this 指向p2的指针常量，而*this指向的就是p2这个对象本体, 指针的指向不可以修改
        // this = NULL;  // 错误

        // this的作用2：返回对象本体
        return *this;
    }


};


// 成员变量 和 成员函数 分开存储的
class Person0
{
// public:

};

class Person1
{
// public:
    //  非静态成员变量 属于类的对象上
    int a;
    // 静态成员变量 不属于类对象上
    static int b;
    // 非静态成员函数 不属于类对象上
    void func1(){};
    // 静态成员函数 不属于类对象上
    static void func2(){};

};
int Person1::b = 100;



class Person2
{

public:

    void PrintName()
    {
        cout<<"Person1 class name!"<<endl;
    }

    void PrintAge()
    {
        cout<<"age: "<<age<<endl;
    }

    int age;


};


class Animal
{
public:

    void showName() const  // 相当于const Animal * const this
    {
        // 成员函数后面加const，修饰的是this指针，让指针指向的值也不可以修改
        // this->m_a = 10;  // 错误
        this->m_b = 20;
        cout<<"Animal"<<endl;
    }

    void func(){};


    int m_a=1;
    mutable int m_b=2; //特殊变量，即使在常函数中，也可以修改这个值
};


int main(int argc, char const *argv[])
{

    // 类对象作为类成员
    Teacher t1("lisi","wangwu");


    Person0 p0;
    // p1空对象占用内存为：1字节
    cout<<"sizeof = "<<sizeof(p0)<<endl;
    Person1 p1;
    cout<<"sizeof = "<<sizeof(p1)<<endl;


    // this指针
    Person p(10);
    cout<<p.age<<endl;
    Person p2(18);
    // 链式编程思想
    p2.personaddage(p).personaddage(p).personaddage(p);
    cout<<p2.age<<endl;



    // 类得空指针可以访问成员函数，当访问成员变量时会发生错误
    Person2 * p3 = NULL;
    p3->PrintName();
    // 不可以
    // cout<<p3->age<<endl;
    // 不可以
    // p3->PrintAge();


    // 常函数
    Animal a1;
    a1.showName();

    // 在对象前加const，变为常对象
    const Animal a2;
    // 常对象中的一般变量也不能修改
    // a2.m_a = 20;  // 错误
    // 特殊变量在常对象下可以修改
    a2.m_b = 30;
    // 常对象只能调用常函数
    a2.showName();
    // a2.func(); //错误

    return 0;
}
