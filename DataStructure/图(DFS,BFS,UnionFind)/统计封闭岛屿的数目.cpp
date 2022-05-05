/*
二维矩阵 grid 由 0 （土地）和 1 （水）组成。岛是由最大的4个方向连通的 0 组成的群，
    封闭岛是一个 完全 由1包围（左、上、右、下）的岛。

请返回 封闭岛屿 的数目。
*/

#include<vector>
#include<iostream>

using namespace std;

/*
与上题岛屿的数量类似，不要统计靠边界的岛屿数量
*/

vector<vector<int>>offset = {{1,0}, {0,1}, {-1,0}, {0,-1}}; 
void bfs(vector<vector<int>>& grid, int m, int n, int i, int j, bool& flag){
    // 靠边界的岛屿 标记一下
    if(i==0||i==m-1||j==0||j==n-1) flag = 1;
    grid[i][j] = 2;
    
    for(auto o: offset){
        int x = o[0]+i, y = o[1]+j;
        if(x>=0&&x<m&&y>=0&&y<n){
            if(grid[x][y] == 0){
                bfs(grid, m, n, x, y, flag);
            }
        }
    }
    return ;
}

int closedIsland(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int ans = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]==0){
                bool flag = 0;
                bfs(grid, m, n, i, j, flag);
                if(!flag) ans++;
            }
        }
    }
    return ans;
}