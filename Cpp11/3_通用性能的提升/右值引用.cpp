/*
lvalue 是 loactor value 的缩写，rvalue 是 read value 的缩写
    左值是指存储在内存中、有明确存储地址（可取地址）的数据；
    右值是指可以提供数据值的数据（不可取地址）；
*/

// 左值
int num = 9;
// 左值引用
int& a = num;
// 右值

// 右值引用
int && b = 1;

// 常量右值引用
const int && c = 6;

// 常量左值引用
const int & d = num;

const int & e = a;
const int & f = b;
const int & g = c;

const int && j = a;
const int && h = b;
const int && i = d;


#include <iostream>
using namespace std;

int&& value = 520;
class Test
{
public:
    Test()
    {
        cout << "construct: my name is jerry" << endl;
    }
    Test(const Test& a)
    {
        cout << "copy construct: my name is tom" << endl;
    }
};

Test getObj()
{
    return Test();
}

int main()
{
    int a1;
    int &&a2 = a1;        // error
    Test& t = getObj();   // error
    Test && t = getObj();
    const Test& t = getObj();
/*
const Test& t = getObj() 这句代码的语法是正确的，

常量左值引用是一个万能引用类型，它可以接受左值、右值、常量左值和常量右值。
*/
    return 0;
}