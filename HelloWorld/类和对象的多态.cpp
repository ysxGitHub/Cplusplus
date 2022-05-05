#include <iostream>
using namespace std;
/*

cl /d1 reportSingleClassLayoutCat "类和对象的多态.cpp"

class Animal    size(4):
        +---
 0      | {vfptr}
        +---

Animal::$vftable@:
        | &Animal_meta
        |  0
 0      | &Animal::speak



class Cat       size(4):
        +---
 0      | +--- (base class Animal)
 0      | | {vfptr}
        | +---
        +---

Cat::$vftable@:
        | &Cat_meta
        |  0
 0      | &Cat::speak


*/

/*
多态满足条件
    有继承关系
    子类重写父类中的虚函数
多态使用条件
    父类指针或引用指向子类对象

重写：函数返回值类型 函数名 参数列表完全一致称为重写
*/

class Animal
{
public:
    //函数前面加上virtual关键字变为虚函数，这样编译器不会确定调用的函数
    virtual void speak()
    {
        cout << "animal is speaking!" << endl;
    }
    virtual void eat()
    {
        cout << "animal is eating" << endl;
    }
};

class Cat : public Animal
{

public:
    void speak()
    {
        cout << "miaomiao~" << endl;
    }
    void eat()
    {
        cout << "eat fish" << endl;
    }
};

class Dog : public Animal
{
public:
    void speak()
    {
        cout << "wangwang~" << endl;
    }
    void eat()
    {
        cout << "eat meat" << endl;
    }
};

void doSpeak(Animal &animal)
{
    animal.speak();
}

void doEat(Animal *aniaml)
{
    aniaml->eat();
}

class People
{

public:
    /*
    纯虚函数
    有纯虚函数的类称为抽象类
    抽象类的特点：
        1.无法实例对象
        2.抽象类的子类必须要重写父类中的纯虚函数，否则也属于纯虚函数
    
    虚析构函数和纯虚析构函数共性：
        可以解决父类指针释放子类对象
        都需要有具体的函数实现
        子类中没有堆区数据,可以写这两个函数
    虚析构函数和纯虚析构函数区别:
        纯虚析构,该类属于抽象类,无法实例化对象
    */
    virtual void speak() = 0;
    People()
    {
        cout << "people constructing function" << endl;
    }

    // 父类的指针在析构时，不会调用子类中的析构函数，导致子类如果有堆区属性成员，会出现内存泄漏，
    // 因此需要加virtual关键字，变为虚析构函数,或者变为纯虚析构函数
    // ~People()
    // {
    //     cout << "people destructing function" << endl;
    // }
    
    // virtual ~People()
    // {
    //     cout << "people destructing function" << endl;
    // }
    // 注意:纯虚析构函数需要类外实现
    virtual ~People()=0;

};

People::~People()
{
    cout << "people destructing function" << endl;
}

class China : public People
{
public:
    void speak()
    {
        cout << "Chinese" << endl;
    }
    string *name;

    China(string name)
    {
        this->name = new string(name);
        cout << "China constructing function" << endl;
    }

    ~China()
    {
        if (this->name != NULL)
        {
            cout << "China destructing function" << endl;
            delete this->name;
            this->name = NULL;
        }
    }
};

class Japan : public People
{
public:
    void speak()
    {
        cout << "Japanese" << endl;
    }
};

void doTell(People &people)
{
    people.speak();
}

void doTell()
{
    People *people = new China("Tom");
    people->speak();
    delete people;
}

int main(int argc, char const *argv[])
{
    Cat c1;
    doSpeak(c1);
    Dog d1;
    doSpeak(d1);

    // 有virtual时虚函数空间大小为地址指针，Animal的空间大小为8个字节，没virtual时函数不占空间，Animal的空间大小为1字节
    cout << "animal size: " << sizeof(Animal) << endl;

    doEat(&c1);
    doEat(&d1);

    // Japan j1;
    // doTell(j1);
    China ch("Tom");
    
    doTell();
    // 使用引用时不会发生子类析构函数不执行
    // doTell(ch);

    return 0;
}
