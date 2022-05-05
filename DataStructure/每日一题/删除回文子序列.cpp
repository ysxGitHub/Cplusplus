/*
题目有点问题

给你一个字符串 s，它仅由字母 'a' 和 'b' 组成。
   每一次删除操作都可以从s中删除一个回文子序列。

返回删除给定字符串中所有字符（字符串为空）的最小删除次数。

「子序列」定义：如果一个字符串可以通过删除原字符串某些字符而不改变原字符顺序得到，
    那么这个字符串就是原字符串的一个子序列。

「回文」定义：如果一个字符串向后和向前读是一致的，那么这个字符串就是一个回文。
*/


#include<bits/stdc++.h>
using namespace std;


int PalindromeLeng(string s, int l, int r){
    while((l>=0) && (r<s.length()) && (s[l]==s[r])){
        l--;
        r++;
    }
    return r-l-1;
}
int removePalindromeSub(string s) {
    int nums = 0;
    while (!s.empty()){
        int maxlen=0;
        int start=0;
        for(int i=0; i<s.length(); i++){
            int curmax = max(PalindromeLeng(s, i, i+1), PalindromeLeng(s, i, i));
            if(curmax>maxlen){
                maxlen = curmax;
                start = i - (curmax+1)/2 + 1; 
            }
        }
        s.erase(start, maxlen);
        cout<<s<<endl;
        nums++;
    }
    return nums;
}

int removePalindromeSub1(string s) {
    if(s.empty()==true){
        return 0 ;
    }else{
        int i=0;
        int j=s.size()-1;
        while (j>=0){
            if(s[i++]!=s[j--]){
                return 2;
            }
        }
        return 1;
    }

}



int main(int argc, char const *argv[])
{
    string s="ababa";
    
    cout<<removePalindromeSub1(s)<<endl;
    return 0;
}
