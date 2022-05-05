

// lambda 表达式定义了一个匿名函数，并且可以捕获一定范围内的变量。lambda 表达式的语法形式简单归纳如下：
// [capture](params) opt -> ret {body;};

/*
lambda 表达式的 [capture] 捕获列表可以捕获一定范围内的变量，具体使用方式如下：
    [] - 不捕捉任何变量
    [&] - 捕获外部作用域中所有变量，并作为引用在函数体内使用 (按引用捕获)
    [=] - 捕获外部作用域中所有变量，并作为副本在函数体内使用 (按值捕获)
        拷贝的副本在匿名函数体内部是 只读 的
    [=, &foo] - 按值捕获外部作用域中所有变量，并按照引用捕获外部变量 foo
    [bar] - 按值捕获 bar 变量，同时不捕获其他变量
    [&bar] - 按引用捕获 bar 变量，同时不捕获其他变量
    [this] - 捕获当前类中的 this 指针
        让 lambda 表达式拥有和当前类成员函数同样的访问权限
        如果已经使用了 & 或者 =, 默认添加此选项
*/

#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Test
{
public:
    void output(int x, int y)
    {
        auto x1 = [] {return m_number; };                      // error
        auto x2 = [=] {return m_number + x + y; };             // ok
        auto x3 = [&] {return m_number + x + y; };             // ok
        auto x4 = [this] {return m_number; };                  // ok
        auto x5 = [this] {return m_number + x + y; };          // error
        auto x6 = [this, x, y] {return m_number + x + y; };    // ok
        auto x7 = [this] {return m_number++; };                // ok
    }
    int m_number = 100;
};

void func(int x, int y){
    int a = 7;
    int b = 9;
    // mutable 使 a, b 在下面的函数中可以进行改动了
    [=, &x](int z) mutable{
        int c = a;
        int d = x;
        b++;
        cout<<"b: "<<b<<endl;
    } (11) ;
    cout<<"b: "<<b<<endl;
}


// 完整的lambda表达式定义
auto f = [](int a) -> int
{
    return a+10;
};

// 忽略返回值的lambda表达式定义
auto f = [](int a){
    return a+10;
};

// ok，可以自动推导出返回值类型
auto f = [](int i){
    return i;
}

// error，不能推导出返回值类型
auto f1 = []()
{
    return {1, 2};	// 基于列表初始化推导返回值，错误
}


