/*
大端存储：字数据的高字节存储在低地址中

小端存储：字数据的低字节存储在低地址中

所以在Socket编程中，往往需要将操作系统所用的小端存储的IP地址转换为大端存储，这样才能进行网络传输
*/

#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    int a = 0x1234;
    //由于int和char的长度不同，借助int型转换成char型，只会留下低地址的部分
    char c = (char)(a);
    if (c == 0x12)
        cout << "big endian" << endl;
    else if(c == 0x34)
        cout << "little endian" << endl;

    //swap 1
    int x = 2, y = 1;
    x += y;
    y = x-y;
    x -= y;
    cout<<"x: "<<x<<", y: "<<y<<endl;

    //swap 2
    x ^= y ^= x ^= y; // 只能对int,char..
    cout<<"x: "<<x<<", y: "<<y<<endl;
    return 0;
}
