/*
给定一个非空 01 二维数组表示的网格，一个岛屿由四连通（上、下、左、右四个方向）的 1 组成，
    你可以认为网格的四周被海水包围。

请你计算这个网格中共有多少个形状不同的岛屿。两个岛屿被认为是相同的，
    当且仅当一个岛屿可以通过平移变换（不可以旋转、翻转）和另一个岛屿重合。

示例 1：
11000
11000
00011
00011
给定上图，返回结果 1 。

示例 2：
11011
10000
00001
11011
给定上图，返回结果 3 。

注意：
    11
    1
    和

    1
    11
    是不同的岛屿，因为我们不考虑旋转、翻转操作。
*/

#include<vector>
#include<iostream>
#include<unordered_set>
using namespace std;


// bfs 序列化遍历
vector<vector<int>>offset = {{1,0}, {0,1}, {-1,0}, {0,-1}}; 
void bfs(vector<vector<int>>& grid, int m, int n, int i, int j, string& path, int dir){
    grid[i][j] = 2;
    path += to_string(dir) + ',';
    for(int k=0; k<offset.size(); k++){
        int x = offset[k][0]+i, y = offset[k][1]+j;
        if(x>=0&&x<m&&y>=0&&y<n){
            if(grid[x][y]==1){
                path += to_string(k);
                bfs(grid, m, n, x, y, path, k);
                path += to_string(-k);
            }
        }
    }
    path += to_string(dir);
    return ;
}


int numDistinctIslands(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    unordered_set<string> ans;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]==1){
                string tmp;
                bfs(grid, m, n, i, j, tmp, 666);
                if(!tmp.empty()) ans.insert(tmp);
            }
        }
    }
    return ans.size();
}