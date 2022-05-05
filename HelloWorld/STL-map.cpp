#include<iostream>
#include<map>
using namespace std;

/*
map为树结构
map中所有元素都是pair
pair中第一个元素为key（键值），第二个元素为value（实值）
所有元素都会根据元素的键值自动排序

map中不允许有重复的键值
multimap容许出现重复的键值
*/ 
template<class T>
void printM(const T&m1)
{
    for(class T::const_iterator it=m1.begin(); it!=m1.end(); it++)
    {
        cout<<"key: "<<it->first<<", value: "<<it->second<<";   ";
    }
    cout<<endl;
}

// map容器的构造和赋值，查找和统计
void test01()
{
    // 默认构造
    map<int, int> m1;
    m1.insert(pair<int, int>(5,100));
    m1.insert(pair<int, int>(2,20));
    m1.insert(pair<int, int>(3,50));
    m1.insert(pair<int, int>(4,80));
    m1.insert(pair<int, int>(1,10));
    printM<map<int, int>>(m1);

    // 拷贝构造
    map<int,int>m2(m1);
    printM<map<int, int>>(m2);

    // 等号赋值
    map<int, int>m3;
    m3 = m2;
    printM<map<int, int>>(m3);

    // key查找
    map<int,int>::iterator pos = m3.find(2);
    if(pos!=m3.end())
    {
        cout<<"find key=2"<<endl;
    }

    // 统计
    cout<<"count key=2 num: "<<m1.count(2)<<endl;

}

// map的交换和大小
void test02()
{
    // 默认构造
    map<int, int> m1;

    m1.insert(pair<int, int>(5,100));
    m1.insert(pair<int, int>(2,20));
    m1.insert(pair<int, int>(3,50));
    m1.insert(pair<int, int>(4,80));
    m1.insert(pair<int, int>(1,10));
    printM<map<int, int>>(m1);

    cout<<"empty?: "<<m1.empty()<<endl;

    cout<<"size: "<<m1.size()<<endl;

    map<int, int> m2;

    m2.insert(pair<int, int>(4,90));
    m2.insert(pair<int, int>(1,10));
    m2.insert(pair<int, int>(2,40));
    m2.insert(pair<int, int>(3,70));
    m2.insert(pair<int, int>(0,0));

    cout<<"swap m1=: ";
    m1.swap(m2);

    printM<map<int, int>>(m1);

}

// map的插入和删除
void test03()
{
    map<int, int>m1;

    m1.insert(pair<int,int>(1,1));
    m1.insert(make_pair(2,2));
    m1.insert(map<int,int>::value_type(3,3));
    m1[4] = 4;
    // 当使用map中的键值key不存在时，map会创建该键值key，并赋值为value=0
    cout<<m1[5]<<endl;
    printM<map<int,int>>(m1);

    // 按照key删除
    m1.erase(5);
    printM<map<int,int>>(m1);

    // 清空
    // m1.erase(m1.begin(),m1.end())
    m1.clear();
    printM<map<int,int>>(m1);

}

class CompareNum
{
public:
    bool operator()(int v1, int v2)
    {
        return v1>v2;
    }

};

// map中的排序
void test04()
{
    // 默认构造
    map<int, int, CompareNum> m1;

    m1.insert(make_pair(5,100));
    m1.insert(make_pair(2,20));
    m1.insert(make_pair(3,50));
    m1.insert(make_pair(4,80));
    m1.insert(make_pair(1,10));

    printM<map<int, int, CompareNum>>(m1);

}
int main(int argc, char const *argv[])
{
    
    test01();
    test02();
    test03();
    test04();
    return 0;
}
