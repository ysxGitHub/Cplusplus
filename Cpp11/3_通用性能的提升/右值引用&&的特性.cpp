// 并不是所有情况下 && 都代表是一个右值引用, 在这两种场景下 && 被称作未定的引用类型
// 1.如果是模板参数需要指定为 T&&，
// 2.如果是自动类型推导需要指定为 auto &&，
template<typename T>
void f(T&& param);

template<typename T>
// const T&& 表示一个右值引用，不是未定引用类型
void f1(const T&& param);

int main(int argc, char const *argv[])
{
    f(10);  // 右值引用
    int x = 10;
    f(x);
    f1(x);  // 右值引用


    int x = 520, y = 1314;
    auto&& v1 = x;
    auto&& v2 = 250; // 右值引用
    decltype(x)&& v3 = y;   // error  // 右值引用


    int&& a1 = 5;   // 右值引用
    int&& aa1 = a1; // error   a1 被传递了 被具名化了, 所有被看成左值
    auto&& bb = a1;
    auto&& bb1 = 5;  // 右值引用

    int a2 = 5;
    int &a3 = a2;
    auto&& cc = a3;
    auto&& cc1 = a2;

    const int& s1 = 100;
    const int&& s2 = 100; // 右值引用
    auto&& dd = s1;
    auto&& ee = s2;

    const auto&& x = 5;



    return 0;
}

/*
通过右值推导 T&& 或者 auto&& 得到的是一个右值引用类型

通过非右值（右值引用、左值、左值引用、常量右值引用、常量左值引用）推导 T&& 或者 auto&& 得到的是一个左值引用类型
*/

