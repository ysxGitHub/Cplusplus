#include <iostream>
#include <string>
using namespace std;

/*
如果不满足聚合条件还想使用列表初始化其实也是可以的，需要在类的内部自定义一个构造函数,
    在构造函数中使用初始化列表对类成员变量进行初始化:
*/

class Person{
public:
    // 初始化列表 会调用 类的构造函数 去初始化 对象
    Person(int num) : m_num(num){

    }
    Person(int num, string name) : m_name(name), m_num(num) {

    }

private:
    int m_num;
    string m_name;
};

Person getPerson(){
    return {110, "李华"};
}

int main1(int argc, char const *argv[])
{
    Person p1{120, "李四"};
    return 0;
}


/*
需要额外注意的是聚合类型的定义并非递归的，也就是说当一个类的非静态成员是非聚合类型时，
    这个类也可能是聚合类型，比如下面的这个例子：
*/
struct T1{
    int x;
    double y;
private:
    int z;
};

struct T2{
    T1 t1;
    long x1;
    double y1;
};

int main(void){
    T2 t2{ {}, 520, 13.14 };
    return 0;
}

/*
最后强调一下 t2 对象的初始化过程，对于非聚合类型的成员 t1 做初始化的时候，
    可以直接写一对空的大括号 {}，这相当于调用是 T1 的无参构造函数。
*/