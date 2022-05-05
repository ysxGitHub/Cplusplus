/*
给你两个 m x n 的二进制矩阵 grid1 和 grid2 ，它们只包含 0 （表示水域）和 1 （表示陆地）。
    一个 岛屿 是由 四个方向 （水平或者竖直）上相邻的 1 组成的区域。任何矩阵以外的区域都视为水域。

如果 grid2 的一个岛屿，被 grid1 的一个岛屿 完全 包含，也就是说 grid2 中该岛屿的每一个格子都被 
    grid1 中同一个岛屿完全包含，那么我们称 grid2 中的这个岛屿为 子岛屿 。

请你返回 grid2 中 子岛屿 的 数目 。
*/

#include<vector>
#include<iostream>

using namespace std;

vector<vector<int>>offset = {{1,0}, {0,1}, {-1,0}, {0,-1}}; 
void bfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int m, int n, int i, int j, bool& flag){
    
    grid2[i][j] = 2;
    if(grid1[i][j]==0){
        flag = 1;
    }
     
    for(auto o: offset){
        int x = o[0]+i, y = o[1]+j;
        if(x>=0&&x<m&&y>=0&&y<n){
            if(grid2[x][y] == 1){
                bfs(grid1, grid2, m, n, x, y, flag);
            }
        }
    }
    return ;
}

int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int m = grid2.size(), n = grid2[0].size();
    int ans = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid2[i][j]==1){
                bool flag = 0;
                bfs(grid1, grid2, m, n, i, j, flag);
                if(!flag) ans++;
            }
        }
    }
    return ans;
}