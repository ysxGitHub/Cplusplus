#include<iostream>

using namespace std;

class Person
{


public:
    int age;
    int* hight;

    Person()
    {
        cout<<"Person�޲ι��캯���ĵ���"<<endl;
    }

    Person(int a, int b)
    {
        age = a;
        hight = new int(b);

        cout<<"Person�вι��캯���ĵ���"<<endl;
    }

    Person(const Person &p)
    {
        age = p.age;
        // hight = hight;
        // �������������ڶ����������ڴ棬�ᵼ��ǳ�����������ظ��ͷŶ�������
        hight = new int(*p.hight);

        cout<<"Person�������캯���ĵ���"<<endl;
    }


    ~Person()
    {
        if (hight!=NULL)
        {
            delete hight;
            hight=NULL;
        }
        cout<<"Person���������ĵ���"<<endl;
    }

// private:

};

// ǳ�������򵥵ĸ�ֵ��������
// ������ڶ�����������ռ䣬���п���������
// ����������ڶ������ٵģ�һ��Ҫ�Լ��ṩ�������캯������ֹǳ��������������->�����ڴ��ظ��ͷ�

void test()
{
    Person p1(18, 180);

    cout<<p1.age<<" "<<*p1.hight<<endl;

    Person p2(p1);

    cout<<p2.age<<" "<<*p2.hight<<endl;

    return ;
}

int main(int argc, char const *argv[])
{
    test();
    
    return 0;
}
