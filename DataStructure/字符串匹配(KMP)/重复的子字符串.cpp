/*
给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。
*/

#include<iostream>
#include<vector>
using namespace std;
// namespace std;

/*
s = 'abab'
s + s = 'abababab'

s = 'aba'
s + s = 'abaaba' 
*/ 
// 方法1：string.find()
bool repeatedSubstringPattern(string s) {
    return (s+s).find(s, 1)!=s.size(); 
}

// 方法2：KMP
vector<int> Next(string s){
    int len = s.length();
    vector<int>next(len, -1);
    int i = -1;
    for(int j=1; j<len; j++){
        // 状态变量 i 需要一直转移到 相等s[i+1]!=s[j], 或者 i = -1
        while((i>=0)&&(s[i+1]!=s[j])){
            i = next[i];
        }
        // 如果 相等 则当前状态变量 j 的转移量为 i + 1
        if(s[i+1]==s[j]){
            i++;   
        }
        next[j] = i;
        // 如果 没有相等 则当前状态变量 j 的转移量为 -1（最开始的位置）
    }
    return next;
}


int subStr(string haystack, string needle, int front){
    int i=front, j=0;
    int hlen = haystack.length();
    int nlen = needle.length();
    vector<int>next =  Next(needle);
    while(i<hlen){
        while(j>0 && haystack[i]!=needle[j]){
            j = next[j-1] + 1;
            if(hlen - i < nlen - j) return -1;
        }
        // 相等 继续 比较下一个
        if(haystack[i]==needle[j]){
            i++;
            j++;
        }
        if(j==nlen) return i - j + 1;
    }
    return -1;
}

bool repeatedSubstringPattern1(string s) {
    return subStr(s+s, s, 1)==s.length()?0:1;
}

int main(int argc, char const *argv[])
{
    cout<<repeatedSubstringPattern("abab");
    return 0;
}
