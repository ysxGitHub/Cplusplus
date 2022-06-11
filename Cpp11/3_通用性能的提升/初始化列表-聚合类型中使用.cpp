#include <iostream>
#include <string>
using namespace std;

// 普通数组本身可以看做是一个聚合类型

int x[] = {1,2,3,4,5,6};
double y[3][3] = {
    {1.23, 2.34, 3.45},
    {4.56, 5.67, 6.78},
    {7.89, 8.91, 9.99},
};
char carry[] = {'a', 'b', 'c', 'd', 'e', 'f'};
string sarry[] = {"hello", "world", "nihao", "shijie"};

/*
满足以下条件的类（class、struct、union）可以被看做是一个聚合类型：

    无用户自定义的构造函数。

    无私有或保护的非静态数据成员。

    无基类。

    无虚函数。
*/

// 场景 1: 类中有私有成员，无法使用列表初始化进行初始化
struct T1 {
    int x;
    long y;
protected:
    int z;
}t{ 1, 100, 2};		// error, 类中有私有成员, 无法使用初始化列表初始化

// 场景 2：类中有非静态成员可以通过列表初始化进行初始化，但它不能初始化静态成员变量。
struct T2 {
    int x;
    long y;
protected:
    static int z;
}t{ 1, 100, 2};		// error

struct T2{
    int x;
    long y;
protected:
    static int z;
}t1{ 1, 100 };		// ok
// 静态成员的初始化
int T2::z = 2;

/*
类中不能有使用 {} 和 = 直接初始化的非静态数据成员（从 c++14 开始就支持了）。
*/
struct T3 {
    int x;
    double y = 1.34;
    int z[3]{1,2,3};
};

int main(void)
{
    T3 t{520, 13.14, {6,7,8}};		// error, c++11不支持,从c++14开始就支持了
    return 0;
}
