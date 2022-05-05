#include <iostream>
#include "quick_sort.cpp"

using namespace std;



// 定义函数时，参数为形式参数
int add_sum(int a, int b)
{
    return a + b;
}

void swap(int a, int b)
{
    cout << "形参交换前 ";
    cout << " a: " << a;
    cout << " b: " << b << endl;

    int temp = a;
    a = b;
    b = temp;

    cout << "形参交换后 ";
    cout << " a: " << a;
    cout << " b: " << b << endl;

    return;
}

// 函数声明可以有多次，但是定义只能有一次
int max(int a, int b);

int main(int argc, char const *argv[])
{
    int a = 3;
    int b = 4;
    int c;

    // 调用函数时，传入的是实际参数，实参的值会传递给形参
    c = add_sum(a, b);
    cout << c << endl;

    cout << "实参交换前 ";
    cout << " a: " << a;
    cout << " b: " << b << endl;
    // 当我们做值传递的时候，函数的形参发生变化，并不会影响实参
    swap(a, b);

    cout << "实参交换后 ";
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
