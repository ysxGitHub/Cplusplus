/*
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。

数值（按顺序）可以分成以下几个部分：
    若干空格
    一个 小数 或者 整数
    （可选）一个 'e' 或 'E' ，后面跟着一个 整数
    若干空格

小数（按顺序）可以分成以下几个部分：
    （可选）一个符号字符（'+' 或 '-'）
    下述格式之一：
    至少一位数字，后面跟着一个点 '.'
    至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
    一个点 '.' ，后面跟着至少一位数字

整数（按顺序）可以分成以下几个部分：
    （可选）一个符号字符（'+' 或 '-'）
    至少一位数字

部分数值列举如下：

    ["+100", "5e2", "-123", "3.1416", "-1E-16", "0123"]
部分非数值列举如下：

    ["12e", "1a3.14", "1.2.3", "+-5", "12e+5.4"]
*/
#include <vector>
#include <iostream>
using namespace std;

bool isNumber(string s) {
    // 统计 . 的出现次数
    int dot = 0, n = s.size();
    // 统计数字是否出现，以及 e 出现的次数
    int cnt = 0, cnte = 0;
    for(int i=0; i<n; i++){
        char c = s[i];
        // 为数字
        if(c>='0'&&c<='9') cnt++;
        // 为字符
        if(isalpha(c)) {
            // 但是不为 e 或 E，返回 false
            if(c!='e'&&c!='E') return 0;
        }
        // 为 '.'
        if(c=='.') {
            // 下一个为 +/-
            if(i+1<n&&(s[i+1]=='+'||s[i+1]=='-'))
                return 0;
            // ++
            dot++;
            // 很多个 '.' 返回 false
            if(dot>1) return 0;
        }
        // 为 +/-
        if(c=='+'||c=='-'){
            // 位置在最后，或者前一个为数字， 返回 false
            if(i==n-1||i>0&&isdigit(s[i-1])) return 0;
            else{
                // 后一个位置不能再为 +/-/空
                if(s[i+1]==' '||s[i+1]=='+'||s[i+1]=='-')
                    return 0;
            }
        }
        // 去掉 前缀空
        if(i==0&&c==' '){
            while(s[i]==' '&&i<n) i++;
            i--;
        }else if(c==' '){ // 后面是否有 空
            while(s[i]==' '&&i<n) i++;
            // 如果后缀全是 空 ， 判断前面是否有 数字
            if(i==n) return cnt>0?1:0;
            else  return 0; // 后缀不全为空 返回 false
        }
        if(c=='e'||c=='E'){
            cnte++; // 统计 e与E
            if(cnte>1) return 0; // 出现多个 返回 false
            // e/E 在最前面或最后面 以及 e/E 出现时前面没有数字，返回 false
            if(i==n-1||i==0||cnt==0) return 0;
            else{
                // 发现e/E后面有 '.' 返回false
                if(s.find('.', i+1)<n) return 0;
                // e/E 直接调用以上判断
                if(!isNumber(s.substr(i+1))) return 0;
            }
        }
    }
    // 是否出现数字
    if(cnt==0) return 0;
    return 1;
}
