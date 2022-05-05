#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

template<class T>
void printAll(const T& vp)
{
    for(class T::const_iterator it=vp.begin(); it!=vp.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

void print(int val)
{
    cout<<val<<" ";
}

int main(int argc, char const *argv[])
{
    vector<int>v1;
    vector<int>v2;

    for(int i=1; i<7; i++)
    {
        v1.push_back(i);
        v2.push_back(i+3);
    }
    cout<<"v1:  ";
    printAll<vector<int>>(v1);
    cout<<"v2:  ";
    printAll<vector<int>>(v2);
    
    // 目标容器
    vector<int>v3;
    // 开辟空间时，交集取两个容器中的较小的size，并集取两个容器size之和
    v3.resize(min(v1.size(), v2.size()));
    // 交集, 返回目标容器的最后位置， 注意容器必须有序
    vector<int>::iterator iend=set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    cout<<"intersection: ";
    // 注意：如果这里使用目标容器的end()，会将所有的元素都打印出来，包括0...
    for_each(v3.begin(), iend, print);
    cout<<endl;

    // 并集，注意容器必须有序
    vector<int>v4;
    v4.resize(v1.size()+v2.size());
    vector<int>::iterator iend1=set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v4.begin());
    cout<<"union: ";
    for_each(v4.begin(), iend1, print);
    cout<<endl;

    // 差集，注意容器必须有序
    vector<int>v5;
    v5.resize(max(v1.size(), v2.size()));
    vector<int>::iterator iend2=set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v5.begin());
    cout<<"difference v1: ";
    for_each(v5.begin(), iend2, print);
    cout<<endl;
    vector<int>::iterator iend3=set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), v5.begin());
    cout<<"difference v2: ";
    for_each(v5.begin(), iend3, print);

    return 0;
}
