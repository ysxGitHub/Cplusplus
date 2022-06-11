#include<iostream>
#include<string>
using namespace std;

/*
C++11 中 auto 并不代表一种实际的数据类型，只是一个类型声明的 “占位符”，
    auto 并不是万能的在任意场景下都能够推导出变量的实际类型，
    使用auto声明的变量必须要进行初始化，
    以让编译器推导出它的实际类型，在编译时将auto占位符替换为真正的类型。
*/

auto var = 100; // int var

/*
    当变量不是指针或者引用类型时，推导的结果中不会保留 const、volatile 关键字
    当变量是指针或者引用类型时，推导的结果中会保留 const、volatile 关键字
*/

auto x = 3.14;
auto y = 20;
auto z = 'c';
auto nb; //error
auto double flag1; //error

int tmp = 10;

auto* a = &tmp; // auto == int

auto b = &tmp; // auto == int*

auto d = tmp;

// 有 const 修饰
int t1 = 20;

// const int x1;
const auto x1 = t1;

// int x2;
auto x2 = x1;

// const int y1;
auto& y1 = x1;

// const int *z1;
auto* z1 = &x1;

// 常量指针
*z1 = 20; // error



char ch = 'h';
char s = 'm';
const char*p1 = &ch; //常量指针:可以通过它更换指向的对象，但是不能改变指向对象的值；
char *const p2 = &ch; //指针常量:可以通过它更改对象的值，但是不能更改指向的对象；
// p1 = &s;//正确;
// *p1 = 'k';//错误;
// *p2 = 'k';//正确;
// p2 = &s;//错误;


