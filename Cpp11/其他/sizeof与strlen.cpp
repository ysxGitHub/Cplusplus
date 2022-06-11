#include <string>
using namespace std;

/*
sizeof是运算符，并不是函数，结果在编译时得到而非运行中获得；strlen是字符处理的库函数。

sizeof参数可以是任何数据的类型或者数据（sizeof参数不退化）；strlen的参数只能是字符指针且结尾是'\0'的字符串。

因为sizeof值在编译时确定，所以不能用来得到动态分配（运行时分配）存储空间的大小。
*/
int main(int argc, char const *argv[])
{
    const char* str = "name";
    sizeof(str); // 取的是指针str的长度，是8
    strlen(str); // 取的是这个字符串的长度，不包含结尾的 \0。大小是4
    return 0;
}
