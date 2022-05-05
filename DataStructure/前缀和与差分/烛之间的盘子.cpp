/*
给你一个长桌子，桌子上盘子和蜡烛排成一列。给你一个下标从 0 开始的字符串 s ，
    它只包含字符 '*' 和 '|' ，其中 '*' 表示一个 盘子 ，'|' 表示一支 蜡烛 。

同时给你一个下标从 0 开始的二维整数数组 queries ，其中 queries[i] = [lefti, righti] 表示 
    子字符串 s[lefti...righti] （包含左右端点的字符）。对于每个查询，
    你需要找到 子字符串中 在 两支蜡烛之间 的盘子的 数目 。如果一个盘子在 子字符串中 左边和右边 
    都 至少有一支蜡烛，那么这个盘子满足在 两支蜡烛之间 。

比方说，s = "||**||**|*" ，查询 [3, 8] ，表示的是子字符串 "*||**|" 。
    子字符串中在两支蜡烛之间的盘子数目为 2 ，子字符串中右边两个盘子在它们左边和右边 都 至少有一支蜡烛。
请你返回一个整数数组 answer ，其中 answer[i] 是第 i 个查询的答案。
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
    int n = s.size();
    vector<int>ans;
    vector<int> plateSum(n, 0);
    vector<int>left(n, -1), right(n, -1);
    for(int i=1; i<n; i++){
        if(s[i-1]=='*'){
            plateSum[i] = plateSum[i-1] + 1;
        }else{
            plateSum[i] = plateSum[i-1];
        }
    }
    
    left[0] = s[0]=='|' ? 0 : -1;

    for(int i=1; i<n; i++){
        if(s[i]=='|'){
            left[i] = i;
        }else{
            left[i] = left[i-1];
        }
    }

    right[n-1] = s[n-1] == '|' ? n-1 : -1;
    for(int i=n-2; i>=0; i--){
        if(s[i]=='|'){
            right[i] = i;
        }else{
            right[i] = right[i+1]; 
        }
    }

    for(int i=0; i<queries.size(); i++){
        int l = right[queries[i][0]];
        int r = left[queries[i][1]];
        if(l>=r||l==-1||r==-1){
            ans.emplace_back(0);
        }else{
            ans.emplace_back(plateSum[r]-plateSum[l]);
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> queries={{1,2},{1,9},{6,12}};
    vector<int> ans = platesBetweenCandles("***|***|****|",queries);
    for (size_t i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<", ";
    }
    
    return 0;
}
