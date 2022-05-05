#include <iostream>
using namespace std;

int main(void)
{
    for (int i = 0; i < 10; i++)
    {
        cout << i << endl;
    }

    for (int i = 1; i <= 100; i++)
    {
        if ((i % 10 == 7) || (i / 10 == 7) || (i % 7 == 0))
        {
            cout << i << "敲桌子" << endl;
        }
    }

    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << "x" << j << "=" << i * j << ' ';
        }
        cout << endl;
    }
    // break使用的时机
    // 1. switch语句中
    // 2. 循环语句中 while, for
    // 3. 嵌套循环语句中 每次都会跳出内部循环，对外层循环没有影响。
    // continue 跳过本次continue下面的代码，开始进行下一次循环。而break直接跳出循环，不再循环。

    goto FLAG;
    cout << "123456" << endl;
    cout << "67890" << endl;
FLAG:
    cout << "09876" << endl;
    cout << "3456" << endl;

    return 0;
}