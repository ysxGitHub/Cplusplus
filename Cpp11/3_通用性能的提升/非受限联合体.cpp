/*
1. 什么是非受限联合体
联合体又叫共用体，我将其称之为 union，它的使用方式和结构体类似，
    程序猿可以在联合体内部定义多种不同类型的数据成员，
    但是这些数据会共享同一块内存空间（也就是如果对多个数据成员同时赋值会发生数据的覆盖）。
    在某些特定的场景下，通过这种特殊的数据结构我们就可以实现内存的复用，从而达到节省内存空间的目的。

在 C++11 之前我们使用的联合体是有局限性的，主要有以下三点：
    不允许联合体拥有非 POD 类型的成员
    不允许联合体拥有静态成员
    不允许联合体拥有引用类型的成员

在新的 C++11 标准中，取消了关于联合体对于数据成员类型的限定，
    规定任何非引用类型都可以成为联合体的数据成员，
    这样的联合体称之为非受限联合体（Unrestricted Union）
*/
#include <iostream>
using namespace std;

union Test {
    int age;
    long id;
    int& tmp = age; // error 非受限联合体中不允许出现引用类型
    static char c;
    static int print() {
    // 在静态函数 print() 只能访问非受限联合体 Test 中的静态变量，
    // 对于非静态成员变量（age、id）是无法访问的。
        cout << "c value: " << c << endl;
        return 0;
    }
};
// 需要在非受限联合体外部声明 或者 初始化 之后才能使用
char Test::c;
// char Test::c = 'a';

// 注意：在非受限联合体中静态成员变量和非静态成员变量使用的不是同一块内存。


/*
非 POD 类型成员
    在 C++11 标准中会默认删除一些非受限联合体的默认函数。
        比如，非受限联合体有一个非 POD 的成员，而该非 POD 成员类型拥有 非平凡的构造函数，
        那么非受限联合体的默认构造函数将被编译器删除。
        其他的特殊成员函数，例如默认拷贝构造函数、拷贝赋值操作符以及析构函数等，也将遵从此规则。
*/

union Student{
    int id;
    string name;
};

int main1(){
    Student s; // 无法引用 "Student" 的默认构造函数 -- 它是已删除的函数
/*
上面代码中的非受限联合体 Student 中拥有一个非 PDO 类型的成员 string name，
    string 类中有非平凡构造函数，因此 Student 的构造函数被删除
    （通过警告信息可以得知它的析构函数也被删除了）导致对象无法被成功创建出来。
    解决这个问题的办法就是由程序猿自己为非受限联合体定义构造函数，
    在定义构造函数的时候我们需要用到定位放置 new 操作。
*/
    return 0;
}

/*
placement new
一般情况下，使用 new 申请空间时，是从系统的堆（heap）中分配空间，
    申请所得的空间的位置是根据当时的内存的实际使用情况决定的。但是，在某些特殊情况下，
    可能需要在已分配的特定内存创建对象，这种操作就叫做 placement new 即定位放置 new。

定位放置 new 操作的语法形式不同于普通的 new 操作：

    使用 new 申请内存空间： Base* ptr = new Base;

    使用定位放置 new 申请内存空间： ClassName* ptr = new (定位的内存地址)ClassName;

*/
#include <iostream>
using namespace std;

class Base{
public:
    Base() {}
    ~Base() {}
    void print(){
        cout << "number value: " << number << endl;
    }
private:
    int number;
};

int main2(){
    int n = 100;
    Base* b = new (&n)Base;
    b->print();  // 100
    return 0;
}

/*
Base* b = new (&n)Base;
在程序的第 93 行，使用定位放置的方式为指针 b 申请了一块内存，
    也就是说此时指针 b 指向的内存地址和变量 n 对应的内存地址是同一块（栈内存），
    而在 Base类中成员变量 number 的起始地址和 Base对象的起始地址是相同的，
    所以打印出 number 的值为 100 也就是整形变量 n 的值。
*/


