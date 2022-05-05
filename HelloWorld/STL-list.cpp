#include<iostream>
using namespace std;
#include<list>

template<typename T>
void print(const T &l)
{
    for(typename T::const_iterator lit=l.begin(); lit!=l.end(); lit++)
    {
        cout<<*lit<<"  ";
    }
    cout<<endl;
}

/*
链表
    优点：
        可以对任意位置进行快速插入和删除
    缺点：
        变量的速度慢些，占用空间大些

*/ 

// list构造函数，赋值和交换
void test01()
{
    // 默认构造方式
    list<int>l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    print<list<int>>(l1);

    // 区间方式构造
    list<int>l2(l1.begin(), l1.end());
    print<list<int>>(l2);

    //拷贝构造
    list<int>l3(l2);
    print<list<int>>(l3);

    // n个m构造
    list<int>l4(3,10);
    print<list<int>>(l4);

    // = 赋值 
    list<int>l5;
    l5 = l4;
    print<list<int>>(l5);

    // 区间赋值
    list<int>l6;
    l6.assign(l5.begin(), l5.end());
    print<list<int>>(l6);
    
    //assign 赋值
    list<int>l7;
    l7.assign(3,100);
    print<list<int>>(l7);


    // 容器互换
    l1.swap(l7);
    cout<<"swap after: "<<endl;
    print<list<int>>(l1);
    print<list<int>>(l7);

}


// list容器的大小操作, 存取
void test02()
{
    list<int>l1;
    cout<<"l1 empty: "<<l1.empty()<<endl;

    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    print<list<int>>(l1);
    cout<<"l1 size: "<<l1.size()<<endl;

    l1.resize(10,6);
    print<list<int>>(l1);

    l1.resize(2);
    print<list<int>>(l1);

    // front
    cout<<"front: "<<l1.front()<<endl;
    // back
    cout<<"back: "<<l1.back()<<endl;
    // list 是链表 不可以使用[] 和 at()操作

}

// list容器的插入和删除
void test03()
{
    list<int>l1;

    // 尾插
    l1.push_back(1);
    l1.push_back(2);
    // 首插
    l1.push_front(3);
    l1.push_front(4);
    print<list<int>>(l1);

    // 尾删
    l1.pop_back();
    // 首删
    l1.pop_front();
    print<list<int>>(l1);

    list<int>::iterator lit=l1.begin();
    // 支持++和--，不支持+j和-j（不支持随机访问）
    lit++;
    // insert插入
    l1.insert(lit, 100);
    print<list<int>>(l1);
    // erase删除
    l1.erase(lit);
    print<list<int>>(l1);

    l1.push_back(2);
    l1.push_back(2);
    l1.push_back(2);
    print<list<int>>(l1);
    // remove删除
    l1.remove(2);
    print<list<int>>(l1);

    // clear清空
    l1.clear();
    print<list<int>>(l1);

}

bool BoolCompare(int v1, int v2)
{

    return v1>v2;
}
// list的排序和反转
void test04()
{
    list<int>l1;
    l1.push_back(4);
    l1.push_front(5);
    l1.push_back(1);
    l1.push_front(3);
    l1.push_back(6);
    l1.push_front(7);
    l1.push_back(9);
    l1.push_front(8);
    l1.push_front(2);

    cout<<"sort before: "<<endl;
    print<list<int>>(l1);

    cout<<"reverse: "<<endl;
    l1.reverse();
    print<list<int>>(l1);

    cout<<"sort after: "<<endl;
    l1.sort();
    print<list<int>>(l1);

    cout<<"sort1 after: "<<endl;
    l1.sort(BoolCompare);
    print<list<int>>(l1);
    // 所有不支持随机访问的容器，不可以用标准算法algorithm
    // sort(l1.begin(), l1.end())  //不行

}

int main(int argc, char const *argv[])
{
    cout<<"************test01************"<<endl;
    test01();

    cout<<"************test02************"<<endl;
    test02();

    cout<<"************test03************"<<endl;
    test03();

    cout<<"************test04************"<<endl;
    test04();

    return 0;
}
