#include <iostream>
using namespace std;
// 宏常量
#define day 7
// 注意常量是不能进行修改的，变量可以修改，变量不能以‘关键字’进行命名。
int main(void)
{
    int b = 20;
    // 定义的常量
    const int a = 10;
    cout << a + b << endl;
    cout << day << endl;
    return 0;
}
