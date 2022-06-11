/*
这个类模板的一些特点：
 它是一个轻量级的容器类型，内部定义了迭代器 iterator 等容器必须的概念，遍历时得到的迭代器是只读的。
 对于 std::initializer_list<T> 而言，它可以接收任意长度的初始化列表，但是要求元素必须是同种类型 T
 在 std::initializer_list 内部有三个成员接口：size(), begin(), end()。
 std::initializer_list 对象只能被整体初始化或者赋值。
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void func(initializer_list<int> ls) {
    for(auto it=ls.begin(); it!=ls.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;
}

class Test {
public:
    Test(std::initializer_list<string> list){
        for (auto it = list.begin(); it != list.end(); ++it){
            cout << *it << " ";
            m_names.push_back(*it);
        }
        cout << endl;
    }
private:
    vector<string> m_names;
};



int main(int argc, char const *argv[]) {
    func({1,2,3,4,5});

    return 0;
}


