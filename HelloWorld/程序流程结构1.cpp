#include <iostream>
using namespace std;

int main(void)
{
    int a = 10;
    int b = 20;
    // ѡ��ṹ
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
    // ��Ŀ�����
    int c = 30;
    c = (a > b ? a : b);
    cout << c << endl;
    // c++����Ŀ��������ص��Ǳ��������Խ��и�ֵ
    a > b ? a : b = 100;
    cout << a << endl;
    cout << b << endl;

    float pig1, pig2, pig3;
    cout << "�������һֻС�������" << endl;
    cin >> pig1;
    cout << "������ڶ�ֻС�������" << endl;
    cin >> pig2;
    cout << "���������ֻС�������" << endl;
    cin >> pig3;
    if ((pig1 >= pig2) && (pig1 >= pig3))
    {
        cout << "��һֻС������" << endl;
    }
    else if ((pig2 >= pig1) && (pig2 >= pig3))
    {
        cout << "�ڶ�ֻС������" << endl;
    }
    else if ((pig3 >= pig1) && (pig3 >= pig2))
    {
        cout << "����ֻС������" << endl;
    }

    return 0;
}