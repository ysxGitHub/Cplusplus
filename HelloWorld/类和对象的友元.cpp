#include<iostream>
using namespace std;

class Building;
class GoodGay
{

public:
    Building *build;

    void visit();
    // {
    //     cout<<"This is "<<build->m_sittingRoom<<endl;
    // }

    GoodGay();

// private:

};


class GoodGay1
{

public:
    Building *build;

    // 可以访问building的私有成员
    void visit();
    // 不可以访问building的私有成员
    void visit1();

    GoodGay1();

// private:

};


class Building
{
// 全局函数放在类中，前面加入friend，就可以访问私有成员
friend void goodGay(Building & build);

// 告诉编译器GoodGay类是Building类的好朋友，可以访问Building类中私有内容
friend class GoodGay;

// 告诉编译器GoodGay1类下的visit成员函数作为本类的好朋友，可以访问私有成员
friend void GoodGay1::visit();

public:

    string m_sittingRoom;

    Building();
    
    // Building()
    // {
    //     m_bedRoom = "bed room";
    //     m_sittingRoom = "sitting room";
    // }


private:
    string m_bedRoom;

};

Building::Building()
{

    m_bedRoom = "bed room";

    m_sittingRoom = "sitting room";

    cout<<"Building......"<<endl;
};


GoodGay::GoodGay()
{
    build = new Building;
    cout<<"GoodGay......"<<endl;
}

void GoodGay::visit()
{
    cout<<"This is "<<build->m_sittingRoom<<endl;
    cout<<"This is "<<build->m_bedRoom<<endl;
};

GoodGay1::GoodGay1()
{
    build = new Building;
    cout<<"GoodGay......"<<endl;
}

void GoodGay1::visit()
{
    cout<<"This is "<<build->m_sittingRoom<<endl;
    cout<<"This is "<<build->m_bedRoom<<endl;
}


void GoodGay1::visit1()
{
    cout<<"This is "<<build->m_sittingRoom<<endl;
    // cout<<"This is "<<build->m_bedRoom<<endl;
}


// 全局函数
void goodGay(Building & build)
{
    cout<<"This is "<<build.m_sittingRoom<<endl;
    cout<<"This is "<<build.m_bedRoom<<endl;
}


int main(int argc, char const *argv[])
{
    Building build;

    // 1.全局函数做友元
    goodGay(build);

    // 2.友元类
    GoodGay gg;
    gg.visit();

    GoodGay1 gg1;
    gg1.visit();
    gg1.visit1();

    return 0;
}
