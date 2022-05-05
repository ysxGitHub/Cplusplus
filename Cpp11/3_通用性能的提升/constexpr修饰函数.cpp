#include<iostream>
#include<string>
using namespace std;

// error 没有返回值
constexpr void func1(){

}

// error 返回的是变量
constexpr int func1(){
    int a = 100;
    return a;
}

// error 不能提前声明，必须定义完整的函数
constexpr int func1();

// constexpr 要求整个函数的函数体中，不能出现非常量表达式之外的语句
//（using指令、typedef语句、static_assert断言、return除外）

// 通过的 函数模板 得到的函数 就叫做 模板函数

template<typename T>
constexpr T display(T t){
    return t;
}
// constexpr 修饰 模板函数，会根据实际情况判断是否是常量函数


class Student{
    // constexpr 修饰 构造函数时，初始必须写在初始化列表中
    constexpr Student(int a): aaa(a){

    }
    int aaa;
};