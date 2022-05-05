#include<iostream>
#include<set>
using namespace std;


class Person
{

public:
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    string name;
    int age;
};

/*
set为树结构
set容器自动排序
set容器不能有重复的元素
multiset容器可以包含重复元素
*/ 
template<class T>
void printS(const T& S)
{
    for(class T::const_iterator it=S.begin(); it!=S.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

}

// set容器的构造和赋值
void test01()
{
    // 默认构造
    set<int>s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(5);
    s1.insert(0);
    printS<set<int>>(s1);

    // 拷贝构造
    set<int>s2(s1);
    s2.insert(20);
    printS<set<int>>(s2);

    // 赋值构造
    set<int>s3;
    s3 = s1;
    printS<set<int>>(s3);

}

// set容器的大小和交换，插入和删除
void test02()
{
    set<int>s1;
    cout<<"empty?: "<<s1.empty()<<endl;
    s1.insert(4);
    s1.insert(2);
    s1.insert(5);
    s1.insert(3);
    cout<<"size: "<<s1.size()<<endl;

    set<int>s2;
    s2.insert(40);
    s2.insert(20);
    s2.insert(50);
    s2.insert(30);

    // 交换
    s1.swap(s2);
    printS<set<int>>(s1);

    // 删除
    s1.erase(s1.begin());
    printS<set<int>>(s1);

    s1.erase(50);
    printS<set<int>>(s1);

    // 清空
    s1.clear();
    printS<set<int>>(s1);
}

void test03()
{
    set<int>s1;
    pair<set<int>::iterator, bool> ret = s1.insert(4);
    cout<<"first insert 5?: "<<ret.second<<endl;
    s1.insert(2);
    s1.insert(5);
    s1.insert(3);
    s1.insert(1);
    pair<set<int>::iterator, bool> ret1 = s1.insert(5);
    cout<<"second insert 5?: "<<ret1.second<<endl;

    set<int>::iterator fit = s1.find(5);
    if(fit!=s1.end())
    {
        cout<<"find out 5"<<endl;
    }
    else
    {
        cout<<"no find out 5"<<endl;
    }

    cout<<"count 5 num: "<<s1.count(5)<<endl;

    // multiset
    multiset<int>ms1;
    ms1.insert(10);
    ms1.insert(10);
    printS<multiset<int>>(ms1);
}

// 自定义排序规则
class myCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1>v2;
    }

};


// set容器的排序
void test04()
{
    // 从大到小
    set<int, myCompare>s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(0);
    printS<set<int, myCompare>>(s1);


}

class CompareAge
{
public:
    bool operator()(const Person& p1, const Person& p2)
    {
        return p1.age<p2.age;
    }


};

// 自定义数据类型排序
void test05()
{
    set<Person,CompareAge>s1;
    Person p1("AAA", 23);
    Person p2("BBB", 21);
    Person p3("CCC", 26);
    Person p4("DDD", 22);

    s1.insert(p1);
    s1.insert(p2);
    s1.insert(p3);
    s1.insert(p4);

    for(set<Person, CompareAge>::const_iterator it=s1.begin(); it!=s1.end(); it++)
    {
        cout<<"name: "<<it->name<<"\t age: "<<it->age<<endl;
    }
}

int main(int argc, char const *argv[])
{
    test01();
    test02();
    test03();
    test04();
    test05();
    return 0;
}


