/*
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。
*/
#include<vector>
#include<iostream>

using namespace std;

vector<vector<int>>offset = {{1,0}, {0,1}, {-1,0}, {0,-1}}; 
void bfs(vector<vector<char>>& grid, int m, int n, int i, int j){
    grid[i][j] = 'x';
    for(auto o: offset){
        int x = o[0]+i, y = o[1]+j;
        if(x>=0&&x<m&&y>=0&&y<n){
            if(grid[x][y]=='1'){
                bfs(grid, m, n, x, y);
            }
        }
    }
    return ;
}

int numIslands(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int ans = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]=='1'){
                ans++;
                bfs(grid, m, n, i, j);
            }
        }
    }
    return ans;
}