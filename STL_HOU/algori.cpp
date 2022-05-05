#include<algorithm>
#include<numeric>
#include<iostream>
#include<vector>
using namespace std;

// 迭代器的分类 对 算法的效率 的影响？
// void test01()
// {
//     // 两个指针的距离
//     distance();
//     // 指针的前进方式
//     advance();
//     // copy
//     copy();
//     // 显示调用一个对象的析构函数 相当于释放一个对象需要释放的一些动态内存 为下次真正释放对象做准备
//     destroy();
// }

// 自己写的仿函数要继承 标准库的父类 如：public: binary_function<T, T, bool>，
//                                 public: unary_function<T, bool>

int myfunc(int x, int y){return x+2*y;}

class myclass
{
public:
    int operator()(int x, int y){return x+3*y;}
};
void accumulate_test()
{
    int init=100;
    int nums[] = {10,20,30};
    cout<<"using default acc: ";
    cout<<accumulate(nums, nums+3, init)<<endl;
    cout<<"using minus: ";
    cout<<accumulate(nums, nums+3, init, minus<int>())<<endl;
    cout<<"using function: ";
    cout<<accumulate(nums, nums+3, init, myfunc)<<endl;
    cout<<"using object: ";
    cout<<accumulate(nums, nums+3, init, myclass())<<endl;
}

void myfunc1(int i){
    cout<<i<<" ";
}

class myobj1{
public:
    void operator()(int i){
        cout<<i<<" ";
    }    
};

void for_each_test()
{
    vector<int> V;
    V.push_back(10);
    V.push_back(20);
    V.push_back(30);
    for_each(V.begin(), V.end(), myfunc1);
    for_each(V.begin(), V.end(), myobj1());

    for(auto& elem: V){
        elem += 5;
    }
    for(auto& elem: V){
        cout<<elem<<" ";
    }
    cout<<endl;

}
bool myfunc2(int i, int j){
    return (i>j);
}

class myobj2{
public: 
    bool operator()(int i, int j){
        return (i<j);
    }
};

void sort_test(){
    int nums[] = {20,29,19,9,30,40,10,6};
    vector<int> myvec(nums, nums+8);
    
    sort(myvec.begin(), myvec.end());
    for(auto& elem: myvec){
        cout<<elem<<" ";
    }
    cout<<endl;
    // 反向
    sort(myvec.rbegin(), myvec.rend());
    for(auto& elem: myvec){
        cout<<elem<<" ";
    }
    cout<<endl;

    sort(myvec.begin(), myvec.end(),myfunc2);
    for(auto& elem: myvec){
        cout<<elem<<" ";
    }
    cout<<endl;
    sort(myvec.begin(), myvec.end(),myobj2());
    for(auto& elem: myvec){
        cout<<elem<<" ";
    }
    cout<<endl;

    sort(myvec.begin(), myvec.end(),greater<int>());
    for(auto& elem: myvec){
        cout<<elem<<" ";
    }
    cout<<endl;

    sort(myvec.begin(), myvec.end(),less<int>());
    for(auto& elem: myvec){
        cout<<elem<<" ";
    }
    cout<<endl;

}

int main(int argc, char const *argv[])
{
    /* code */
    accumulate_test();
    for_each_test();
    sort_test();
    return 0;
}

