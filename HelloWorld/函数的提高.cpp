#include <iostream>

using namespace std;

// ������Ĭ�ϲ���
// ���ĳ��λ����Ĭ�ϲ������Ǵ����λ������Ҫ��Ĭ�ϲ���.
// ������������뺯���Ķ���ֻ������һ����Ĭ�ϲ���.
int func(int a, int b = 2, int c = 3)
{
    return a + b + c;
}

// ռλ���� int, ��������Ĭ�ϲ���
void func2(int a, int = 10)
{
    cout << "ռλ�����ĺ���" << endl;
    return;
}

/*
��������
    �����ú�������ͬ,��߸�����

�������ر������������:
    1.ͬһ����������
    2.����������ͬ
    3.�����������Ͳ�ͬ,���߲���������ͬ,���߲���˳��ͬ

�������ص�ע������:    
    1.�����ķ���ֵ������Ϊ�������ص�����.
    2.������Ϊ���ص�����
    3.������������Ĭ�ϲ���

*/
void func1()
{
    cout << "����func1" << endl;
    return;
}

void func1(int a)
{
    cout << "����func1(int a)" << endl;
    return;
}

void func1(double a)
{
    cout << "����func1(double a)" << endl;
    return;
}

void func1(double a, int b)
{
    cout << "����func1(double a, int b)" << endl;
    return;
}

void func1(int b, double a)
{
    cout << "����func1(int b, double a)" << endl;
    return;
}

void func3(int &a)
{
    cout << "����func3(int &a)" << endl;
    return;
}

void func3(const int &a) //const int &a=10 �൱��int temp = 10; int &a = temp;
{
    cout << "����func3(const int &a)" << endl;
    return;
}

void func4(int a)
{
    cout << "����func4(int a)" << endl;
    return;
}
// ��������ʱ��ò�Ҫ��Ĭ�ϲ���
void func4(int a, int b)
{
    cout << "����func4(int a, int b)" << endl;
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
