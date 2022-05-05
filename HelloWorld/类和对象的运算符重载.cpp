#include <iostream>
using namespace std;

class Person
{
public:

    // 1. 通过成员函数实现重载+号
    Person operator+(Person &p)
    {
        Person temp;
        temp.a = this->a + p.a;
        temp.b = this->b + p.b;
        return temp;
    }
    Person operator+(int num)
    {
        Person temp;
        temp.a = this->a + num;
        temp.b = this->b + num;
        return temp;
    }

    // 不会利用成员函数重载<<运算符，因为无法实现
    // ostream& operator<<()
    // {
    //     return 
    // }


    int a;
    int b;
};

// 2. 通过全局函数实现重载+号
// Person operator+(Person&p1, Person&p2)
// {
//     Person temp;
//     temp.a = p1.a + p2.a;
//     temp.b = p1.b + p2.b;

//     return temp;
// }

// 只能利用全局函数重载<<运算符
ostream& operator<<(ostream& cout, Person& p)
{
    cout<<"a: "<<p.a<<" b: "<<p.b;
    return cout;
}


class MyInteger
{
public:
    friend ostream& operator<<(ostream& cout, MyInteger m1);

    MyInteger(int num)
    {
        this->m = num;
    }

    // 前置++重载
    MyInteger& operator++()
    {
        ++this->m;
        return *this;
    }
    // 后置++重载, 用占位参数int，和前置进行区分
    MyInteger operator++(int)
    {
        MyInteger temp = *this;
        this->m++;
        return temp;
    }

private:
    int m;

};

ostream& operator<<(ostream& cout, MyInteger m1)
{
    cout<<m1.m;
    return cout; 
}


class Teacher
{
public:

    int * age;

    Teacher(int age)
    {
        this->age = new int(age);
    }

    ~Teacher()
    {
        if(age!=NULL)
        {
            delete age;
            age = NULL;
        }
        
    }
    Teacher& operator=(Teacher &p)
    {
        // 编译器提供的是浅拷贝
        // age = p.age;
        
        // 先判断是否有属性在堆区，如果有先释放干净，然后再深拷贝
        if(age!=NULL)
        {
            delete age;
            age = NULL;
        }
        // 实现深拷贝
        age = new int(*p.age);
        // 实现连等于，返回自身
        return *this;
    }

};

class Student
{

public:
    Student(string name, int age)
    {
        this->name = name;
        this->age = age;

    }

    bool operator==(Student &s)
    {
        if((this->age==s.age)&&(this->name==s.name))
        {
            return true;
        }
        else
        {
            return false;
        }

    } 
    bool operator!=(Student &s)
    {
        if((this->age==s.age)&&(this->name==s.name))
        {
            return false;
        }
        else
        {
            return true;
        }

    } 

    string name;
    int age;

};

class MyPrint
{

public:
    void operator()(string test)
    {

        cout<<test<<endl;
    }
    int operator()(int a, int b)
    {
        return a+b;
    }

};

int main(int argc, char const *argv[])
{

    Person p1;
    Person p2;
    p1.a = 10;
    p1.b = 20;
    p2.a = 10;
    p2.b = 20;
    
    // 成员函数重载调用本质
    // Person p3  = p1.operator+(p2);
    // 全局函数重载调用本质
    // Person p3 = operator+(p1, p2);

    Person p3 = p1 + p2;
    cout<<p3.a<<" "<<p3.b<<endl;

    // 运算符重载也可以发生函数重载。
    Person p4 = p1 + 10;
    cout<<p4.a<<" "<<p4.b<<endl;

    // <<运算符的重载
    cout<<p4<<endl;

    MyInteger myint(10);
    cout<<myint<<endl;

    // 重载前置++
    cout<<++(++myint)<<endl;
    cout<<myint<<endl;

    // 重载后置++ 有点问题先屏蔽
    cout<<myint++<<endl;
    cout<<myint<<endl;

    // 重载赋值运算符
    Teacher t1(200);
    Teacher t2(100);
    Teacher t3(300);
    t3 = t2 = t1;
    cout<<*t1.age<<endl;
    cout<<*t2.age<<endl;
    cout<<*t3.age<<endl;

    // 关系运算符重载
    Student s1("Tom", 12);
    Student s2("Tom", 12);
    // == 和 !=
    cout<<(s1==s2)<<endl;
    cout<<(s1!=s2)<<endl;

    // 重载函数调用运算符  ()
    MyPrint mp;
    // 由于使用起来非常像函数调用，所有称为重载函数调用
    mp("hello world");
    cout<<mp(10,10)<<endl;
    // 匿名对象调用
    cout<<MyPrint()(100,100)<<endl;

    return 0;
}
