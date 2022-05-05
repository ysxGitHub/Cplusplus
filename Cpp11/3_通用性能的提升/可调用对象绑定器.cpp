
/*
std::bind用来将可调用对象与其参数一起进行绑定。绑定后的结果可以使用std::function进行保存，
    并延迟调用到任何我们需要的时候。通俗来讲，它主要有两大作用：

    将可调用对象与其参数一起绑定成一个仿函数。

    将多元（参数个数为n，n>1）可调用对象转换为一元或者（n-1）元可调用对象，即只绑定部分参数。
*/

/*
绑定器函数使用语法格式如下：
绑定非类成员函数/变量
    auto f = std::bind(可调用对象地址, 绑定的参数/占位符);
绑定类成员函/变量
    auto f = std::bind(类函数/成员地址, 类实例对象地址, 绑定的参数/占位符);
*/

#include <iostream>
#include <functional>
using namespace std;

void test(int x, int y, const function<void(int x, int y)> &f){
    if(x%2 == 0){
        f(x, y);
    }
}

void output(int x, int y){

    cout << x << " " << y << " " << x+y <<endl;
}

int main(void)
{
    // 使用绑定器绑定可调用对象和参数, 并调用得到的仿函数
    bind(output, 1, 2)();
    bind(output, placeholders::_1, 2)(10);
    bind(output, 2, placeholders::_1)(10);

    // error, 调用时没有第二个参数
    // bind(output, 2, placeholders::_2)(10);
    // 调用时第一个参数10被吞掉了，没有被使用
    bind(output, 2, placeholders::_2)(10, 20);

    bind(output, placeholders::_1, placeholders::_2)(10, 20);
    bind(output, placeholders::_2, placeholders::_1)(10, 20);

    // 绑定器的使用
    for(int i=0; i<9; i++){
        auto f = bind(output, placeholders::_1, placeholders::_2);
        test(i, i+10, f);
    }

    return 0;
}




