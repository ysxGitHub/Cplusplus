#include <iostream>
enum E_Human
{
    EBlackHuman     ,
    EYellowHuman    ,
    EWhiteHuman
};

class Human  //产品类的公共方法
{
public:
    virtual void    getColor() = 0; //每个人种的皮肤都有相应的颜色
    virtual void    talk()     = 0; //人类会说话
};

class BlackHuman:public Human //具体产品类
{
public:
    virtual void    getColor(){std::cout << "Black";}
    virtual void    talk(){std::cout << "Black talk";}
};

class YellowHuman:public Human //具体产品类
{
public:
    virtual void    getColor(){std::cout << "Yellow";}
    virtual void    talk(){std::cout << "Yellow talk";}
};

class WhiteHuman:public Human //具体产品类
{
public:
    virtual void    getColor(){std::cout << "White";}
    virtual void    talk(){std::cout << "White talk";}
};

class AbstractHumanFactory //抽象工厂类
{
public:
    virtual Human* createHuman(E_Human nnum) = 0;
};

class HumanFactory:public AbstractHumanFactory //具体工厂类
{
public:
    virtual Human* createHuman(E_Human nnum)
    {
        Human* human;
        switch(nnum)
        {
        case EBlackHuman:
            human = new BlackHuman();
            break;
        case EYellowHuman:
            human = new YellowHuman();
            break;
        case EWhiteHuman:
            human = new WhiteHuman();
            break;
        }
        return human;
    }
};



int main(int argc, char *argv[])
{

    AbstractHumanFactory *factory = new HumanFactory();
    Human *white = factory->createHuman(EWhiteHuman);
    white->getColor();
    white->talk();

    Human *yellow = factory->createHuman(EYellowHuman);
    yellow->getColor();
    yellow->talk();

    Human *black = factory->createHuman(EBlackHuman);
    black->getColor();
    black->talk();


    return 0;
}
