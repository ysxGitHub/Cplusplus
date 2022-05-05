#include<iostream>
#include<vector>
using namespace std;

template<class T>
void printT(vector<T>&v)
{
    for(typename std::vector<T>::iterator it=v.begin(); it!=v.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

// vector是动态容器，可以扩展，而数组一般是固定大小的

// vector的初始化
void test01()
{
    // 默认构造 无参构造
    vector<int> v1;
    
    for(int i=0; i<10; i++)
    {
        v1.push_back(i);
    }
    printT<int>(v1);

    //通过区间方式进行构造
    vector<int> v2(v1.begin(), v1.end());
    printT<int>(v2);

    // n个element方式构造
    vector<int> v3(10,100);
    printT<int>(v3);

    // 拷贝构造
    vector<int> v4(v2);
    printT<int>(v4);
}

// vector的赋值操作
void test02()
{

    vector<int> v1;
    
    for(int i=0; i<10; i++)
    {
        v1.push_back(i);
    }

    vector<int>v2;
    v2 = v1;
    printT<int>(v2);

    vector<int>v3;
    v3.assign(v2.begin(), v2.end());
    printT<int>(v3);

    vector<int>v4;
    v4.assign(10,100);
    printT<int>(v4);


}

// vector的容量和大小、插入、删除
void test03()
{
    vector<int> v1;
    
    for(int i=0; i<10; i++)
    {
        v1.push_back(i);
    }

    cout<<"v1 is empty?  "<<v1.empty()<<endl;
    cout<<"v1 size?  "<<v1.size()<<endl;
    cout<<"v1 capacity?  "<<v1.capacity()<<endl;

    // 指定v1大小，默认填充0，现在填充为100
    v1.resize(15, 100);
    cout<<"v1 resize?  "<<v1.size()<<endl;
    printT<int>(v1);

    // 指定v1大小，变小了就会删除原来最后的数据
    v1.resize(9);
    cout<<"v1 resize?  "<<v1.size()<<endl;
    printT<int>(v1);

    vector<char>v2;
    // 尾插法
    v2.push_back('a');
    v2.push_back('b');
    v2.push_back('c');
    v2.push_back('d');
    v2.push_back('e');
    v2.push_back('f');
    printT<char>(v2);
    
    // 尾删法
    v2.pop_back();
    printT<char>(v2);

    // 插入第一个位置
    v2.insert(v2.begin(), 'f');
    printT<char>(v2);
    // 插入第一个位置两个g
    v2.insert(v2.begin(), 2, 'g');
    printT<char>(v2);

    // 删除
    v2.erase(v2.begin());
    printT<char>(v2);


    // 清空
    // v2.erase(v2.begin(), v2.end());
    v2.clear();
    printT<char>(v2);

}

// vector的数据存取, 容器元素互换
void test04()
{
    vector<int> v1;
    
    for(int i=0; i<10; i++)
    {
        v1.push_back(i);
    }

    // 得到对应index的数据
    cout<<v1[2]<<endl;
    cout<<v1.at(2)<<endl;
    // 返回第一元素和最后一个
    cout<<v1.front()<<endl;
    cout<<v1.back()<<endl;

    vector<int> v2;
    
    for(int i=9; i>=0; i--)
    {
        v2.push_back(i);
    }

    // 交换两个容器的数据
    v1.swap(v2);
    printT<int>(v1);
    printT<int>(v2);
    // swap交换的实际用途

    vector<int> v;
    
    for(int i=0; i<100000; i++)
    {
        v.push_back(i);
    }

    cout<<"size: "<<v.size()<<endl;
    cout<<"capacity: "<<v.capacity()<<endl;

    v.resize(3);

    cout<<"size: "<<v.size()<<endl;
    cout<<"capacity: "<<v.capacity()<<endl;

    vector<int>(v).swap(v);

    cout<<"size: "<<v.size()<<endl;
    cout<<"capacity: "<<v.capacity()<<endl;



}

int main(int argc, char const *argv[])
{

    test01();

    test02();

    test03();

    test04();

    // vector预留空间
    vector<int>v1;
    // 预留空间可以减少程序在内存中开辟空间的次数
    // v1.reserve(10);
    cout<<"size: "<<v1.size()<<endl;
    cout<<"capacity: "<<v1.capacity()<<endl;
    int num=0;
    int *p=NULL;
    for(int i=0; i<10; i++)
    {
        if(p!=&v1[0])
        {
            num++;
            p=&v1[0];
        }
        v1.push_back(i);
    }
    cout<<"kai pi room ci shu: "<<num<<endl;
    cout<<"size: "<<v1.size()<<endl;
    cout<<"capacity: "<<v1.capacity()<<endl;

    return 0;
}


