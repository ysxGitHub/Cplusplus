#include<iostream>
using namespace std;


template<class NameType, class AgeType> class Person;

template<class NameType, class AgeType>
void PrintP1(Person<NameType, AgeType>&p)
{
    cout<<"class exter"<<p.name<<"  "<<p.age<<endl;
}


template<class NameType, class AgeType>
class Person
{
// 全局函数配合友元，类内实现
friend void PrintP(Person<NameType, AgeType>&p)
{
    cout<<"class inter"<<p.name<<"  "<<p.age<<endl;
}

// 全局函数配合友元，类外实现
friend void PrintP1<>(Person<NameType, AgeType>&p);

public:
    Person(NameType name, AgeType age);
    // {
    //     this->name = name;
    //     this->age = age;
    // }

    void PersonPrint();
    // {
    //     cout<<this->name<<"  "<<this->age<<endl;
    // }

    NameType name;
    AgeType age;
};

// 成员函数类模板外实现
template<class NameType, class AgeType>
Person<NameType, AgeType>::Person(NameType name, AgeType age)
{
    this->name = name;
    this->age = age;
}

// 成员函数类模板外实现
template<class NameType, class AgeType>
void Person<NameType, AgeType>::PersonPrint()
{
    cout<<this->name<<"  "<<this->age<<endl;
}


