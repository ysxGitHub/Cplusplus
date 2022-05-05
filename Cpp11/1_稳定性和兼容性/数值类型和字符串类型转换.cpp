#include <iostream>
#include <string>
using namespace std;

int main()
{
    // 数值转字符串
    string pi = "pi is " + to_string(3.1415926);
    string love = "love is " + to_string(5.20 + 13.14);
    cout << pi << endl;
    cout << love << endl;


    // 字符串转数值
    string str1 = "45";
    string str2 = "3.14159";
    string str3 = "9527 with words";
    string str4 = "words and 2";

    int myint1 = std::stoi(str1);
    float myint2 = std::stof(str2);
    int myint3 = std::stoi(str3);
    int myint4 = std::stoi(str4); // error： 'std::invalid_argument'

    cout << "std::stoi(\"" << str1 << "\") is " << myint1 << endl;
    cout << "std::stof(\"" << str2 << "\") is " << myint2 << endl;
    cout << "std::stoi(\"" << str3 << "\") is " << myint3 << endl;
    cout << "std::stoi(\"" << str4 << "\") is " << myint4 << endl;


    return 0;
}

/*
如果字符串中所有字符都是数值类型，整个字符串会被转换为对应的数值，并通过返回值返回
如果字符串的前半部分字符是数值类型，后半部不是，那么前半部分会被转换为对应的数值，并通过返回值返回
如果字符第一个字符不是数值类型转换失败
*/