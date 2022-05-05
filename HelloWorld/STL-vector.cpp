#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

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

ostream &operator<<(ostream&out, Person&p)
{
    out<<"name: "<<p.name<<"\t age: "<<p.age;
    return out;
}

void print(int val)
{
    cout<<val<<" ";
}

void test01()
{
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(5);

    // 第一种遍历方式
    // vector<int>::iterator pBegin = v.begin();
    // vector<int>::iterator pEnd = v.end();
    // while (pBegin!=pEnd)
    // {
    //     cout<<*pBegin<<" ";
    //     pBegin++;
    // }
    // cout<<endl;

    // 第二种遍历方式
    for(vector<int>::iterator it=v.begin(); it!=v.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    // 第三种遍历方式
    // for_each(v.begin(), v.end(), print);

}

void test02()
{
    vector<Person> v;
    Person p1("zhangsan",21);
    Person p2("lisi",22);
    Person p3("wangwu",23);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    // for(vector<Person>::iterator it=v.begin(); it!=v.end(); it++)
    // {
    //     cout<<(*it).name<<"\t"<<(*it).age<<endl;
    //      cout<<it->name<<"\t"<<it->age<<endl;
    // }
    for(vector<Person>::iterator it=v.begin(); it!=v.end(); it++)
    {
        cout<<*it<<endl;
    }

}


void test03()
{
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    for(int i=0; i<4; i++)
    {
        v1.push_back(i+1);
        v2.push_back(i+2);
        v3.push_back(i+3);
        v4.push_back(i+4);
    }

    vector<vector<int>>v;

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    for(vector<vector<int>>::iterator it=v.begin(); it!=v.end(); it++)
    {
        for(vector<int>::iterator vit=(*it).begin(); vit!=(*it).end(); vit++)
        {
            cout<<*vit<<" ";
        }
        cout<<endl;
    }

}


int main(int argc, char const *argv[])
{

    test01();

    test02();

    test03();

    return 0;
}





