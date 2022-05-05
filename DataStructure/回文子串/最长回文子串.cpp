/*
「回文」定义：如果一个字符串向后和向前读是一致的，那么这个字符串就是一个回文。
*/

#include<bits/stdc++.h>
using namespace std;

// 中心扩散法
int PalindromeLen(string s, int l, int r){
    while (l>=0 && r<s.length() && s[l]==s[r]){
        l--;
        r++;
    }
    return (r - l - 1);
}


string longestPalindrome1(string s) {
    if(s.length()<=1){
        return s;
    }
    else{
        int slen=0;
        int start=0;
        for(int i=0; i<s.length(); i++){
            // 以 s[i] 为中心的最长回文子串  // 以 s[i] 和 s[i+1] 为中心的最长回文子串
            int maxlen = max(PalindromeLen(s, i, i), PalindromeLen(s, i, i+1));
            
            if(maxlen>slen){
                slen = maxlen;
                start = i - (slen+1)/2 +1;
                // cout<<start<<"  "<<slen<<"  "<<i<<endl;
            }
        }
        return s.substr(start, slen);
    }
}


//动态规划
string longestPalindrome(string s) {
    /*
    s = "abcba";
    dp[][]=
          i 0 1 2 3 4
        j 0 1    
          1 0 1
          2 0 0 1
          3 0 1 0 1
          4 1 0 0 0 1

    */
    int len = s.length();
    if(len<=1){
        return s;
    }
    else{
        int maxlen = 1;
        int start = 0;
        vector<vector<bool>>dp(len, vector<bool>(len,false));
        for(int i=0; i<len; i++){
            dp[i][i] = true;
        }
        for(int j=1; j<len; j++){
            for(int i=0; (i<len-1)&&(i<j); i++){
                if(s[i]!=s[j]){
                    dp[i][j] = false;
                }else{
                    if(j-i < 3){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
                if(dp[i][j] && (j - i + 1)>maxlen){
                    // cout<<maxlen<<endl;
                    maxlen = j-i+1;
                    start = i;
                }
            }
        }
        // for(auto n: dp){
        //     for(auto d: n){
        //         cout<<d<<"  ";
        //     }
        //     cout<<endl;
        // }
        return s.substr(start, maxlen);
    }
}



int main(int argc, char const *argv[])
{
    string s = "abcddcba";
    cout<<longestPalindrome(s)<<endl;
    cout<<longestPalindrome1(s)<<endl;
    return 0;
}


