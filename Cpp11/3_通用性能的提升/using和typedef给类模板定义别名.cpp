/*
使用 typedef 重定义类似很方便，但是它有一点限制，比如无法重定义一个模板
*/
#include<map>
#include<iostream>
using namespace std;

template <typename T>
typedef map<int, T> type;	// error, 语法错误

// 如何解决上面的问题？如下
template <typename T>
// 定义外敷类
struct MyMap
{
    typedef map<int, T> type;
};

MyMap<int>::type mm1;
MyMap<double>::type mm2;
MyMap<string>::type mm2;

// using 给模板定义别名
template <typename T>
using Mmap = map<int, T>;

Mmap<int> m1;
Mmap<double> m2;
Mmap<string> m3;

