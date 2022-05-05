#include <iostream>
using namespace std;

class Fraction
{
public:
    // 转换函数：将别的类型转为这种类的类型，要配合 Fraction operator+(cosnt Fraction& f)使用
    // explicit 用在构造函数前, 只有在创建对象时会调用该构造函数, 不会将4自动转为Fraction
    // explicit Fraction(int num, int den = 1) : m_numerator(num), m_denominator(den) {}
    Fraction(int num, int den = 1) : m_numerator(num), m_denominator(den) {}
    
    Fraction operator+(const Fraction& f)
    {
        return Fraction((this->m_numerator+f.get_num()), this->m_denominator);
    }

    // 转换函数：将这种类的类型转为需要的类型(double)
    // operator double() const
    // {
    //     return (m_numerator / (double)m_denominator);
    // }

    int get_num() const
    {
        return this->m_numerator;
    }
    int get_den() const
    {
        return this->m_denominator;
    }

private:
    int m_numerator;
    int m_denominator;
};

int main(int argc, char const *argv[])
{
    Fraction f(4, 5);
    // double d = 4 + f;
    // cout << d << endl;

    Fraction d2 = f + 4;
    cout<<d2.get_num()<<"/"<<d2.get_den()<<endl;
    return 0;
}
