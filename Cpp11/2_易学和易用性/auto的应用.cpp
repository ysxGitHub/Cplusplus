#include<map>
#include<iostream>
using namespace std;

// 用于STL的容器遍历
void func1(){
    map<string, int>mp;
    for(auto it=mp.begin(); it!=mp.end(); ++it){

    }
}


class T1{
public:
    static int get()
    {
        return 10;
    }
};

class T2{
public:
    static string get()
    {
        return "hello, world";
    }
};


// 用于泛型编程
template<class T>
void func(void){
    auto ret = T::get();
    cout<<"1: "<<ret<<endl;
};

// 可以替换上面
template<class T, class P>
void func(void){
    P ret = T::get();
    cout<<"2: "<<ret<<endl;
};

int main(int argc, char const *argv[])
{
    func<T1>();
    func<T2>();
    func<T1, int>();
    func<T2, string>();
    return 0;
}
