#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>

template<class T>
void printT(const T&t)
{
    for(class T::cosnt_iterator it=t.begin(); it!=t.end(); it++)
    {
        cout<<*it<<"  ";
    }
    cout<<endl;
}

void printv(int num)
{
    cout<<num<<" ";
}

class Printv
{
public:
    void operator()(int num)
    {
        cout<<num<<" ";
    }

};

class Transform
{
public:
    int operator()(int v)
    {
        return v/2;
    }

};

int main(int argc, char const *argv[])
{
    vector<int>v1;
    for(int i=0; i<10; i++)
    {
        v1.push_back(i+i);
    }
    // 常用遍历：for_each
    // 普通函数进行遍历
    for_each(v1.begin(), v1.end(), printv);
    cout<<endl;

    // 仿函数
    for_each(v1.begin(), v1.end(), Printv());
    cout<<endl;

    // 搬运数据：transform，搬运过程可以做一些操作。 注意 **要给目标容器开辟空间
    vector<int>v2;
    v2.resize(v1.size());
    transform(v1.begin(), v1.end(), v2.begin(), Transform());
    for_each(v2.begin(), v2.end(), Printv());


    return 0;
}

