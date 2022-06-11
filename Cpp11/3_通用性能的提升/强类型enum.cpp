/*
// 匿名枚举
    enum {Red, Green, Blue};
// 有名枚举
    enum Colors{Red, Green, Blue};

在枚举类型中的枚举值编译器会默认从 0 开始赋值，而后依次向下递增，
    也就是说 Red=0，Green=1，Blue=2
*/

/*
C/C++ 的 enum 有个很” 奇怪” 的设定，就是具名（有名字）的enum类型的名字，
    以及 enum 的成员的名字都是全局可见的。
    这与 C++ 中具名的 namespace、class/struct 及 union
    必须通过名字::成员名的方式访问相比是格格不入的，编码过程中一不小心程序员就容易遇到问题。
    比如∶
    enum China {Shanghai, Dongjing, Beijing, Nanjing};
    enum Japan {Dongjing, Daban, Hengbin, Fudao};
    error C2365: “Dongjing”: 重定义；以前的定义是“枚举数”
*/

/*
针对枚举的缺陷，C++11 标准引入了一种新的枚举类型，即枚举类，又称强类型枚举（strong-typed enum）。
    声明强类型枚举非常简单，只需要在 enum 后加上关键字 class。
*/

// 比如∶定义强类型枚举
enum class Types {R, C, S};
// 注意 enum class 的成员没有公有私有之分，也不会使用模板来支持泛化的声明

/*
强类型枚举具有以下几点优势∶

    1.强作用域，强类型枚举成员的名称不会被输出到其父作用域空间。
        强类型枚举只能是有名枚举，如果是匿名枚举会导致枚举值无法使用（因为没有作用域名称）。

    2.转换限制，强类型枚举成员的值不可以与整型隐式地相互转换。

    3.可以指定底层类型。强类型枚举默认的底层类型为 int，但也可以显式地指定底层类型，
    具体方法为在枚举名称后面加上∶type，其中 type 可以是除 wchar_t 以外的任何整型。

wchar_t 是什么？
    双字节类型，或宽字符类型，是 C/C++ 的一种扩展的存储方式，一般为 16 位或 32 位，
        所能表示的字符数远超 char 型。
    主要用在国际化程序的实现中，但它不等同于 unicode 编码。
        unicode 编码的字符一般以 wchar_t 类型存储。
*/
#include <iostream>
using namespace std;

enum class China { Shanghai, Dongjing, Beijing, Nanjing, };
enum class Japan:char { Dongjing, Daban, Hengbin, Fudao };
int main1(){

    // 强类型枚举属于强作用于类型，不能直接使用，枚举值前必须加枚举类型
    int m = Shanghai;           // error

    // 强类型枚举不会进行隐式类型转换，因此枚举值不能直接给 int 行变量赋值
    // （虽然强类型枚举的枚举值默认就是整形，但其不能作为整形使用）。
    int n = China::Shanghai;    // error

    if ((int)China::Beijing >= 2){
    	cout << "ok!" << endl;
    }
    cout << "size1: " << sizeof(China::Dongjing) << endl;
    cout << "size2: " << sizeof(Japan::Dongjing) << endl;
    return 0;
}

// 扩展
/*
原有枚举类型的底层类型在默认情况下，仍然由编译器来具体指定实现。
    但也可以跟强类型枚举类一样，显式地由程序员来指定。
    其指定的方式跟强类型枚举一样，都是枚举名称后面加上∶type，其中 type 可以是除 wchar_t 以外的任何整型。
*/
enum Colors : char { Red, Green, Blue };
/*
关于作用域，在 C++11 中，枚举成员的名字除了会自动输出到父作用域，
    也可以在枚举类型定义的作用域内有效。
*/
int main()
{
    Colors c1 = Green;          // C++11以前的用法
    Colors c2 = Colors::Green;  // C++11的扩展语法
    return 0;
}


