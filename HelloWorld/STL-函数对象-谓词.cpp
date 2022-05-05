#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

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

函数对象 返回值类型是bool，称为谓词
一元谓词：函数对象中重载函数只有一个参数
二元谓词：函数对象中重载函数有两个参数

*/

class FindBigFive
{
public:
    // 一元谓词
    bool operator()(int num)
    {
        return num>5;
    }
};


class compareNum
{
public:
    bool operator()(int a, int b)
    {
        return a>b;
    }

};


int main(int argc, char const *argv[])
{
    vector<int>v1;
    v1.push_back(2);
    v1.push_back(1);
    v1.push_back(5);
    v1.push_back(3);
    v1.push_back(4);

    vector<int>::iterator it=find_if(v1.begin(), v1.end(), FindBigFive());
    if(it!=v1.end())
    {
        cout<<"find out: "<<*it<<endl;
    }

    sort(v1.begin(),v1.end());
    printT<int>(v1);
    sort(v1.begin(),v1.end(), compareNum());
    printT<int>(v1);
    
    return 0;
}

