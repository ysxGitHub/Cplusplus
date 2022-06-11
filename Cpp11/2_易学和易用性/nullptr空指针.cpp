#include<iostream>
#include<string>
using namespace std;


void func1(char* p) {
    cout<<"func1 char"<<endl;
}
void func1(int p) {
    cout<<"func1 int"<<endl;
}


int main(int argc, char const *argv[]) {
    // nullptr 会自动转换为各种类型的指针, 可以隐式匹配指针类型, 解决函数重载时会遇到的问题
    int* ptr1 = nullptr;
    char* ptr2 = nullptr;
    double* ptr3 = nullptr;
    void* ptr4 = NULL; // NULL = 0;

    // 需要显式转换
    int* ptr5 = (int*)ptr4;

    func1(10);
    func1(NULL);
    func1(nullptr);

    return 0;
}


// nullptr的一种实现方式如下：
const class nullptr_t{
public:
    template<class T>
    inline operator T*() const{
        return 0;
    }

    template<class C, class T>
    inline operator T C::*() const {
        return 0;
    }

private:
    void operator&() const;
} mynullptr = {};




