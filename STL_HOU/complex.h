/*
防卫式声明的作用是：防止由于同一个头文件被包含多次，而导致了重复定义。
#ifndef 依赖于宏定义名，当宏已经定义时，#endif之前的代码就会被忽略，但是这里需要注意宏命名重名的问题；
#pragma once 只能保证同一个文件不会被编译多次，但是当两个不同的文件内容相同时，仍然会出错。
            而且这是微软提供的编译器命令，当代码需要跨平台时，需要使用宏定义方式。

只是千万不要在头文件里面using namesoace std; 防止命名空间污染

*/ 

#ifndef __COMPLEX__
#define __COMPLEX__

#include <iostream>


template<class T> class Complex;
// 当实例化失败的时候，需要使用前向声明友元函数
template<class T> Complex<T>& __doapl(Complex<T>*, const Complex<T>&);

template<class T>
class Complex
{
public:
    Complex(T r, T i):re(r),im(i) {}
    // 重载
    Complex():re(0),im(0) {}

    // 重载
    Complex<T> & operator +=(const Complex<T>&);
    Complex<T> & operator =(const Complex<T>&);

    // 只读模式 const
    T real() const
    {
        return this->re;
    }
    // 重载
    void real(T r)
    {
        this->re = r;
    }
    
    T imag() const
    {
        return this->im;
    }
     

private:
    T re, im;

    friend Complex<T>& __doapl<T>(Complex<T>*, const Complex<T>&);

};

#endif
