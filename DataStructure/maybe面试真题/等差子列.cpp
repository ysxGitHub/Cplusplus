/**
 * 对于两个单调递增整数序列s1, s2, 在其中可能存在这样的子序列ss1, ss2, 
 * 对于任意元素ss1[i+1]-ss1[i]= ss2[i+1]-ss2[i], 
 * 请找出这样子序列中元素个数最多的子序列。
 * 子序列定义：对于长度为N的子序列S, 从其中删除n个元素后得到一个子序列SS
 *
 * 给定两个单调递增序列，单个元素取值范围 -10^9 < ss[i] < 10^9
 * 如果能找到子序列，则第一行输出子序列长度，第二三行输出子序列
 * 如果有多个满足条件的子序列，输出元素最小子序列
 * 如果找不到子序列，输出0即可
 * 输入：
 * 1 2 3 4 5
 * 2 4 6 8
 * 输出：
 * 3
 * 1 3 5
 * 2 4 6
 */
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<iostream>
using namespace std;

int correspondSubseq(vector<int>&s1, vector<int>&s2, vector<int>&ss1, vector<int>&ss2){
    unordered_map<int, vector<pair<int, int>>>hash;
    int MaxLen = 0;
    int pos = INT32_MAX;
    for(auto&m: s1){
        for(auto&n: s2){
            hash[m-n].push_back(make_pair(m,n));
        }
    }
    for(auto&h : hash){
        if((MaxLen<h.second.size())||(MaxLen==h.second.size()&&pos>h.first)){
            MaxLen = h.second.size();
            pos = h.first;
        }
    }
    for(auto&c : hash[pos]){
        ss1.push_back(c.first);
        ss2.push_back(c.second);
    }
    sort(ss1.begin(), ss1.end());
    sort(ss2.begin(), ss2.end());

    return hash[pos].size();
}


int main(int argc, char const *argv[])
{
    vector<int>s1={1,2,3,4,5};
    vector<int>s2={2,4,6,8};
    vector<int>ss1;
    vector<int>ss2;
    cout<<correspondSubseq(s1, s2, ss1, ss2);
    return 0;
}
