#include <iostream>

using namespace std;

int main(void)
{
    int a;
    // switch�� �ж�ֻ�������ͺ��ַ���
    cout << "���������" << endl;
    cin >> a;

    switch (a)
    {
    case 5:
        cout << "����" << endl;
        break;
    case 4:
        cout << "����" << endl;
        break;
    case 3:
        cout << "�е�" << endl;
        break;
    case 2:
        cout << "������" << endl;
        break;
    case 1:
        cout << "��" << endl;
        break;
    default:
        cout << "����" << endl;
        break;
    }

    return 0;
}