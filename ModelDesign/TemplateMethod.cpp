/*
Template Method 模式是一种非常基础性的设计模式，在面向对象系统中有着大量的应用。

模式定义：
    定义一个操作中的算法的骨架（稳定），而将一些步骤延迟（变化）到子类中。
    Template Method使得子类可以不改变（复用）一个算法的结构即可重定义（override重写）
    该算法的某些特定步骤。

*/ 

// 程序库开发人员
class Library{
public:
    void Step1(){
        // ...
    }
    void Step3(){
        // ...
    }
    void Step5(){
        // ...
    }
};

// 应用程序开发人员
class Application{
public:
    bool Step2(){
        // ...
    }
    bool Step3(){
        // ...
    }

};

int main(int argc, char const *argv[])
{
    // 稳定的
    Library lib();
    Application app();

    lib.Step1();

    if(app.Step2()){
        lib.Step3();
    }

    for(int i=0; i<4; i++){
        app.Step4();
    }

    lib.Step5();

    return 0;
}

//////////////////
// Template Method
//////////////////

// 程序库开发人员
class Library{
public:
    // 稳定 template method
    void Run(){
        Step1();

        if(Step2()){ //支持变化==》虚函数的多态调用
            Step3();
        }

        for(int i=0; i<4; i++){
            Step4(); //支持变化==》虚函数的多态调用
        }

        Step5();
    }
    // 多态指针 ——> 父类要写虚析构函数，子类的析构函数才可能正常调用
    virtual ~Library(){}

private:
    void Step1(){  //稳定
        // ...
    }
    void Step3(){  //稳定
        // ...
    }
    void Step5(){  //稳定
        // ...
    }

    virtual bool Step2()=0;
    virtual void Step4()=0;
};

// 应用程序开发人员
class Application{
public:
    virtual bool Step2(){
        // ...之类重写实现
    }
    virtual bool Step3(){
        // ...之类重写实现
    }

};

int main(int argc, char const *argv[])
{
    Library* pLib = new Application();
    lib->Run();
    delete pLib;
    return 0;
}




