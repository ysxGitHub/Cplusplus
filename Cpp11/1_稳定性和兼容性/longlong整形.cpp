// C++11 标准要求 long long 整型可以在不同平台上有不同的长度，但至少有64位。

long long num1 = 1238618276ll;
long long num2 = 1283781299LL;

unsigned long long num3 = 29187349278ull;
unsigned long long num4 = 24979283839ULL;

/*
对于有符号类型的 long long 和以下三种类型等价

    long long int
    signed long long
    signed long long int
*/

/*
要了解平台上 long long 大小的方法就是查看 <climits>（或 <limits. h> ）中的宏与 long long
    整型相关的一共有 3 个：

    LLONG_MIN - 最小的 long long 值
    LLONG_MAX - 最大的 long long 值
    ULLONG MAX - 最大的 unsigned long long 值
*/

/*
在 C++11 中一共只定义了以下 5 种标准的有符号整型：

    signed char
    short int
    int
    long int
    long long int
*/

/*
当我们在 C++ 中处理数据的时候，如果参与运算的数据或者传递的参数类型不匹配，整型间会发生隐式的转换，
    这种过程通常被称为整型的提升。比如如下表达式∶
    (int)num1 + (long long)num2
*/

/*
关于这种整形提升的隐式转换遵循如下原则:
    长度越大的整型等级越高，比如 long long int 的等级会高于 int。

    长度相同的情况下，标准整型的等级高于扩展类型，比如 long long int 和 int64
        如果都是 64 位长度，则 long long int 类型的等级更高。

    相同大小的有符号类型和无符号类型的等级相同，long long int 和 unsigned long long int
        的等级就相同。

    转换过程中，低等级整型需要转换为高等级整型，有符号的需要转换为无符号整形。
*/

