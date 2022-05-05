#include<iostream>

// 在 C++ 中可以通过 typedef 重定义一个类型，语法格式如下：
// typedef 旧的类型名 新的类型名;
// 使用举例
typedef unsigned int uint_t;

// 使用 using 定义 别名 的语法格式是这样的：
// using 新的类型 = 旧的类型;
// 使用举例
using uint_t = int;




// 假设我们定义一个函数指针，using 的优势就能凸显出来了，看一下下面的例子：
// 使用typedef定义函数指针
typedef int(*func_ptr)(int, std::string);

// 使用using定义函数指针
using func_ptr1 = int(*)(int, std::string);

int mytest(int a, std::string b){
    std::cout<<"a: "<<a<<", b: "<<b<<std::endl;
    return 0;
}

int main(int argc, char const *argv[])
{
    func_ptr f = mytest;
    func_ptr1 f1 = mytest;

    f(1, "he");
    f1(10, "hhe");
    (*f1)(20, "hhhe");

    return 0;
}
