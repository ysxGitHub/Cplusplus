/*
给你一个正整数 n ，请你找出符合条件的最小整数，其由重新排列 n 中存在的每位数字组成，并且其值大于 n 。
    如果不存在这样的正整数，则返回 -1 。

注意 ，返回的整数应当是一个 32 位整数 ，如果存在满足题意的答案，但不是 32 位整数 ，同样返回 -1 。

*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

using namespace std;

int nextGreaterElement(int n){
    if(n<=11) return -1;
    
    string s = to_string(n);
    int len = s.size();
    int i = len - 2;

    while (i>=0 && s[i+1] <= s[i]) i--;
    // 从后向前不能一直递增，找到第一个递减的数值a
    if (i<0) return -1;
    int j = len - 1;
    // 找到递增阶段比a大一点点的数值b, 等于的也要跳过
    while (j>=0 && s[j] <= s[i]) j--;
    // 交换a与b
    swap(s[i],s[j]);
    // 并且反转a后面的数字
    reverse(s.begin()+i+1, s.end());
    long res = stol(s);
    return res > INT_MAX ? -1 : res;
}

int main(int argc, char const *argv[])
{
    cout<<nextGreaterElement(230241)<<endl;
    return 0;
}

