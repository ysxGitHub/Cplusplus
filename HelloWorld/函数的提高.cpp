#include <iostream>

using namespace std;

// 函数的默认参数
// 如果某个位置有默认参数，那从这个位置往后都要有默认参数.
// 如果函数声明与函数的定义只能其中一个有默认参数.
int func(int a, int b = 2, int c = 3)
{
    return a + b + c;
}

// 占位参数 int, 还可以有默认参数
void func2(int a, int = 10)
{
    cout << "占位参数的函数" << endl;
    return;
}

/*
函数重载
    可以让函数名相同,提高复用性

函数重载必须满足的条件:
    1.同一个作用域下
    2.函数名称相同
    3.函数参数类型不同,或者参数个数不同,或者参数顺序不同

函数重载的注意事项:    
    1.函数的返回值不能作为函数重载的条件.
    2.引用作为重载的条件
    3.函数重载碰到默认参数

*/
void func1()
{
    cout << "调用func1" << endl;
    return;
}

void func1(int a)
{
    cout << "调用func1(int a)" << endl;
    return;
}

void func1(double a)
{
    cout << "调用func1(double a)" << endl;
    return;
}

void func1(double a, int b)
{
    cout << "调用func1(double a, int b)" << endl;
    return;
}

void func1(int b, double a)
{
    cout << "调用func1(int b, double a)" << endl;
    return;
}

void func3(int &a)
{
    cout << "调用func3(int &a)" << endl;
    return;
}

void func3(const int &a) //const int &a=10 相当于int temp = 10; int &a = temp;
{
    cout << "调用func3(const int &a)" << endl;
    return;
}

void func4(int a)
{
    cout << "调用func4(int a)" << endl;
    return;
}
// 函数重载时最好不要有默认参数
void func4(int a, int b)
{
    cout << "调用func4(int a, int b)" << endl;
    return;
}

int main(int argc, char const *argv[])
{

    int sumabc = func(3);

    func2(10);

    cout << sumabc << endl;

    func1();
    func1(1);
    func1(1.1);
    func1(1, 3.4);
    func1(3.4, 1);

    int a = 10;
    func3(a);
    func3(10);
    func4(20);

    return 0;
}
