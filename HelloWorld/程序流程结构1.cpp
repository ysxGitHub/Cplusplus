#include <iostream>
using namespace std;

int main(void)
{
    int a = 10;
    int b = 20;
    // 选择结构
    if (a > b)
    {
        cout << "a>b" << endl;
    }
    else if (a == b)
    {
        cout << "a=b" << endl;
    }
    else
    {
        cout << "a<b" << endl;
    }
    // 三目运算符
    int c = 30;
    c = (a > b ? a : b);
    cout << c << endl;
    // c++中三目运算符返回的是变量，可以进行赋值
    a > b ? a : b = 100;
    cout << a << endl;
    cout << b << endl;

    float pig1, pig2, pig3;
    cout << "请输入第一只小猪的体重" << endl;
    cin >> pig1;
    cout << "请输入第二只小猪的体重" << endl;
    cin >> pig2;
    cout << "请输入第三只小猪的体重" << endl;
    cin >> pig3;
    if ((pig1 >= pig2) && (pig1 >= pig3))
    {
        cout << "第一只小猪最重" << endl;
    }
    else if ((pig2 >= pig1) && (pig2 >= pig3))
    {
        cout << "第二只小猪最重" << endl;
    }
    else if ((pig3 >= pig1) && (pig3 >= pig2))
    {
        cout << "第三只小猪最重" << endl;
    }

    return 0;
}