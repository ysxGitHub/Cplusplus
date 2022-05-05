#include "complex.h"
using namespace std;

/*
1.数据在private中
2.参数尽量用引用
3.const看情况加
4.返回尽量用引用

const加在成员函数后面, 全局函数后面不加, 
const可以作为函数重载的条件
const obj只能调用const成员函数
non-const obj只能调用non-const成员函数
*/

// "<<"号重载只能在类外实现
template <class T>
ostream &operator<<(ostream &os, const Complex<T> &x)
{
    return os << "(" << x.real() << ", " << x.imag() << ")";
}

template <class T>
Complex<T> &__doapl(Complex<T> *ths, const Complex<T> &r)
{
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

template <class T>
Complex<T> &Complex<T>::operator+=(const Complex<T> &r)
{
    return __doapl(this, r);
}

// 函数中的局部变量不能返回引用
template <class T>
Complex<T> operator+(const Complex<T> &x, const Complex<T> &y)
{
    return Complex<T>(x.real() + y.real(), x.imag() + y.imag());
}

template <class T>
Complex<T> &Complex<T>::operator=(const Complex<T> &r)
{
    this->re = r.re;
    this->im = r.im;
    return *this;
}

int main(int argc, char const *argv[])
{
    // 相同class的各个objects互为friends(友元)

    cout << "hello world!" << endl;
    Complex<int> c;
    cout << c << endl;

    Complex<int> c1(2, 2);
    cout << c1 << endl;

    c += c1;
    cout << c << endl;

    c = c + c1;
    cout << c << endl;

    // 临时（匿名）对象
    Complex<int>();
    Complex<int>(4,5);

    system("pause");
    return 0;
}
