#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>

class Person 
{
public:
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    bool operator==(const Person& p)
    {
        if(this->name==p.name&&this->age==p.age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // int operator==(const Person& p1)
    // {
    //     if(this->age==p1.age)
    //     {
    //         return true;
    //     }
    //     else
    //     {
    //         return false;
    //     }
    // }

    string name;
    int age;
};

// find
void test01()
{
    vector<int>v1;
    for(int i=0; i<10; i++)
    {
        v1.push_back(i);
    }

    vector<int>::iterator it=find(v1.begin(), v1.end(), 5);
    if(it!=v1.end())
    {
        cout<<"find 5 is ? True"<<endl;
    }

    Person p1("aaa", 23);
    Person p2("bbb", 24);
    Person p3("ccc", 25);
    vector<Person>vp;
    vp.push_back(p1);
    vp.push_back(p2);
    vp.push_back(p3);

    vector<Person>::iterator it2 = find(vp.begin(), vp.end(), p2);
    if(it2!=vp.end())
    {
        cout<<"find Person is ? True"<<endl;
    }    
}

class GreaterAge
{
public:
    bool operator()(Person&p)
    {
        return p.age>24;
    }

};

// find_if
void test02()
{

    Person p1("aaa", 23);
    Person p2("bbb", 24);
    Person p3("ccc", 25);
    vector<Person>vp;
    vp.push_back(p1);
    vp.push_back(p2);
    vp.push_back(p3);

    vector<Person>::iterator it = find_if(vp.begin(), vp.end(), GreaterAge());
    if(it!=vp.end())
    {
        cout<<"find out Person age>24: "<<it->name<<endl;
    }
}

// adjacent_find
void test03()
{
    vector<int>v1;
    v1.push_back(2);
    v1.push_back(1);
    v1.push_back(0);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(2);
    v1.push_back(2);

    vector<int>::iterator it = adjacent_find(v1.begin(), v1.end());
    if(it!=v1.end())
    {
        cout<<"find out adjacent num: "<<*it<<endl;
    }

}

void test04()
{
    vector<int>v1;
    v1.push_back(0);
    v1.push_back(1);
    v1.push_back(2);
    cout<<"find out is: "<<binary_search(v1.begin(), v1.end(), 1)<<endl;

}

void test05()
{
    Person p("bbb", 24);
    Person p1("aaa", 23);
    Person p2("bbb", 24);
    Person p3("ccc", 25);
    Person p4("ddd", 24);

    vector<Person>vp;
    vp.push_back(p1);
    vp.push_back(p2);
    vp.push_back(p3);
    vp.push_back(p4);

    cout<<"name and age all same people count: "<<count(vp.begin(), vp.end(), p)<<endl;

    vector<int>v1;
    v1.push_back(2);
    v1.push_back(1);
    v1.push_back(0);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(2);
    v1.push_back(2);

    cout<<"count 2 num: "<<count(v1.begin(), v1.end(), 2)<<endl;

}

class compareNum
{
public:

    bool operator()(int num)
    {
        return num>2;
    }

};

class compareAge
{
public:

    bool operator()(const Person& p)
    {
        return p.age>24;
    }

};

void test06()
{
    vector<int>v1;
    v1.push_back(2);
    v1.push_back(1);
    v1.push_back(0);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(2);
    v1.push_back(2);

    cout<<">2 num: "<<count_if(v1.begin(), v1.end(), compareNum())<<endl;

    Person p("bbb", 24);
    Person p1("aaa", 23);
    Person p2("bbb", 24);
    Person p3("ccc", 25);
    Person p4("ddd", 24);

    vector<Person>vp;
    vp.push_back(p1);
    vp.push_back(p2);
    vp.push_back(p3);
    vp.push_back(p4);

    cout<<"age>24 num: "<<count_if(vp.begin(), vp.end(), compareAge())<<endl;

}

int main(int argc, char const *argv[])
{

    // find：查找 
    test01();

    // find_if：条件查找 
    test02();

    // adjacent_find：查找相邻重复元素 
    test03();

    // binary_find：二分查找元素是否存在，返回0或1，只能在有序的容器中使用。
    test04();

    // count：统计目标元素
    test05();

    // count：按条件统计元素
    test06();

    return 0;
}

