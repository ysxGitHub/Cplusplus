/*
复数 可以用字符串表示，遵循 "实部+虚部i" 的形式，并满足下述条件：

实部 是一个整数，取值范围是 [-100, 100]
虚部 也是一个整数，取值范围是 [-100, 100]
i^2 == -1
给你两个字符串表示的复数 num1 和 num2 ，请你遵循复数表示形式，返回表示它们乘积的字符串。
*/
#include <vector>
#include <iostream>
#include <regex>
using namespace std;

vector<int> stringToNums(string num)
{
    vector<int> func(4, 0);
    string real, imag;
    // int neg1 = 0, neg2 = 0;
    int addidx = num.find('+');
    if (num[0] != '-')
    {
        real = num.substr(0, addidx);
    }
    else
    {
        func[0] = 1;
        real = num.substr(1, addidx - 1);
    }
    if (num[addidx + 1] != '-')
    {
        imag = num.substr(addidx + 1, num.size() - 1 - addidx - 1);
    }
    else
    {
        func[2] = 1;
        imag = num.substr(addidx + 2, num.size() - 1 - addidx - 2);
    }
    func[1] = stoi(real);
    func[3] = stoi(imag);
    return func;
}

string complexNumberMultiply(string num1, string num2)
{
    string ans;
    vector<int> fun1 = stringToNums(num1);
    vector<int> fun2 = stringToNums(num2);
    int real1 = fun1[1] * fun2[1];
    int real2 = fun1[3] * fun2[3];
    if ((fun1[0] == 0 && fun2[0] == 1) || (fun1[0] == 1 && fun2[0] == 0))
    {
        real1 = -real1;
    }
    if ((fun1[2] == 0 && fun2[2] == 0) || (fun1[2] == 1 && fun2[2] == 1))
    {
        real2 = -real2;
    }
    int real = real1 + real2;

    ans += to_string(real);

    int imag1 = fun1[1] * fun2[3];
    int imag2 = fun1[3] * fun2[1];
    if ((fun1[0] == 0 && fun2[2] == 1) || (fun1[0] == 1 && fun2[2] == 0))
    {
        imag1 = -imag1;
    }
    if ((fun1[2] == 0 && fun2[0] == 1) || (fun1[2] == 1 && fun2[0] == 0))
    {
        imag2 = -imag2;
    }
    int imag = imag1 + imag2;
    ans += '+';
    ans += to_string(imag);
    ans += 'i';
    return ans;
}


string complexNumberMultiply1(string num1, string num2) {
    regex re("\\+|i"); 
    vector<string> complex1(sregex_token_iterator(num1.begin(), num1.end(), re, -1), std::sregex_token_iterator());
    vector<string> complex2(sregex_token_iterator(num2.begin(), num2.end(), re, -1), std::sregex_token_iterator());
    int real1 = stoi(complex1[0]);
    int imag1 = stoi(complex1[1]);
    int real2 = stoi(complex2[0]);
    int imag2 = stoi(complex2[1]);
    return to_string(real1 * real2 - imag1 * imag2) + "+" + to_string(real1 * imag2 + imag1 * real2) + "i";
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
