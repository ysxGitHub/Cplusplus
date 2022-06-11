#include<iostream>
using namespace std;
#include<deque>
#include<algorithm>

template<class T>
void printD(const deque<T>&v)
{
    // 注意：上面的容器只读，下面的迭代器也就只能只读
    for(typename std::deque<T>::const_iterator it=v.begin(); it!=v.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

// deque的初始化、赋值
void test01()
{
    // 默认的构造形式
    deque<int>d1;
    for(int i=0;i<10;i++)
    {
        d1.push_back(i);
    }
    printD<int>(d1);

    // 拷贝元素构造
    deque<int>d2(d1.begin(), d1.end());
    printD<int>(d2);

    // 初始化为n个elem
    deque<int>d3(10,1);
    printD<int>(d3);

    // 拷贝构造
    deque<int>d4(d3);
    printD<int>(d4);

    // 赋值
    // 等号重载赋值
    deque<int>d5;
    d5 = d1;
    printD<int>(d5);
    deque<int>(d6);

    // 数据拷贝赋值
    d6.assign(d1.begin(), d1.end());
    printD<int>(d6);

    // n个elem元素赋值
    deque<int>d7;
    d7.assign(10, 10);
    printD<int>(d7);


}
// deque的大小操作
void test02()
{
    deque<int>d1;
    for(int i=0;i<10;i++)
    {
        d1.push_back(i);
    }
    printD<int>(d1);
    // 是否为空
    cout<<"deque is empty? "<<d1.empty()<<endl;
    // deque的大小
    cout<<"deque size: "<<d1.size()<<endl;
    // deque的重定义大小，其余元素填入1
    d1.resize(15, 1);
    cout<<"deque resize: "<<d1.size()<<endl;
    printD<int>(d1);
    // deque的重定义大小，删除多余元素
    d1.resize(9);
    cout<<"deque resize: "<<d1.size()<<endl;
    printD<int>(d1);

}

// deque的插入和删除
void test03()
{
    deque<int>d1;
    // 尾插
    d1.push_back(1);
    // 头插
    d1.push_front(2);
    d1.push_front(3);
    d1.push_back(4);
    printD<int>(d1);

    // 尾删
    d1.pop_back();
    printD<int>(d1);
    // 头删
    d1.pop_front();
    printD<int>(d1);

    deque<int>d2;
    for(int i=0;i<10;i++)
    {
        d2.push_back(i*2);
    }
    printD<int>(d2);
    // 头插元素2
    d2.insert(d2.begin(),2);
    printD<int>(d2);
    // 头插2个元素4
    d2.insert(d2.begin(),2,4);
    printD<int>(d2);
    // 将d1的全部元素插入d2的头部
    d2.insert(d2.begin(),d1.begin(),d1.end());
    printD<int>(d2);

    deque<int>::iterator it=d2.begin();
    it++;
    // iterator控制删除位置
    d2.erase(it);
    printD<int>(d2);

    // 全部删除
    // d2.erase(d2.begin(), d2.end());
    printD<int>(d2);

    // 清空
    d2.clear();
    printD<int>(d2);

}

// deque数据的存取， 排序
void test04()
{
    deque<int>d1;
    for(int i=6;i>=0;i--)
    {
        d1.push_back(i);
    }
    // 输出第1元素
    cout<<d1[3]<<endl;
    cout<<d1.at(2)<<endl;

    // 获取第一个和最后一个位置的数据
    cout<<d1.front()<<endl;
    cout<<d1.back()<<endl;

    // 排序
    printD<int>(d1);
    sort(d1.begin(),d1.end());
    printD<int>(d1);

}

int main(int argc, char const *argv[])
{
    test01();
    test02();
    test03();
    test04();
    return 0;
}

