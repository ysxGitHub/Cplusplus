#include<iostream>
using namespace std;
#include<string>

// 字符串初始化
void test01()
{
    string s1;
    
    const char* str = "+++";
    string s2(str);
    cout<<s2<<endl;

    string s3(s2);
    string s4(20, '*');
    cout<<s3<<endl;
    cout<<s4<<endl;

    string str1;
    str1 = "hello ";
    cout<<str1<<endl;

    string str2;
    str2 = str1;
    cout<<str2<<endl;

    string str3;
    str3 = '+';
    cout<<str3<<endl;

    string str4;
    str4.assign("hello ");
    cout<<str4<<endl;

    string str5;
    str5.assign("hello C++",5);
    cout<<str5<<endl;

    string str6;
    str6.assign(str5);
    cout<<str6<<endl;

    string str7;
    str7.assign(10,'-');
    cout<<str7<<endl;
}

// 字符串拼接
void test02()
{
    string str1 = "hello ";
    str1 += "world! ";
    cout<<str1<<endl;

    str1+='n';
    cout<<str1<<endl;

    string str2 = "o bushi";

    str1+=str2;
    cout<<str1<<endl;

    string str3 = "I ";

    str3.append("like ");
    cout<<str3<<endl;

    str3.append("play a game", 4);
    cout<<str3<<endl;

    str3.append(str2);
    cout<<str3<<endl;

    // 从str2的第二个位置开始截取5个字符
    str3.append(str2,2,5);
    cout<<str3<<endl;


}



int main(int argc, char const *argv[])
{

    test01();

    test02();

    // 3. 字符串查找与替换
    string str1 = "aabbccdd";
    cout<<str1.find("b")<<endl;
    // 从右边找
    cout<<str1.rfind("b")<<endl;
    // 从1号位置起2个字符被替换为eee；
    str1.replace(1,2,"eee");
    cout<<str1<<endl;

    // 4. 字符串比较
    string str2="aabb";
    string str3="aabb";
    // str2==str3 return 0
    // str2>str3 return 1
    // str2<str3 return -1
    cout<<str2.compare(str3)<<endl;

    // 5. 字符存取
    string str4="zzbbbcc";
    for(int i=0; i<str4.size(); i++)
    {
        cout<<str4[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<str4.size(); i++)
    {
        cout<<str4.at(i)<<" ";
    }
    cout<<endl;

    str4[0] = 'x';
    cout<<str4<<endl;

    str4.at(0) = 'z';
    cout<<str4<<endl;

    // 6. 字符串的插入和删除
    string st1 = "hello";
    // 从第0个开始插入
    st1.insert(0,"abc ");
    cout<<st1<<endl;
    // 从第0个开始删除4个字符
    st1.erase(0, 4);
    cout<<st1<<endl;

    // 子串的获取
    string st2 = "aabbccddeeff";
    // 从0开始截取2个
    cout<<st2.substr(0,2)<<endl;
    
    string qq="2206405089@qq.com";
    int index = qq.find('@');
    cout<<qq.substr(0, index)<<endl;


    return 0;
}



