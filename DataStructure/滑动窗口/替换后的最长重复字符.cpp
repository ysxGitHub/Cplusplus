/*
给你一个字符串 s 和一个整数 k 。你可以选择字符串中的任一字符，并将其更改为任何其他大写英文字符。
    该操作最多可执行 k 次。

在执行上述操作后，返回包含相同字母的最长子字符串的长度。
*/

/*思路
当 K>0 时，子串的条件变成了允许我们变换子串中的 K 个字符使其变成一个连续子串

那么这个题的关键点就是我们如何判断一个字符串改变 K 个字符，能够变成一个连续串

如果当前字符串中的出现次数最多的字母个数 +K 大于串长度，那么这个串就是满足条件的

我们维护一个数组 int[26] 来存储当前窗口中各个字母的出现次数，left 表示窗口的左边界，
    right 表示窗口右边界

窗口扩张：left 不变，right++
窗口滑动：left++，right++
historyCharMax 保存滑动窗口内相同字母出现次数的 历史 最大值，
    通过判断窗口宽度 (right - left + 1)是否大于 
    historyCharMax + K 来决定窗口是否做滑动，否则窗口就扩张。
*/

#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

int characterReplacement(string s, int k) {
    int n = s.size();
    int left = 0, maxlen = 0;
    unordered_map<char, int>cnt;
    for(int right = 0; right<n; right++){
        int ch = s[right] - 'A';
        cnt[ch]++;
        // 记录当前最长重复的字符
        maxlen = max(maxlen, cnt[ch]);
        // 如果窗口的长度大于 当前最长重复的字符 + k 则就滑动窗口
        if(right - left + 1 > maxlen + k){
            // 把不在窗口的字符减去
            cnt[s[left] - 'A']--;
            left++;
        }
    }
    // 返回现在的窗口大小
    return n - left;
}

int main(int argc, char const *argv[])
{
    cout<<characterReplacement("ABBBB",0);
    return 0;
}
