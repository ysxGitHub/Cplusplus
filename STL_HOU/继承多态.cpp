#include<iostream>
using namespace std;



class A
{
public:
    void print()
    {
        cout<<"A"<<endl;
    }

    void countplus()
    {
        numplus();
    };

    virtual void numplus(){};
};

class B : public A
{
public:
    void numplus()
    {
        cout<<"B++"<<endl;
    }

    void print()
    {
        cout<<"B"<<endl;
    }
    

};

int main(int argc, char const *argv[])
{
    B b1;
    b1.countplus();

    A *a1 = new B;
    a1->print();
    // a1->numplus();
    return 0;
}

