/*
请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号整数（类似 C/C++ 中的 atoi 函数）。

函数 myAtoi(string s) 的算法如下：
    读入字符串并丢弃无用的前导空格
    检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。
        如果两者都不存在，则假定结果为正。
    读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
    将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。
        如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
    如果整数数超过 32 位有符号整数范围 [−2^31,  2^31 − 1] ，需要截断这个整数，使其保持在这个范围内。
        具体来说，小于 −2^31 的整数应该被固定为 −2^31 ，大于 2^31 − 1 的整数应该被固定为 2^31 − 1 。
    返回整数作为最终结果。
注意：
本题中的空白字符只包括空格字符 ' ' 。
除前导空格或数字后的其余字符串外，请勿忽略 任何其他字符。
*/
#include<iostream>
#include<sstream>
#include<unordered_map>
#include<vector>
using namespace std;

int myAtoi1(string s) {
    int result = 0;
    stringstream ss;
    ss << s;
    ss >> result;
    return result;
}

int myAtoi(string s) {
    int sign = 1;
    int res = 0;
    int m = s.size();
    int i = 0;
    // 先去掉开头的空格
    while(i < m && s[i]==' '){
        i++;
    }
    int start = i;
    for(; i < m; i++){
        char c = s[i];
        if(i==start && c=='+'){
            // 开始位置是 +
            sign = 1;
        }
        else if(i==start && c=='-'){
            // 开始位置是 -
            sign = -1;
        }
        else if(isdigit(c)){
            // 是 数字
            int num = c-'0';
            // 大于 INT32_MAX
            if(res > INT32_MAX/10 || (res == INT32_MAX/10&&num>INT32_MAX%10)){
                return INT32_MAX;
            }
            // 小于 INT32_MIN
            if(res < INT32_MIN/10 || (res == INT32_MIN/10&&-num<INT32_MIN%10)){
                return INT32_MIN;
            }
            res = res*10+sign*num;
        }
        else{
            // 否则直接退出
            break;
        }
    }
    return res;
}


int main(int argc, char const *argv[])
{
    myAtoi("  +  121 + 1321");
    return 0;
}
