#include <iostream>
#include <functional>
using namespace std;

/*
int a = 1;
auto f1 = [=] {return a++; };              // error, 按值捕获外部变量, a是只读的
auto f2 = [=]()mutable {return ++a; };     // ok
最后再剖析一下为什么通过值拷贝的方式捕获的外部变量是只读的:
    lambda表达式的类型在C++11中会被看做是一个带operator()的类，即仿函数。
    按照C++标准，lambda表达式的operator()默认是const的，一个const成员函数是无法修改成员变量值的。

    mutable 选项的作用就在于取消 operator () 的 const 属性。

    因为 lambda 表达式在 C++ 中会被看做是一个仿函数，
    因此可以使用std::function和std::bind来存储和操作lambda表达式：
*/
int main(void)
{
    // 包装可调用函数
    std::function<int(int)> f1 = [=](int a) {return a; };
    // 绑定可调用函数
    std::function<int(int)> f2 = bind([&](int a) {return a; }, placeholders::_1);

    // 函数调用
    cout << f1(100) << endl;
    cout << f2(200) << endl;
    return 0;
}


// 对于没有捕获任何变量的 lambda 表达式，还可以转换成一个普通的函数指针：
using func_ptr = int(*)(int);
// 没有捕获任何外部变量的匿名函数
func_ptr f = [](int a) {
    return a;
};
void main1(void){
    // 函数调用
    f(1314);
}


