#include <algorithm>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a = 1;
    // auto f1 = [=] {return a++; };              // error, 按值捕获外部变量, a是只读的
    auto f2 = [=]()mutable {return ++a; };     // ok
    int b = f2();
    cout<<a<<", "<<b<<endl;
    return 0;
}

