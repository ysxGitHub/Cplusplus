#include<iostream>
using namespace std;

#include<list>


class Person
{

public:
    Person(string name, int age, int height)
    {
        this->name = name;
        this->age = age;
        this->height = height;
    }

    string name;
    int age;
    int height;

};

void printL(const list<Person>&L1)
{
    for(list<Person>::const_iterator it=L1.begin(); it!=L1.end(); it++)
    {
        cout<<"name: "<<it->name<<"\t age: "<<it->age<<"\t height: "<<it->height<<endl;
    }

}

void CreatePeople(list<Person>&L1)
{
    Person p1("zhangsan",23, 175);
    Person p2("lisi",23, 170);
    Person p3("wangwu",21, 178);
    Person p4("dalang",30, 168);
    Person p5("xiaoyi",20, 188);

    L1.push_back(p1);
    L1.push_back(p2);
    L1.push_back(p3);
    L1.push_back(p4);
    L1.push_back(p5);
}

//指定排序规则
bool comparePerson(Person& p1, Person& p2)
{
    if(p1.age<p2.age)
    {
        return true;
    }
    else if(p1.age==p2.age)
    {
        if(p1.height<=p2.height)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
     
} 

int main(int argc, char const *argv[])
{

    list<Person>L1;
    CreatePeople(L1);
    printL(L1);
    L1.sort(comparePerson);
    cout<<"sort _____________________"<<endl;
    printL(L1);
    return 0;
}



