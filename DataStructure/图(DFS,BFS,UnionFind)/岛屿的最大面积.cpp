/*
给你一个大小为 m x n 的二进制矩阵 grid 。

岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在 
    水平或者竖直的四个方向上 相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。

岛屿的面积是岛上值为 1 的单元格的数目。

计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。

*/

#include<vector>
#include<iostream>

using namespace std;

vector<vector<int>>offset = {{1,0}, {0,1}, {-1,0}, {0,-1}}; 
void bfs(vector<vector<int>>& grid, int m, int n, int i, int j, int& cnt){
 
    grid[i][j] = 2;
    cnt++;

    for(auto o: offset){
        int x = o[0]+i, y = o[1]+j;
        if(x>=0&&x<m&&y>=0&&y<n){
            if(grid[x][y] == 1){
                bfs(grid, m, n, x, y, cnt);
            }
        }
    }
    return ;
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int ans = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]==1){
                int cnt = 0;
                bfs(grid, m, n, i, j, cnt);
                ans = max(ans, cnt);
            }
        }
    }
    return ans;
}