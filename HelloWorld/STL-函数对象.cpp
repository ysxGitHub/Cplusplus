#include<iostream>
using namespace std;

/*
函数对象（仿函数）
1.函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
2.函数对象超出普通函数的概率，函数对象可以有自己的状态
3.函数对象可以作为参数进行传递
*/ 

// 1.函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
class myAdd
{
public:
    int operator()(int a, int b)
    {
        return a+b;
    }

};

// 2.函数对象超出普通函数的概率，函数对象可以有自己的状态
class myPrint
{
public:
    myPrint()
    {
        this->count=0;
    }
    void operator()(string str)
    {
        this->count++;
        cout<<str<<endl;
    }
    int count;
};

// 3.函数对象可以作为参数进行传递
class doPrint
{
public:

    void operator()(string str)
    {
        cout<<str<<endl;
    }
};

// 类似装饰器
void printd(doPrint&dp, string test)
{
    dp(test);
}

int main(int argc, char const *argv[])
{
    myAdd add;
    cout<<add(10, 10)<<endl;

    // 记录调用了几次，自己的状态
    myPrint print;
    print("hellooooo");
    print("hellooooo");
    print("hellooooo");
    cout<<print.count<<endl;

    doPrint dp;
    printd(dp, "worlddddd");

    return 0;
}

