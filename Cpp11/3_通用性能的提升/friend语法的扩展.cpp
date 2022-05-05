/*
friend 关键字在 C++ 中是一个比较特别的存在。
    friend 关键字用于声明类的友元，
    友元可以无视类中成员的属性（ public、protected 或是 private ），
    友元类或友元函数都可以访问，这就完全破坏了面向对象编程中封装性的概念。
*/

#include <iostream>
using namespace std;


// C++11 改进
// 1.声明一个类为另外一个类的友元时，不再需要使用 class 关键字，并且还可以使用类的别名（使用 typedef 或者 using 定义）。

// 类声明
class Tom;
// 定义别名
using Honey = Tom;

// 定义两个测试类
class Jack {
    // 声明友元
    // friend class Tom;    // C++98 标准语法
    friend Tom;             // C++11 标准语法
    string name = "jack";   // 默认私有
    void print()            // 默认私有
    {
        cout << "my name is " << name << endl;
    }
};

class Lucy {
protected:
    // 声明友元
    // friend class Tom;    // C++98 标准语法
    friend Honey;           // C++11 标准语法
    string name = "lucy";
    void print()
    {
        cout << "my name is " << name << endl;
    }
};

class Tom {
public:
    void print() {
        // 通过类成员对象访问其私有成员
        cout << "invoke Jack private member: " << jObj.name << endl;
        cout << "invoke Jack private function: " << endl;
        jObj.print();

        cout << "invoke Lucy private member: " << lObj.name << endl;
        cout << "invoke Lucy private function: " << endl;
        lObj.print();
    }
private:
    string name = "tom";
    Jack jObj;
    Lucy lObj;
};

int main1(){
    Tom t;
    t.print();
    return 0;
}


// 2.为类模板声明友元


class Ketty;

template<typename T>
class Person {
    friend T;
};

int main() {
    Person<Ketty> p; // Ketty 类是 Person 类的友元
    Person<int> pp;
    return 0;
}
