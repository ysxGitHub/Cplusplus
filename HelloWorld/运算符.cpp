#include<iostream>
using namespace std;


int main(void)
{
    // ���������ĳ��������Ȼ������
    int a = 1;
    float b = 2.5;
    cout<<a*b<<endl;
    cout<<b/a<<endl;
    cout<<a+b<<endl;
    cout<<a-b<<endl;

    //ȡ��ֻ�������� 
    cout<<"ȡ��"<<endl;
    int a1 = 2;
    int b1 = 5;
    cout<<b1%a1<<endl;

    /*
    ���õ�����ݼ����ȼ�����ʽ���ټ�һ���һ
    a++  a+=1
    a--  a-=1
    ǰ�õ�����ݼ����ȼ�һ���һ���ټ�����ʽ
    --a  a-=1
    ++a  a+=1
    */
    cout<<"������ݼ�"<<endl;
    cout<<--a*10<<endl;
    cout<<a++*10<<endl;
    cout<<++b*10<<endl;
    cout<<b--*10<<endl;
    cout<<a<<endl;
    cout<<b<<endl;

    // ��ֵ�����
    cout<<"��ֵ�����"<<endl;
    a1 /= 10;
    cout<<a1<<endl;
    a1 *= 5;
    cout<<a1<<endl;
    a1 += 2;
    cout<<a1<<endl;
    a1 -= 3;
    cout<<a1<<endl;
    a1 %= -1;
    cout<<a1<<endl;

    // �Ƚ������
    cout<<"�Ƚ������"<<endl;
    cout<<(a==b)<<endl;
    cout<<(a!=b)<<endl;
    cout<<(a>=b)<<endl;
    cout<<(a<=b)<<endl;
    
    /*
    �߼������
    ��c++�г���0������
    �߼���  !
    �߼���  &&
    �߼���  ||
    */ 
    int a2 = 0;
    int b2 = 20;
    cout<<"�߼������"<<endl;
    cout<<!a2<<endl;
    cout<<(a2&&b2)<<endl;
    cout<<(a2||b2)<<endl;


    return 0;
}