#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{

    int a = 10;

    // 定义指针
    int *p;
    // 让指针记录变量的地址
    p = &a;

    cout << p << " " << a << endl;
    *p = 100;
    cout << p << " " << a << endl;

    // 在32位操作系统下不论什么类型的指针都占4个字节，64位指针占8个字节
    cout << sizeof(p) << endl;
    cout << sizeof(int *) << endl;
    cout << sizeof(char *) << endl;
    cout << sizeof(float *) << endl;
    cout << sizeof(double *) << endl;

    // 空指针, 用于给指针变量进行初始化，是不可以访问的
    int *q = NULL;
    // *q = 100;
    // cout<<*q<<endl;

    // 野指针, 注意避免
    // int *x = (int *)0x1100;
    // cout << *p << endl;

    // const修饰指针: 常量指针, 指针的指向可以修改，指针指向的值不能修改。
    int b = 100;
    int c = 200;
    const int* p1 = &b;
    // *p1 = 200;  错误
    // p1 = &c;  正确

    // 指针修饰const: 指针常量，指针的指向不可以修改，指针指向的值可以修改。
    int* const p2 = &b;
    // *p1 = 200;  正确
    // p1 = &c;  错误

    // 指针的指向不可以修改，指针指向的值不可以修改。
    const int* const p3 = &b;
    

    return 0;
}
