#include<iostream>
using namespace std;

/*
C++��һ�ֱ��˼��Ϊ���ͱ�̣���Ҫ���õļ�������ģ��
ģ���Ϊ��
    ����ģ�����ģ��

����ģ�壺
    �﷨��template<typename T>
    ��������
template--��������ģ��
typename--���������ķ�����һ���������ͣ�������class���� 
T--ͨ�õ��������ͣ����ƿ����滻��ͨ��Ϊ��д��ĸ
    ע�⣺T����������Ҫһ�£�
        T����������Ҫȷ��

��ͨ�����뺯��ģ�������
    ��ͨ�������ÿ��Է�����ʽת��
    ����ģ�����Զ������Ƶ������Է�����ʽ����ת��
    ����ģ������ʾָ�����Ϳ��Է�����ʽ����ת��

��ͨ�����ͺ���ģ����ù���
    1.�������ģ�����ͨ���������ڣ����ȵ�����ͨ����
    2.����ͨ�� ��ģ������б� ǿ�Ƶ��ú���ģ��
    3.����ģ��Ҳ���Է�����������
    4.�������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��

ģ��ľ����ԣ�
    ��Щ�ض����������ͣ���Ҫ�þ��廯��ʽ�����⻯ʵ��

*/ 

// template<typename T>
template<class T>
void mySwape(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template<class T>
void mySort(T &arr, int len)
{
    for(int i=0; i<len; i++)
    {
        int maxindex = i;
        for(int j=i+1; j<len; j++)
        {
            if(arr[maxindex]<arr[j])
            {
                maxindex = j;
            }
        }
        if(maxindex!=i)
        {
            mySwape(arr[maxindex],arr[i]);
        }
    }

}

int mySum(int a, int b)
{
    return a+b;
}

template<class T>
T mySumT(T a, T b)
{
    return a+b;
}

void myPrint(int a, int b)
{
    cout<<"��ͨ����"<<endl;
}
template<class T>
void myPrint(T a, T b)
{
    cout<<"����ģ��"<<endl;
}

template<class T>
void myPrint(T a, T b, T c)
{
    cout<<"����ģ��1"<<endl;
}

class Person
{
public:
    Person(int num, string name)
    {
        this->name = name;
        this->num = num;
    }
    int num;
    string name;
};


template<class T>
bool myCompare(T &a, T &b)
{
    if(a==b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<> bool myCompare(Person &a, Person &b)
{
    if(a.name==b.name&&a.num==b.num)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, char const *argv[])
{
    // ����ģ�壺
    int a=10;
    int b=20;
    mySwape(a, b);
    cout<<a<<"\t"<<b<<endl;

    char ch='a';
    char sh='b';
    mySwape<char>(ch,sh);
    cout<<ch<<"\t"<<sh<<endl;

    char str1[] = "abcdefg";
    mySort(str1, (int)(sizeof(str1)/sizeof(str1[0])));
    cout<<str1<<endl;

    int arr[] = {1,2,3,4,5,6,7};
    int len = sizeof(arr)/sizeof(arr[0]);
    mySort(arr, len);
    for (int i=0;i<len;i++)
    {
        cout<<arr[i];
    }
    cout<<endl;

    // ��ͨ�����뺯��ģ�������
    cout<<mySum(a,b)<<endl;
    cout<<mySum(ch,sh)<<endl;

    cout<<mySumT(a,b)<<endl;
    // cout<<mySumT(ch,sh)<<endl; //����
    cout<<mySumT<int>(a,b)<<endl;
    cout<<mySumT<int>(ch,sh)<<endl;

    // ��ͨ�����ͺ���ģ����ù���
    myPrint(a,b);
    myPrint<>(a,b);
    myPrint<>(a,b,30);
    myPrint(ch,sh);

    // ģ��ľ����ԣ�
    Person p1(10, "tom");
    Person p2(10, "tom");
    cout<<myCompare(p1,p2)<<endl;

    return 0;
}







