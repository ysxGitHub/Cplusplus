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
            cout << i << "������" << endl;
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
    // breakʹ�õ�ʱ��
    // 1. switch�����
    // 2. ѭ������� while, for
    // 3. Ƕ��ѭ������� ÿ�ζ��������ڲ�ѭ���������ѭ��û��Ӱ�졣
    // continue ��������continue����Ĵ��룬��ʼ������һ��ѭ������breakֱ������ѭ��������ѭ����

    goto FLAG;
    cout << "123456" << endl;
    cout << "67890" << endl;
FLAG:
    cout << "09876" << endl;
    cout << "3456" << endl;

    return 0;
}