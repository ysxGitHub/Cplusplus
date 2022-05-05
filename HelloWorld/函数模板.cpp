#include<iostream>
using namespace std;

/*
C++另一种编程思想为泛型编程，主要利用的技术就是模板
模板分为：
    函数模板和类模板

函数模板：
    语法：template<typename T>
    函数声明
template--声明创建模板
typename--表明其后面的符号是一种数据类型，可以用class代替 
T--通用的数据类型，名称可以替换，通常为大写字母
    注意：T的数据类型要一致，
        T的数据类型要确定

普通函数与函数模板的区别：
    普通函数调用可以发生隐式转换
    函数模板用自动类型推导不可以发生隐式类型转换
    函数模板用显示指定类型可以发生隐式类型转换

普通函数和函数模板调用规则：
    1.如果函数模板和普通函数都存在，优先调用普通函数
    2.可以通过 空模板参数列表 强制调用函数模板
    3.函数模板也可以发生函数重载
    4.如果函数模板可以产生更好的匹配，优先调用函数模板

模板的局限性：
    有些特定的数据类型，需要用具体化方式做特殊化实现

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
    cout<<"普通函数"<<endl;
}
template<class T>
void myPrint(T a, T b)
{
    cout<<"函数模板"<<endl;
}

template<class T>
void myPrint(T a, T b, T c)
{
    cout<<"函数模板1"<<endl;
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
    // 函数模板：
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

    // 普通函数与函数模板的区别：
    cout<<mySum(a,b)<<endl;
    cout<<mySum(ch,sh)<<endl;

    cout<<mySumT(a,b)<<endl;
    // cout<<mySumT(ch,sh)<<endl; //不行
    cout<<mySumT<int>(a,b)<<endl;
    cout<<mySumT<int>(ch,sh)<<endl;

    // 普通函数和函数模板调用规则：
    myPrint(a,b);
    myPrint<>(a,b);
    myPrint<>(a,b,30);
    myPrint(ch,sh);

    // 模板的局限性：
    Person p1(10, "tom");
    Person p2(10, "tom");
    cout<<myCompare(p1,p2)<<endl;

    return 0;
}







