/*
虚拟继承解决菱形继承问题

虚继承的作用是减少了对基类的重复，代价是增加了虚表指针的负担（增加了更多的需指针）
 */


#include <iostream>
using namespace std;

class A{};
class B : virtual public A{};
class C : virtual public A{};
class D : public B, public C{};

int main()
{
    cout << "sizeof(A): " << sizeof(A) <<endl; // 1，空对象，只有一个占位
    cout << "sizeof(B): " << sizeof(B) <<endl; // 4，一个bptr指针，省去占位,不需要对齐
    cout << "sizeof(C): " << sizeof(C) <<endl; // 4，一个bptr指针，省去占位,不需要对齐
    cout << "sizeof(D): " << sizeof(D) <<endl; // 8，两个bptr，省去占位,不需要对齐
}