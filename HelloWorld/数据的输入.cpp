#include<iostream>
using namespace std;

int main(void)
{
    int a = 10;
    cout<<"给a赋整数"<<endl;
    cin>>a;
    cout<<"a = "<<a<<endl;

    float b = 1.43;
    cout<<"给b赋浮点数"<<endl;
    cin>>b;
    cout<<"b = "<<b<<endl;

    char ch = 'c';
    cout<<"给ch赋字符"<<endl;
    cin>>ch;
    cout<<"ch = "<<ch<<endl;

    char st[] = "qweq";
    cout<<"给st赋字符串"<<endl;
    cin>>st;
    cout<<"st = "<<st<<endl;
    
    bool flag = true;
    cout<<"给flag赋bool值"<<endl;
    cin>>flag;
    cout<<"flag = "<<flag<<endl;

    return 0;
}

