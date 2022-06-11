/*
为了能够正确的在C++代码中调用C语言的代码：在程序中加上extern "C"后，相当于告诉编译器这部分代码是C语言写的，因此要按照C语言进行编译，而不是C++；

哪些情况下使用extern "C"：

（1）C++代码中调用C语言代码；

（2）在C++中的头文件中使用；

（3）在多个人协同开发时，可能有人擅长C语言，而有人擅长C++；

使用extern "C"全部都放在于cpp程序相关文件或其头文件中。
*/

#ifndef __EXTERN_C_H__
#define __EXTERN_C_H__

extern "C"{
    typedef unsigned int result_t;
    typedef void* my_handle_t;

    my_handle_t create_handle(const char* name);
    result_t operate_on_handle(my_handle_t handle);
    void close_handle(my_handle_t handle);
}

#endif

/*
（1）C++调用C函数：
    //xx.h
    extern int add(...)

    //xx.c
    int add(){

    }

    //xx.cpp
    extern "C" {
        #include "xx.h"
    }

（2）C调用C++函数
    //xx.h
    extern "C"{
        int add();
    }
    //xx.cpp
    int add(){
    }
    //xx.c
    extern int add();
*/