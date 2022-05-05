/*
有一个 m × n 的矩形岛屿，与 太平洋 和 大西洋 相邻。 “太平洋” 处于大陆的左边界和上边界，而 “大西洋” 处于大陆的右边界和下边界。

这个岛被分割成一个由若干方形单元格组成的网格。给定一个 m x n 的整数矩阵 heights ， heights[r][c] 表示坐标 (r, c) 上单元格 高于海平面的高度 。

岛上雨水较多，如果相邻单元格的高度 小于或等于 当前单元格的高度，雨水可以直接向北、南、东、西流向相邻单元格。水可以从海洋附近的任何单元格流入海洋。

返回 网格坐标 result 的 2D列表 ，其中 result[i] = [ri, ci] 表示雨水可以从单元格 (ri, ci) 流向 太平洋和大西洋 。

*/

#include<iostream>
#include<vector>
using namespace std;

static const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(vector<vector<int>>& heights, int row, int col, vector<vector<bool>> & ocean) {
    int m = ocean.size();
    int n = ocean[0].size();
    if (ocean[row][col]) {
        return;
    }
    ocean[row][col] = true;
    for(auto&dir : dirs){
        int newRow = row + dir[0], newCol = col + dir[1];
        if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && heights[newRow][newCol] >= heights[row][col]) {
            dfs(heights, newRow, newCol, ocean);
        }
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int m = heights.size();
    int n = heights[0].size();
    vector<vector<bool>> pacific(m, vector<bool>(n, false));
    vector<vector<bool>> atlantic(m, vector<bool>(n, false));
    // j=0 靠近 pacific ocean
    for (int i = 0; i < m; i++) {
        dfs(heights, i, 0, pacific);
    }
    // i=0 靠近 pacific ocean
    for (int j = 1; j < n; j++) {
        dfs(heights, 0, j, pacific);
    }
    // j=n-1 靠近 atlantic ocean
    for (int i = 0; i < m; i++) {
        dfs(heights, i, n - 1, atlantic);
    }
    // i=m-1 靠近 atlantic ocean
    for (int j = 0; j < n - 1; j++) {
        dfs(heights, m - 1, j, atlantic);
    }
    vector<vector<int>> result;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (pacific[i][j] && atlantic[i][j]) {
                result.push_back({i, j});
            }
        }
    }
    return result;
}

