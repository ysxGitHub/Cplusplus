#include <iostream>
using namespace std;

int main(void)
{
    int score[10];
    // �����ʼ������ʱ��û��ȫ����д�꣬����0����
    int score1[10] = {1, 2, 3, 4, 5};
    int score2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    cout << score1[6] << endl;
    // �������ĳ���
    cout << sizeof(score1) / sizeof(score1[0]) << endl;
    // �������ĵ�ַ
    cout << score << endl;
    // ȡַ&
    cout << &score[0] << endl;
    cout << &score[1] << endl;
    // ��������һ�������������Խ��и�ֵ����

    int arr[5] = {300, 350, 200, 400, 250};
    int max_weight = 0;
    int max_i = 0;
    for (int i = 0; i < 5; i++)
    {
        if (max_weight <= arr[i])
        {
            max_weight = arr[i];
            max_i = i;
        }
    }
    cout << "���ص�С���ǣ�" << max_i + 1 << endl;

    int arr1[5] = {1, 2, 3, 4, 5};
    int start = 0;
    int end = sizeof(arr1) / sizeof(arr1[0]) - 1;


    while (start < end)
    {
        int temp = arr1[start];
        arr1[start] = arr1[end];
        arr1[end] = temp;
        start++;
        end--;
    }

    cout<<"�������ã�";
    for (int i = 0; i < 5; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;

    return 0;
}
