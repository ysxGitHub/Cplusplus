#include <iostream>
#include "head.h"

int main(int argc, char const *argv[])
{
    int a = 10;
    int b = 20;
    std::cout<<"a = "<<a<<", b = "<<b<<std::endl;
    std::cout<<"a + b = "<<add1(a, b)<<std::endl;
    std::cout<<"a - b = "<<sub1(a, b)<<std::endl;
    std::cout<<"a * b = "<<mult1(a, b)<<std::endl;
    std::cout<<"a - b = "<<div1(a, b)<<std::endl;
    return 0;
}

// 编译步骤
//1. cd .\build\
//2. cmake ..
//3. mingw32-make.exe
//4. .\algorithm.exe

