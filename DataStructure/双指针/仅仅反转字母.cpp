/*
给你一个字符串 s ，根据下述规则反转字符串：

所有非英文字母保留在原有位置。
所有英文字母（小写或大写）位置反转。
返回反转后的 s 。
*/
#include<iostream>

using namespace std;

string reverseOnlyLetters(string s) {
    int i=0, j=s.size()-1;
    while(i<j){
        if(isalpha(s[i])&&isalpha(s[j])){
            swap(s[i], s[j]);
            ++i, --j;
        }
        else if(!isalpha(s[i])&&!isalpha(s[j])){++i, --j;}
        else if(isalpha(s[i])&&!isalpha(s[j])){--j;}
        else{++i;}
    }
    return s;
}

