/*
给定一种规律 pattern 和一个字符串 s ，判断 s 是否遵循相同的规律。

这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。

*/

#include<unordered_map>
#include<iostream>
#include<sstream>
using namespace std;

bool wordPattern(string pattern, string s) {
    if(s==pattern) return s.size()==1?true:false;
    unordered_map<char, string>p1;
    unordered_map<string, char>s1;
    stringstream ss(s);
    string t;
    int i = 0;
    while(ss>>t){
        char c = pattern[i++];
        if(p1.count(c)&&p1[c]!=t||s1.count(t)&&s1[t]!=c) return false;
        p1[c] = t;
        s1[t] = c;
    }
    return i==pattern.size()?true:false;
}