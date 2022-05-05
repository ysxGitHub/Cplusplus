#include<iostream>
using namespace std;


// 类模板

/*
与函数模板的区别：
    类模板没有自动类型推导的使用方式
    类模板中模板参数可以有默认参数

类模板中成员函数创建的时机: 调用时才创建

函数模板的对象作为函数参数
    1.指定传入的数据类型
    2.参数模板化
    3.将整个类模板 模板化
*/
class Person1
{
    
public:
    void Pprint01()
    {
        cout<<"Person1"<<endl;
    }

};
class Person2
{
    
public:
    void Pprint02()
    {
        cout<<"Person2"<<endl;
    }

};

template<class ClassType>
class MyClass
{
public:
    ClassType obj;

    void print01()
    {
        obj.Pprint01();
    }
    void print02()
    {
        obj.Pprint02();
    }

};

void test()
{
    MyClass<Person2> p1;
    // p1.print01();
    p1.print02();
}

template<class NameType, class AgeType=int>
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        this->name = name;
        this->age = age;
    }

    void PersonPrint()
    {
        cout<<this->name<<"  "<<this->age<<endl;
    }

    NameType name;
    AgeType age;
};


// 指定传入的数据类型
void Persontest01(Person<string, int>&p)
{
    p.PersonPrint();
}
void test01()
{
    Person<string, int> p("zhangsan", 20);
    Persontest01(p);
}

// 参数模板化
template<class T1, class T2>
void Persontest02(Person<T1, T2>&p)
{
    p.PersonPrint();
}
void test02()
{
    Person<string, int> p("qida", 22);
    Persontest02(p);
}


// 将整个类模板 模板化
template<class T>
void Persontest03(T &p)
{
    p.PersonPrint();
}
void test03()
{
    Person<string, int> p("liqing", 25);
    Persontest03(p);
}


int main(int argc, char const *argv[])
{
    // Person p1("lisi", 25); //不行
    Person<string> p1("lisi", 25);
    Person<string, int> p2("wangwu", 21);
    cout<<p1.name<<" "<<p1.age<<endl;
    cout<<p2.name<<" "<<p2.age<<endl;
    
    // 类模板中成员调用时机
    test();

    // 函数模板的对象作为函数参数
    test01();
    test02();
    test03();



    return 0;
}


