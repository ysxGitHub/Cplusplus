
// 类的三大特性: 封装  继承  多态
#include<iostream>
using namespace std;

const double PI=3.14;

/*
封装:
    将属性和行为作为一个整体,表现生活中的事物
    将属性和行为加以权限控制
*/

class Circle{

public:
    //类中的属性和行为统称为成员
    // 属性 (成员属性)
    int m_r;

    // 行为 (成员行为)
    double calu(){
        return 2*PI*m_r;
    }
};


class Student
{

// 访问权限, 默认权限是私有的.
// 公共权限, 类内外都可以访问
public:
    string name;
    int num;
    void printf_info()
    {

        cout<<"姓名: "<<name<<"  学号: "<<num<<endl;

        return ;
    }

// 保护权限, 类内可以访问, 类外不可以访问, 子类可以访问父类的保护内容
protected:
    double hight=189.7;


// 私有权限, 类内可以访问, 类外不可以访问, 子类不可以访问父类的私有内容.
private:
    string passward="1324354";

public:
    void secret_info()
    {
        cout<<"身高: "<<hight<<"  密码: "<<passward<<endl;
        return ;
    }

};


class Preson
{
/*
成员属性设为私有
    1.可以自己控制读写权限
    2.对于写可以检测数据的有效性
*/
private:
    string m_Name=" ";
    double m_Hight=178.9;
    int m_Age=18;


public:
    void set_Name(string name)
    {
        m_Name = name;
    }
    string get_Name()
    {
        return m_Name;
    }
    void set_Age(int age)
    {
        if(age<=0 || age>=200)
        {
            cout<<"你输入的有误"<<endl;
            return ;
        }
        m_Age = age;
    }
    int get_Age()
    {
        return m_Age;
    }
    double get_Hight()
    {
        return m_Hight;
    }

};

class Cube
{
public:
    double m_Lenght=0.0;
    double m_Wight=0.0;
    double m_Hight=0.0;

private:
    void set_Param(double lenght, double wight, double hight)
    {
        if(lenght<0 || wight<0 || hight<0)
        {
            cout<<"你输入的有误"<<endl;
            return ;
        }

        m_Lenght = lenght;
        m_Hight = hight;
        m_Wight = wight;
    }


    double get_Area()
    {
        return 2.0*(m_Lenght*m_Hight+m_Hight*m_Wight+m_Wight*m_Lenght);
    }

    double get_Volume()
    {
        return m_Lenght*m_Hight*m_Wight;
    }


};

int main(int argc, char const *argv[])
{
    Circle ci;

    ci.m_r=10;

    cout<<"圆的周长为: "<<ci.calu()<<endl;

    Student st1;

    st1.name = "ZhangSan";
    st1.num = 13214325;

    st1.printf_info();

    st1.secret_info();

    Preson p1;
    p1.set_Name("LiSi");
    cout<<p1.get_Name()<<endl;
    p1.set_Age(-1);

    return 0;
}
