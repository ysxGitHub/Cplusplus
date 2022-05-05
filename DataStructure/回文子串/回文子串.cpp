/*
给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。

回文字符串 是正着读和倒过来读一样的字符串。

子字符串 是字符串中的由连续字符组成的一个序列。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
*/

#include<iostream>
using namespace std;

int countSubstrings(string s) {
    int n = s.size();
    int num=0;
    for(int i=0; i<n; i++){
        // 分别对应一个中心点，或两个中心点
        for(int j=0; j<2; j++){
            int l = i, r = i+j;
            while(l>=0&&r<n&&s[l--]==s[r++]) num++;
        }
    }
    return num;
}

bool isPalindrome(string& s){
    if(s.size()==1) return 1;
    int num=0, n=s.size();
    if(n%2){
        int l=n/2-1, r=n/2+1;
        while(l>=0&&r<n&&s[l--]==s[r++]) num++;
        if(num==n/2) return 1;
        else return 0;
    }else{
        int l=n/2-1, r=n/2;
        while(l>=0&&r<n&&s[l--]==s[r++]) num++;
        if(num==n/2) return 1;
        else return 0;
    }
}

int main(int argc, char const *argv[])
{
    string s = "abcd";
    cout<<isPalindrome(s)<<endl;
    int n = s.size();
    for(int j=0; j<n; j++){
        for(int i=1; i+j<=n; i++){
            cout<<s.substr(j,i)<<endl;

        }
    }
    return 0;
}
