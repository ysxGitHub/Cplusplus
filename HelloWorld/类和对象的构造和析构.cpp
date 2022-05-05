
#include<iostream>
using namespace std;

// 构造函数:主要作用在于创建对象时为对象的成员属性赋值,构造函数由编译器自动调用,无须手动调用.
/*
    构造函数: 类名(){}
        1.构造函数,没有返回值也不用写void
        2.函数名称与类名相同
        3.构造函数可以有参数,因此可以发生重载
        4.程序调用对象时候会自动调用构造,无须手动调用,而且只会调用一次.
*/

// 析构函数:主要作用在于对象销毁前系统自动调用,执行一些清理工作.
/*
    析构函数: ~类名(){}
        1.析构函数,没有返回值也不用写void
        2.函数名称与类名相同,在名称前加上符合 ~
        3.析构函数不可以有参数,因此不可以发生重载
        4.程序调用对象时候会自动调用构造,无须手动调用,而且只会调用一次.
*/

// 构造与析构函数都是必须实现的, 如果我们不提供,编译器会提供一个空实现的构造和析构



class Person
{


public:
    int age = 10;

    Person()
    {
        cout<<"Person无参构造函数的调用"<<endl;
    }

    Person(int a)
    {
        age = a;
        cout<<"Person有参构造函数的调用"<<endl;
    }

    Person(const Person &p)
    {
        age = p.age;
        cout<<"Person拷贝构造函数的调用"<<endl;
    }

    ~Person()
    {
        cout<<"Person析构函数的调用"<<endl;
    }

// private:

};

void func1(Person p)
{
    cout<<"值传递的方式给函数参数传值"<<endl;
}

Person func2()
{
    Person p;
    cout<<&p<<endl;
    return p;
}

/*
构造函数的分类：
    按照参数分类：有参构造和无参构造
    按照类型分类：普通构造和拷贝构造

调用构造函数的方法：
    1.括号法
    2.显示法
    3.隐式转换法

C++中拷贝构造函数的调用时机
    1.使用一个已经创建完毕的对象来初始化一个新的对象
    2.值传递的方式给函数参数传值
    3.以值的方式返回局部对象

C++构造函数调用规则：
    1.如果用户定义有参构造函数，C++不在提供无参构造函数，但是会提供默认拷贝构造函数
    2.如果用户定义拷贝构造函数，C++不会在提供其他构造函数。
*/

class Student
{
public:
    int age=0; 
    Student()
    {
        cout<<"Student无参构造函数的调用"<<endl;
    }

    Student(int a)
    {
        age = a;
        cout<<"Student有参构造函数的调用"<<endl;
    }

    Student(const Student &p)
    {
        age = p.age;
        cout<<"Student拷贝构造函数的调用"<<endl;
    }

    ~Student()
    {
        cout<<"Student析构函数的调用"<<endl;
    }

};

void test1()
{
    Student stu1;
    stu1.age=18;
    // Student stu2(stu1);
    // cout<<stu2.age<<endl;
}

class Teacher
{

public:
    // 初始化列表方式初始化
    Teacher(int a, int b, int c):m_a(a),m_b(b),m_c(c)
    {
        cout<<"a = "<<m_a<<endl;
        cout<<"b = "<<m_b<<endl;
        cout<<"c = "<<m_c<<endl;
    }

private:
    int m_a;
    int m_b;
    int m_c;

};


// 调用构造函数
int main(int argc, char const *argv[])
{
    // 1.括号法
    Person p1; // 无参构造
    Person p2(10); // 有参构造
    Person p3(p2); // 拷贝构造  //1.使用一个已经创建完毕的对象来初始化一个新的对象

    // ps:调用默认构造函数时，不要加(); 加括号后会认为是一个函数声明 eg : void func()

    // 2.显示法
    Person p11; // 无参构造
    Person p22 = Person(10); // 有参构造
    Person p33 = Person(p22); // 拷贝构造  //1.使用一个已经创建完毕的对象来初始化一个新的对象

    Person(10); // 匿名对象 特点：当前执行结束后，系统会立即回收掉匿名对象
    //ps: 不要利用拷贝构造函数 初始化匿名对象
    // Person(p3); // Person p3 编译器认为是 对象声明

    // 隐式转换法
    Person p4 = 10; // 有参构造
    Person p5 = p4; // 拷贝构造  //1.使用一个已经创建完毕的对象来初始化一个新的对象

    // 2.值传递的方式给函数参数传值
    func1(p4);

    // 3.以值的方式返回局部对象
    Person p6 = func2();
    cout<<&p6<<endl;

    test1();

    // 初始化列表
    Teacher t1(10,20,30);

    system("pause"); // 请按任意键继续. . .
    return 0;
}




