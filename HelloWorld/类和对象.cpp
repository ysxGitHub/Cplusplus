
// �����������: ��װ  �̳�  ��̬
#include<iostream>
using namespace std;

const double PI=3.14;

/*
��װ:
    �����Ժ���Ϊ��Ϊһ������,���������е�����
    �����Ժ���Ϊ����Ȩ�޿���
*/

class Circle{

public:
    //���е����Ժ���Ϊͳ��Ϊ��Ա
    // ���� (��Ա����)
    int m_r;

    // ��Ϊ (��Ա��Ϊ)
    double calu(){
        return 2*PI*m_r;
    }
};


class Student
{

// ����Ȩ��, Ĭ��Ȩ����˽�е�.
// ����Ȩ��, �����ⶼ���Է���
public:
    string name;
    int num;
    void printf_info()
    {

        cout<<"����: "<<name<<"  ѧ��: "<<num<<endl;

        return ;
    }

// ����Ȩ��, ���ڿ��Է���, ���ⲻ���Է���, ������Է��ʸ���ı�������
protected:
    double hight=189.7;


// ˽��Ȩ��, ���ڿ��Է���, ���ⲻ���Է���, ���಻���Է��ʸ����˽������.
private:
    string passward="1324354";

public:
    void secret_info()
    {
        cout<<"���: "<<hight<<"  ����: "<<passward<<endl;
        return ;
    }

};


class Preson
{
/*
��Ա������Ϊ˽��
    1.�����Լ����ƶ�дȨ��
    2.����д���Լ�����ݵ���Ч��
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
            cout<<"�����������"<<endl;
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
            cout<<"�����������"<<endl;
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

    cout<<"Բ���ܳ�Ϊ: "<<ci.calu()<<endl;

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
