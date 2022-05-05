#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbletSort(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            int temp = 0;
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int a = 10;
    int b = 20;

    cout << a << " " << b << endl;
    // 地址传递会修改实参，而值传递不会修改实参。
    swap(&a, &b);

    cout << a << " " << b << endl;

    int arr[] = {3, 4, 1, 2, 7, 6, 5, 9, 10, 8};

    int lengths = sizeof(arr) / sizeof(arr[0]);

    bubbletSort(arr, lengths);

    for (int i = 0; i < lengths; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
