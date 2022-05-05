#include<iostream>
using namespace std;
// 包含头对象
#include<fstream>


class Person
{
public:
    int m_Age;
    char m_Name[64];
};

int main(int argc, char const *argv[])
{
    // 写文件流程
    // 1.创建 写 流对象
    ofstream ofs;
    // 2.以什么方式打开文件
    /*
        ios::in      为读文件而打开文件
        ios::out     为写文件而打开文件
        ios::ate     初始位置：文件尾
        ios::app     追加方式写文件
        ios::trunc   如果文件存在先删除，在创建
        ios::binary  二进制方式
        用二进制方式写文件 ios:out | ios:binary
    */ 
    ofs.open("test.txt", ios::out);
    // 3.写数据，文件中endl也相当于换行
    ofs<<"ysx"<<endl;
    ofs<<"1234567890";
    // 4.关闭文件
    ofs.close();

    // 读文件流程
    // 1.创建 读 流对象
    ifstream ifs;
    // 2.打开文件，并且用is_open()判断是否打开成功
    ifs.open("test.txt", ios::in);
    if(!ifs.is_open())
    {
        printf("open file failure!!");
        return 0;
    }
    // 3.读数据
    // 第一种
    // char buf[1024] = {0};
    // while (ifs>>buf)
    // {
    //     cout<<buf<<endl;
    // }

    // 第二种
    // char buf[1024] = {0};
    // while (ifs.getline(buf, sizeof(buf)))
    // {
    //     cout<<buf<<endl;
    // }

    // 第三种
    string buf;
    while (getline(ifs, buf))
    {
        cout<<buf<<endl;
    }

    // 第四种
    // char c;
    // while ((c = ifs.get())!=EOF)
    // {
    //     cout<<c;
    // }

    // 4.关闭文件
    ifs.close();

    // 二进制文件写
    // 1.创建 写 流对象
    // 2.打开文件
    ofstream ofsb("person.txt",ios::out|ios::binary); 
    // 3.写文件
    Person p1={31, "lisi"};
    ofsb.write((const char*)&p1, sizeof(p1));
    
    // 4.关闭文件
    ofsb.close();

    // 二进制文件读
    // 1.创建 读 流对象
    ifstream ifsb;
    // 2.打开文件 并判断是否打开成功
    ifsb.open("person.txt", ios::in | ios::binary);
    if(!ifsb.is_open())
    {
        cout<<"file open failure!!"<<endl;
        return 0;
    }
    // 3.读文件
    Person p;
    ifsb.read((char*)&p, sizeof(Person));
    cout<<p.m_Age<<endl;
    cout<<p.m_Name<<endl;
    // 4.关闭文件
    ifsb.close();

    return 0;
}

