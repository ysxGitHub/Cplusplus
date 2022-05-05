#include<iostream>
using namespace std;

/*

继承的好处：减少重复的代码
语法：class 子类： 继承方式 父类
子类：派生类； 父类：基类


父类的私有属性的成员 子类什么样的继承都无法访问父类的私有属性的成员

继承方式：
    公共继承
        父类中的成员属性，子类继承后 子类中继承的成员不改变其属性

    保护继承
        父类中的公有属性与保护属性的成员，子类继承后 子类中继承的成员都变为保护属性的成员
    
    私有继承
        父类中的公有属性与保护属性的成员，子类继承后 子类中继承的成员都变为私有属性的成员

继承中的构造和析构函数
    先调用父类构造函数，再调用子类构造函数，而析构函数的调用相反

*/ 

class Animal
{

public:
    Animal()
    {
        cout<<"father class constructing function"<<endl;
    }
    ~Animal()
    {
        cout<<"father class destructing function"<<endl;
    }
    void eat()
    {
        cout<<"eat"<<endl;
    }
    void sleep()
    {
        cout<<"sleep"<<endl;
    }
    void drink()
    {
        cout<<"drink"<<endl;
    }
    int a=0;

    void func()
    {
        cout<<"father func"<<endl;
    }

    void func(int num)
    {
        cout<<"father func"<<num<<endl;
    }

    static int s;
    static void sfunc()
    {
        cout<<"father static function"<<endl;
    }

protected:
    void life()
    {
        cout<<"life"<<endl;
    }
    int b=0;

private:
    void people()
    {
        cout<<"people"<<endl;
    }
    int c=0;

};
int Animal::s = 10;


class Dog: public Animal
{

public:
    Dog()
    {
        cout<<"son class constructing function"<<endl;
    }
    ~Dog()
    {
        cout<<"son class destructing function"<<endl;
    }
    void bark()
    {
        cout<<"wangwang"<<endl;
    }
    int a=1;

    void func()
    {
        cout<<"son func"<<endl;
    }

    static int s;
    static void sfunc()
    {
        cout<<"son static function"<<endl;
    }

};
int Dog::s = 20;

class Cat: protected Animal
{
public:
    void bark()
    {
        cout<<"miaomiao"<<endl;
    }


};

class Fish: private Animal
{
public:
    void bark()
    {
        cout<<"bobo"<<endl;
    }

};


int main(int argc, char const *argv[])
{

    Dog d1;
    // 公共继承后，子类中继承的成员属性不变
    d1.eat();
    d1.drink();
    d1.sleep();
    d1.bark();
    
    Cat c1;
    // 保护继承后，子类中继承的成员都变为保护属性成员，外部不能访问
    // c1.eat();
    // c1.drink();
    // c1.sleep();
    c1.bark();

    Fish f1;
    // 私有继承后，子类中继承的成员都变为私有属性成员，外部不能访问
    // f1.eat();
    // f1.drink();
    // f1.sleep();
    f1.bark();


    // 16
    // 父类中所有非静态属性成员都会被子类继承下去，包括私有属性成员，只是子类不能访问而已。
    cout<<sizeof(Dog)<<endl;


    // 父类与子类出现同名成员时，
    // 子类会屏蔽父类中的所有的同名成员，只访问自己具有的
    cout<<d1.a<<endl;
    d1.func();
    // 子类访问父类的同名成员需要加上作用域
    cout<<d1.Animal::a<<endl;
    d1.Animal::func();


    // 父类与子类出现同名静态成员时，
    // 1.通过对象访问
    cout<<d1.s<<endl;
    cout<<d1.Animal::s<<endl;
    d1.sfunc();
    d1.Animal::sfunc();
    // 2.通过类名访问
    cout<<Dog::s<<endl;
    cout<<Dog::Animal::s<<endl;
    Dog::sfunc();
    Dog::Animal::sfunc();
    

    return 0;
}
