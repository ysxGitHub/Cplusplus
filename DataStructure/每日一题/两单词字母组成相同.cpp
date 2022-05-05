/*
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
*/
#include<iostream>
#include<cstring>
using namespace std;


bool anagram(string t, string s){
    int slen1 = t.length();
    int slen2 = s.length();
    int num1[26] = {0};
    int num2[26] = {0};
    if(slen1!=slen2){
        return false;
    }else{
        for(int i=0; i<slen1; i++){
            num1[t[i]-'a']+=1;
            num2[s[i]-'a']+=1;
        }
        for(int j=0; j<26; j++){
            if(num1[j]!=num2[j]){
                return false;
            }
        }
        return true;
    }
}




int main(int argc, char const *argv[])
{
    string str1 = "abababa";
    string str2 = "bbbaaaa";
    cout<<anagram(str1, str2);
    return 0;
}


