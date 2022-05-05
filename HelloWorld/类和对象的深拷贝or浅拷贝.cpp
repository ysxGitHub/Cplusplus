#include<iostream>

using namespace std;

class Person
{


public:
    int age;
    int* hight;

    Person()
    {
        cout<<"Person无参构造函数的调用"<<endl;
    }

    Person(int a, int b)
    {
        age = a;
        hight = new int(b);

        cout<<"Person有参构造函数的调用"<<endl;
    }

    Person(const Person &p)
    {
        age = p.age;
        // hight = hight;
        // 如果不利用深拷贝在堆区创建新内存，会导致浅拷贝带来的重复释放堆区问题
        hight = new int(*p.hight);

        cout<<"Person拷贝构造函数的调用"<<endl;
    }


    ~Person()
    {
        if (hight!=NULL)
        {
            delete hight;
            hight=NULL;
        }
        cout<<"Person析构函数的调用"<<endl;
    }

// private:

};

// 浅拷贝：简单的赋值拷贝操作
// 深拷贝：在堆区重新申请空间，进行拷贝操作。
// 如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题->堆区内存重复释放

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
