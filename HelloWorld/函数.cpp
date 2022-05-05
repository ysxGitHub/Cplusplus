#include <iostream>
#include "quick_sort.cpp"

using namespace std;



// ���庯��ʱ������Ϊ��ʽ����
int add_sum(int a, int b)
{
    return a + b;
}

void swap(int a, int b)
{
    cout << "�βν���ǰ ";
    cout << " a: " << a;
    cout << " b: " << b << endl;

    int temp = a;
    a = b;
    b = temp;

    cout << "�βν����� ";
    cout << " a: " << a;
    cout << " b: " << b << endl;

    return;
}

// �������������ж�Σ����Ƕ���ֻ����һ��
int max(int a, int b);

int main(int argc, char const *argv[])
{
    int a = 3;
    int b = 4;
    int c;

    // ���ú���ʱ���������ʵ�ʲ�����ʵ�ε�ֵ�ᴫ�ݸ��β�
    c = add_sum(a, b);
    cout << c << endl;

    cout << "ʵ�ν���ǰ ";
    cout << " a: " << a;
    cout << " b: " << b << endl;
    // ��������ֵ���ݵ�ʱ�򣬺������βη����仯��������Ӱ��ʵ��
    swap(a, b);

    cout << "ʵ�ν����� ";
    cout << " a: " << a;
    cout << " b: " << b << endl;

    cout << max(a, b) << endl;

    int d[] = {3, 4, 5, 12, 46, 7, 87, 34, 9, 36, 77, 23, 24, 13, 56, 69, 79, 11, 1};
    int end = sizeof(d) / sizeof(d[0]) - 1;
    cout << end << endl;

    quick_sort(d, 0, end);

    for (int i = 0; i < end; i++)
    {
        cout << d[i] << " ";
    }

    return 0;
}

int max(int a, int b)
{
    return a > b ? a : b;
}
