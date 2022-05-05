#include<iostream>
#include<functional>
using namespace std;
#include<algorithm>
#include<vector>


template<class T>
void printT(vector<T>&v)
{
    for(typename std::vector<T>::iterator it=v.begin(); it!=v.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

/*
内建函数是STL提供的函数对象

*/ 


int main(int argc, char const *argv[])
{
    // 1.运算仿函数
    // 取反
    negate<int>n;
    cout<<"negate: "<<n(10)<<endl;

    // 相加
    plus<int>p;
    cout<<"add: "<<p(10,20)<<endl;

    // 2.关系仿函数
    vector<int>v1;
    v1.push_back(3);
    v1.push_back(2);
    v1.push_back(5);
    v1.push_back(4);
    v1.push_back(1);
    // 降序排序仿函数 greater<>()
    sort(v1.begin(), v1.end(), greater<int>());
    printT<int>(v1);

    // 3.逻辑仿函数
    vector<bool>v2;
    v2.push_back(false);
    v2.push_back(true);
    v2.push_back(false);
    printT<bool>(v2);

    vector<bool>v3;
    v3.resize(v2.size());
    transform(v2.begin(), v2.end(), v3.begin(), logical_not<bool>());
    printT<bool>(v3);
    
    return 0;
}
