/*
右值引用类型是独立于值的，一个右值引用作为函数参数的形参时，在函数内部转发该参数给内部其他函数时，
    它就变成一个左值，并不是原来的类型了。如果需要按照参数原来的类型转发到另一个函数，
    可以使用 C++11 提供的 std::forward () 函数，该函数实现的功能称之为完美转发。
*/

// std::forward<T>(t);
// 当T为左值引用类型时，t将被转换为T类型的左值
// 当T不是左值引用类型时，t将被转换为T类型的右值

#include <iostream>
using namespace std;

template<typename T>
void printValue(T& t)
{
    cout << "l-value: " << t << endl;
}

template<typename T>
void printValue(T&& t)
{
    cout << "r-value: " << t << endl;
}

template<typename T>
void testForward(T && v)
{
    printValue(v);
    printValue(move(v));
    printValue(forward<T>(v));
    cout << endl;
}

int main()
{
    testForward(520);
    int num = 1314;
    testForward(num);
    testForward(forward<int>(num)); // int 不是左值引用 num 会被转发为右值
    testForward(forward<int&>(num));
    testForward(forward<int&&>(num));

    return 0;
}
