
#include <iostream>

// 注：抽象模板中的基本方法尽量设计为 protected 类型，符合迪米特法则，不需要暴露的属性或方法尽量不要设置为 protected 类型。实现类若非必要，尽量不要扩大父类中的访问权限。

class AbstractClass
{
protected:
    virtual void    doSomething() = 0; //基本方法
    virtual void    doAngthing()  = 0;
public:
    void    templateMethod()           //模板方法
    {
        this->doSomething();
        this->doAngthing();
    }
};

class ConcreteClass1:public AbstractClass
{
protected:
    virtual void    doSomething() override {std::cout << "ConcreteClass1 : doSomething\n";}
    virtual void    doAngthing() override {std::cout << "ConcreteClass1 : doAngthing\n";}
};

class ConcreteClass2:public AbstractClass
{
protected:
    virtual void    doSomething() override {std::cout << "ConcreteClass2 : doSomething\n";}
    virtual void    doAngthing() override {std::cout << "ConcreteClass2 : doAngthing\n";}
};

int main ()
{
    AbstractClass *class1 = new ConcreteClass1();
    AbstractClass *class2 = new ConcreteClass2();

    class1->templateMethod();
    class2->templateMethod();

    delete class1;
    delete class2;

    return 0;
}