/*
最后，给大家总结一下关于 placement new 的一些细节：

    使用定位放置 new 操作，既可以在栈 (stack) 上生成对象，也可以在堆（heap）上生成对象，
        这取决于定位时指定的内存地址是在堆还是在栈上。
    从表面上看，定位放置 new 操作是申请空间，其本质是利用已经申请好的空间，
        真正的申请空间的工作是在此之前完成的。
    使用定位放置 new 创建对象时会自动调用对应类的构造函数，但是由于对象的空间不会自动释放，
        如果需要释放堆内存必须显示调用类的析构函数。
    定位放置 new 操作，我们可以反复动态申请到同一块堆内存，这样可以避免内存的重复创建销毁，
        从而提高程序的执行效率（比如网络通信中数据的接收和发送）。
*/

// 自定义非受限联合体构造函数
class Base {
public:
    void setText(string str) {
        notes = str;
    }
    void print() {
        cout << "Base notes: " << notes << endl;
    }
private:
    string notes;
};

union Student {
    Student() {
        new (&name)string;
    }
    ~Student() {}

    int id;
    Base tmp;
    string name;
};

int main2() {
    Student s;
    s.name = "蒙奇·D·路飞";
    s.tmp.setText("我是要成为海贼王的男人!");
    s.tmp.print();  // Base notes: 我是要成为海贼王的男人!
    cout << "Student name: " << s.name << endl; // Student name: 我是要成为海贼王的男人!
    return 0;
}
/*
我们在上面的程序里边给非受限制联合体显示的指定了构造函数和析构函数，
    在程序的第 145 行需要创建一个非受限联合体对象，这时便调用了联合体内部的构造函数，
    在构造函数的第 135 行通过定位放置 new 的方式将构造出的对象地址定位到了联合体的成员
    string name 的地址上了，这样联合体内部其他非静态成员也就可以访问这块地址了
    （通过输出的结果可以看到对联合体内的 tmp 对象赋值，会覆盖 name 对象中的数据）。

*/

// 匿名的非受限联合体
/*
例如：
    木叶村要进行第99次人口普查，人员的登记方式如下：
        - 学生只需要登记所在学校的编号
        - 本村学生以外的人员需要登记其身份证号码
        - 本村外来人员需要登记户口所在地+联系方式
*/
// 外来人口信息
struct Foreigner {
    Foreigner(string s, string ph) : addr(s), phone(ph) {}
    string addr;
    string phone;
};

// 登记人口信息
class Person {
public:
    enum class Category : char {Student, Local, Foreign};
    Person(int num) : number(num), type(Category::Student) {}
    Person(string id) : idNum(id), type(Category::Local) {}
    Person(string addr, string phone) : foreign(addr, phone), type(Category::Foreign) {}
    ~Person() {}

    void print() {
        cout << "Person category: " << (int)type << endl;
        switch (type) {
        case Category::Student:
            cout << "Student school number: " << number << endl;
            break;
        case Category::Local:
            cout << "Local people ID number: " << idNum << endl;
            break;
        case Category::Foreign:
            cout << "Foreigner address: " << foreign.addr
                << ", phone: " << foreign.phone << endl;
            break;
        default:
            break;
        }
    }

private:
    Category type;
    union {
        int number;
        string idNum;
        Foreigner foreign;
    };
};

int main() {
    Person p1(9527);
    Person p2("1101122022X");
    Person p3("砂隐村村北", "1301810001");
    p1.print();
    p2.print();
    p3.print();
    return 0;
}
/*
根据需求我们将木叶村的人口分为了三类并通过枚举记录了下来，
    在 Person类中添加了一个匿名的非受限联合体用来存储人口信息，
    仔细分析之后就会发现这种处理方式的优势非常明显：尽可能地节省了内存空间。

        Person类可以直接访问匿名非受限联合体内部的数据成员。
        不使用匿名非受限联合体申请的内存空间等于 number、 idNum 、 foreign 三者内存之和。
        使用匿名非受限联合体之后 number、 idNum 、 foreign 三者共用同一块内存。
*/

