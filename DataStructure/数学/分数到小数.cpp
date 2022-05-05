/*
给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以 字符串形式返回小数 。

如果小数部分为循环小数，则将循环的部分括在括号内。

如果存在多个答案，只需返回 任意一个 。

对于所有给定的输入，保证 答案字符串的长度小于 10^4 。
*/

#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;


string fractionToDecimal(int numerator, int denominator) {
    string ans;
    unordered_map<long long, int>idx;
    // 先转为 long long 防止溢出
    long long num = numerator, den = denominator;
    // 如果可以整除直接返回
    if(num%den==0) return to_string(num/den);

    // 如果存在负数直接在 答案中先添加 '-' , 然后对数取绝对值
    if(num*den<0) {
        num = abs(num);
        den = abs(den);
        ans += '-';
    }

    // 先存入整数部分，注意加 '.'
    ans += to_string(num / den) + ".";
    // 得到余数部分
    long long remainder = num % den;

    // 利用长除法，idx 保留商 与 对应字符的位置，发现出现同样的商则退出
    while(remainder!=0&&!idx.count(remainder)){
        idx[remainder] = ans.size();
        remainder*=10;
        ans += to_string(remainder/den);
        remainder %= den;
    }
    if(remainder!=0){
        int pos = idx[remainder];
        // 组合答案
        ans = ans.substr(0, pos) + "(" + ans.substr(pos) + ")";
    }

    return ans;
}

