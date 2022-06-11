/*
给定一个字符串 s ，找出 至多 包含两个不同字符的最长子串 t 。

示例 1:
输入: "eceba"
输出: 3
解释: t 是 "ece"，长度为3。

示例 2:
输入: "ccaabbb"
输出: 5
解释: t 是 "aabbb"，长度为5。

// 一样 904:水果成栏
*/

#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstringTwoDistinct(string s) {
    unordered_map<char, int>cnt;
    int n = s.size(), left = 0;
    int sum=0, ans = 0;
    for(int right=0; right<n; ++right){
        cnt[s[right]]++;
        sum++;
        while(cnt.size()>2){
            int f = s[left++];
            cnt[f]--;
            sum--;
            if(cnt[f]==0) cnt.erase(f);
        }
        ans = max(ans, sum);
    }
    return ans;
}

