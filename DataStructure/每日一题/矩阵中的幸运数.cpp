/*
给你一个 m * n 的矩阵，矩阵中的数字 各不相同 。请你按 任意 顺序返回矩阵中的所有幸运数。

幸运数是指矩阵中满足同时下列两个条件的元素：

在同一行的所有元素中最小
在同一列的所有元素中最大

*/

#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
#include<unordered_map>
using namespace std;

vector<int> luckyNumbers (vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<pair<int, int>>maxCol(n);
    for(int j=0; j<n; j++){
        for(int i=0; i<m; i++){
            if(matrix[i][j]>maxCol[j].first){
                maxCol[j] = make_pair(matrix[i][j], i);
            }
        }
    }
    for(auto&s: maxCol){
        // cout<<s.first<<" "<<s.second<<"***";
        int flag=0;
        for(int j=0; j<n; j++){
            if(s.first>matrix[s.second][j]){
                flag=1;
                continue;
            }
        }
        if(flag==0){
            return {s.first};
        }
    }
    return {};
}
int main(int argc, char const *argv[])
{
    unordered_map<int, int>mp;
    
    return 0;
}
