#include <iostream>

using namespace std;

/*
�ڴ����ģ��
c++������ִ��ʱ�����ڴ���򻮷�Ϊ4������
    ����������ź�����Ķ����ƴ��룬�ɲ���ϵͳ���й����
    ȫ���������ȫ�ֱ����;�̬�����Լ�����
    ջ�����ɱ������Զ������ͷţ���ź����Ĳ���ֵ���ֲ�������
    �������ɳ���Ա������ͷţ�������Ա���ͷţ��������ʱ�ɲ���ϵͳ����
�ڴ����������壺
    ��ͬ�����ŵ����ݣ����費ͬ���������ڣ������Ǹ��������̡�
*/

/*
1.1 ��������ǰ
    ��������������exe��ִ�г���δִ�иó���ǰ��Ϊ��������
    ��������
        ���CPUִ�еĻ���ָ��
        �������ǹ���ģ������Ŀ���Ƕ���Ƶ����ִ�еĳ���ֻ��Ҫ���ڴ�����һ�ݴ��뼴��
        ��������ֻ���ģ�ʹ��ֻ����ԭ���Ƿ�ֹ����������޸�������ָ��
    ȫ������
        ȫ�ֱ����;�̬��������ڴˡ�
        ȫ�����������˳��������ַ�����������������Ҳ����ڴˡ�
        ������������ڳ���������ɲ���ϵͳ�ͷš�
    ջ��(stack)��
        �ֲ��������β������Լ��������ص�ַ����ڴ�
        ps����Ҫ���ؾֲ�������ַ��
    ����(heap)��
        ��������ʱ�Ķ�̬�ڴ����
*/

int global_a = 10;
int global_b = 20;

const int global_const_a = 10;
const int global_const_b = 20;

int *func()
{
    // ����new�ؼ��֣����Խ����ݿ��ٵ������� ���ظ��������͵�ָ�롣
    int *p = new int(10);
    return p;
}

int *funclist()
{
    // ����new������
    int *arr = new int[10];
    for(int i=0; i<10; i++)
    {
        arr[i] = i;
    }

    return arr;
}

int main(int argc, char const *argv[])
{
    int local_a = 10;
    int local_b = 20;

    cout << "�ֲ�����a��ַ: " << (long long)&local_a << endl;
    cout << "�ֲ�����b��ַ: " << (long long)&local_b << endl;

    cout << "ȫ�ֱ���a��ַ: " << (long long)&global_a << endl;
    cout << "ȫ�ֱ���b��ַ: " << (long long)&global_b << endl;

    static int static_a = 10;
    static int static_b = 20;

    cout << "��̬����a��ַ: " << (long long)&static_a << endl;
    cout << "��̬����b��ַ: " << (long long)&static_b << endl;

    const int local_const_a = 10;
    const int local_const_b = 20;

    cout << "�ֲ�����a��ַ: " << (long long)&local_const_a << endl;
    cout << "�ֲ�����b��ַ: " << (long long)&local_const_b << endl;

    cout << "ȫ�ֳ���a��ַ: " << (long long)&global_const_a << endl;
    cout << "ȫ�ֳ���b��ַ: " << (long long)&global_const_b << endl;

    string s = "123456";

    cout << "�ַ�������s��ַ: " << (long long)&s << endl;
    cout << "�ַ�������s��ַ: " << (long long)&"123456" << endl;

    int *p = func();
    cout << "new ���ٵĵ�ַ�ڶ���: " << *p << endl;
    // �����������ɳ���Ա�����ٺ��ͷš����ùؼ���delete�����ͷš�
    delete p;

    int*arr = funclist();
    for (int i=0;i<10;i++)
    {
        cout<<arr[i]<<" ";
    }
    //�ͷ�����ʱdelete��[] 
    delete[] arr;

    return 0;
}
