#include<iostream>
#include<string>
using namespace std;


int main(int argc, char const *argv[])
{
    string s1 = "D:\hello\world\test.exe";
    cout<<s1<<endl;

    //原始字变量, 类似 python 中的 print(f"hello word!")
    string s2 = R"(D:\hello\world\test.exe)";
    cout<<s2<<endl;

    // 添加注释 hello 注意前后必须添加相同的注释
    string s3 = R"hello(D:\hello\world\test.exe)hello";
    cout<<s3<<endl;
    return 0;
}


