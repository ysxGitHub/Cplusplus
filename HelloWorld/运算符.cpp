#include<iostream>
using namespace std;


int main(void)
{
    // 两个整数的除法结果仍然是整数
    int a = 1;
    float b = 2.5;
    cout<<a*b<<endl;
    cout<<b/a<<endl;
    cout<<a+b<<endl;
    cout<<a-b<<endl;

    //取余只能是整数 
    cout<<"取余"<<endl;
    int a1 = 2;
    int b1 = 5;
    cout<<b1%a1<<endl;

    /*
    后置递增与递减，先计算表达式，再加一或减一
    a++  a+=1
    a--  a-=1
    前置递增与递减，先加一或减一，再计算表达式
    --a  a-=1
    ++a  a+=1
    */
    cout<<"递增与递减"<<endl;
    cout<<--a*10<<endl;
    cout<<a++*10<<endl;
    cout<<++b*10<<endl;
    cout<<b--*10<<endl;
    cout<<a<<endl;
    cout<<b<<endl;

    // 赋值运算符
    cout<<"赋值运算符"<<endl;
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

    // 比较运算符
    cout<<"比较运算符"<<endl;
    cout<<(a==b)<<endl;
    cout<<(a!=b)<<endl;
    cout<<(a>=b)<<endl;
    cout<<(a<=b)<<endl;
    
    /*
    逻辑运算符
    在c++中除了0都是真
    逻辑非  !
    逻辑与  &&
    逻辑或  ||
    */ 
    int a2 = 0;
    int b2 = 20;
    cout<<"逻辑运算符"<<endl;
    cout<<!a2<<endl;
    cout<<(a2&&b2)<<endl;
    cout<<(a2||b2)<<endl;


    return 0;
}