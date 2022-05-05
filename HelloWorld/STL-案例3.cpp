#include<iostream>
#include<vector>
#include<map>
using namespace std;

#define JUECE 1
#define KAIFA 2
#define MEISHU 3

class Person
{

public:
    string name;
    int salary;

};

void createPerson(vector<Person>&v)
{
    string namestr = "ABCDEFGHIJ";
    for(int i=0; i<10; i++)
    {
        int salary = rand()%10000+10000;
        string name = "Worker-";
        name = name + namestr[i];
        Person p;
        p.name=name;
        p.salary = salary; 
        v.push_back(p);
    }

}

void setGroup(vector<Person>&vp, multimap<int, Person>&mp)
{
    for(vector<Person>::iterator it=vp.begin(); it!=vp.end(); ++it)
    {
        int sec = rand()%3;
        mp.insert(make_pair(sec, *it));
    }
}

void printAll(const multimap<int, Person>&mp)
{
    // 决策
    cout<<"JUECE***********"<<endl;
    multimap<int, Person>::const_iterator it = mp.find(JUECE);
    int index = 0;
    int num = mp.count(JUECE);
    for(; it!=mp.end()&&index<=num; it++, index++)
    {
        cout<<it->second.name<<"  "<<it->second.salary<<endl;
    }
    // 技术
    cout<<"KAIFA***********"<<endl;
    multimap<int, Person>::const_iterator it1 = mp.find(KAIFA);
    int index1 = 0;
    int num1 = mp.count(KAIFA);
    for(; it1!=mp.end()&&index1<=num1; it1++, index1++)
    {
        cout<<it1->second.name<<"  "<<it1->second.salary<<endl;
    }
    // 美术
    cout<<"MEISHU***********"<<endl;
    multimap<int, Person>::const_iterator it2 = mp.find(MEISHU);
    int index2 = 0;
    int num2 = mp.count(MEISHU);
    for(; it2!=mp.end()&&index2<=num2; it2++, index2++)
    {
        cout<<it2->second.name<<"  "<<it2->second.salary<<endl;
    }

}

int main(int argc, char const *argv[])
{
    vector<Person>vp;
    createPerson(vp);
    // for(vector<Person>::iterator it=vp.begin(); it!=vp.end(); it++)
    // {
    //     cout<<it->name<<"  "<<it->salary<<endl;
    // }

    multimap<int, Person>mp;
    setGroup(vp, mp);
    printAll(mp);

    return 0;
}

