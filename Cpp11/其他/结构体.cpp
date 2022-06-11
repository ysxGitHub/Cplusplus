/*
使用<stddef.h>头文件中的，offsetof宏。
*/

#include <iostream>
#include <stddef.h>
using namespace std;

// 如果加上 #pragma pack(4) 指定4字节对齐方式就可以了
// #pragma pack(4)
struct  S
{
	int x;
	char y;
	int z;
	double a;
    double b;
};

// class A{
//     A() = delete;
// };

int main()
{
	cout << offsetof(S, x) << endl; // 0
	cout << offsetof(S, y) << endl; // 4
	cout << offsetof(S, z) << endl; // 8
	cout << offsetof(S, a) << endl; // 16 这里是 16的位置，因为 double是8字节，需要找一个8的倍数对齐，
    cout << offsetof(S, b) << endl;
	return 0;
}
