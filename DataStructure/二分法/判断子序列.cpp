/*
给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。
    （例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

进阶：
如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。
    在这种情况下，你会怎样改变代码？

*/
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;


bool isSubsequence1(string s, string t) {
    int i=0, j=0;
    int m = s.size(), n = t.size();
    while(i<m&&j<n){
        if(s[i]==t[j]) i++;
        j++;
    }
    return i==m;
}


int left_bound(vector<int>& arr, int tar){
    int lo = 0, hi = arr.size()-1;
    while(lo<=hi){
        int mid = (lo + hi)/2;
        if(tar>arr[mid]){
            lo = mid + 1;
        }else {
            hi = mid - 1;
        }
    }
    return lo;
}

// 位操作
bool isSubsequence(string s, string t) {
    int m = s.size(), n = t.size();
    // 记录t中每一个元素位置，相同元素位置放在一起
    vector<vector<int>>charToIdx(26);
    for(int i=0; i<n; i++){
        int ch = t[i] - 'a';
        charToIdx[ch].emplace_back(i);
    }

    int j = 0;
    for(int i=0; i<m; i++){
        int ch = s[i] - 'a';
        if(charToIdx[ch].size()==0) return false;
        int pos = left_bound(charToIdx[ch], j);
        if(pos == charToIdx[ch].size()) return false;
        j = charToIdx[ch][pos] + 1;
    }
    return true;
}

int main(int argc, char const *argv[])
{

    return 0;
}
