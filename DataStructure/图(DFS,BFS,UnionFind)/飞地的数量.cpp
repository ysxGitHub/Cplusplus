/*
给你一个大小为 m x n 的二进制矩阵 grid ，其中 0 表示一个海洋单元格、1 表示一个陆地单元格。
一次 移动 是指从一个陆地单元格走到另一个相邻（上、下、左、右）的陆地单元格或跨过 grid 的边界。
返回网格中 无法 在任意次数的移动中离开网格边界的陆地单元格的数量
*/
#include<vector>
#include<iostream>
using namespace std;

void DFS(vector<vector<int>>& grid, int row, int col, int i, int j){
    if(i<0||i>=row||j<0||j>=col||grid[i][j]==0){
        return;
    }
    grid[i][j]=0;
    DFS(grid, row, col, i, j+1);
    DFS(grid, row, col, i, j-1);
    DFS(grid, row, col, i+1, j);
    DFS(grid, row, col, i-1, j);
}

int numEnclaves(vector<vector<int>>& grid) {
    int res=0;
    int row = grid.size();
    int col = grid[0].size();
    for(int i=0; i<row; i++)
    {
        DFS(grid, row, col, i, 0);
        DFS(grid, row, col, i, col-1);
    }
    for(int j=0; j<col; j++)
    {
        DFS(grid, row, col, 0, j);
        DFS(grid, row, col, row-1, j);
    }
    for(int m=0; m<row; m++){
        for(int n=0; n<col; n++){
            if(grid[m][n]==1){
                res++;
            }
        }
    }
    return res;
}


/*********利用并查集*********/
int findParent(vector<int>&parent, int x){
    if(parent[x]!=x){
        parent[x] = findParent(parent, parent[x]);
    }
    return parent[x];
}

void unionVer(vector<int>&parent, vector<int>&rank, vector<bool>&onedge, int x, int y){
    int x_root = findParent(parent, x);
    int y_root = findParent(parent, y);
    if(rank[x_root]>rank[y_root]){
        parent[y_root] = x_root;
        onedge[x_root] = onedge[x_root]||onedge[y_root];
    }
    else if(rank[x_root]<rank[y_root]){
        parent[x_root] = y_root;
        onedge[y_root] = onedge[y_root]||onedge[x_root];
    }
    else{
        parent[y_root] = x_root;
        onedge[x_root] = onedge[x_root]||onedge[y_root];
        rank[x_root]++;
    }
}


int numEnclaves1(vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    vector<int>parent(m*n, -1);
    vector<int>rank(m*n, 0);
    vector<bool>onedge(m*n, 0);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int idx = i*n+j;
            parent[idx] = idx;
            if(i==0||j==0||i==m-1||j==n-1){
                onedge[idx] = true;
            }
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]==1){
                int idx = i*n+j;
                if(j+1<n&&grid[i][j+1]==1){
                    unionVer(parent, rank, onedge, idx, idx+1);
                }
                if(i+1<m&&grid[i+1][j]==1){
                    unionVer(parent, rank, onedge, idx, idx+n);
                }
            }
        }
    }
    int ans = 0;
    for(int i=1; i<m-1; i++){
        for(int j=1; j<n-1; j++){
            if(grid[i][j]==1&&onedge[findParent(parent, i*n+j)]==0){
                ans++;
            }
        }
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    vector<vector<int>> grid = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    // cout<<numEnclaves(grid);
    cout<<numEnclaves1(grid);
    return 0;
}
