/*
在给定的 m x n 网格 grid 中，每个单元格可以有以下三个值之一：
    值 0 代表空单元格；
    值 1 代表新鲜橘子；
    值 2 代表腐烂的橘子。
每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。

返回 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1 。
*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;


int orangesRotting(vector<vector<int>>& grid) {
    int ans = 0;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> offset = {{1,0},{-1,0},{0,1},{0,-1}};
    
    queue<pair<int, int>>badGrid;

    int cntGood = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]==2){
                // 将坏橘子加入，相当于多个起点
                badGrid.emplace(i,j);
            }
            if(grid[i][j]==1){
                cntGood++;
            }
        }
    }
    if(cntGood==0){return 0;}
    if(badGrid.empty()){return -1; }

    // bfs
    while(!badGrid.empty()){
        bool used = false;
        int size = badGrid.size();
        // 进行每一层的遍历
        for(int i=0; i<size; i++){
            auto bad = badGrid.front();
            badGrid.pop();
            for(int k=0; k<4; k++){
                int x = bad.first + offset[k][0];
                int y = bad.second + offset[k][1];
                if(x<0||y<0||x>=m||y>=n||grid[x][y]==0||grid[x][y]==2){
                    continue;
                }
                grid[x][y] = 2;
                used = true;
                badGrid.emplace(x, y);
            }
        }
        if(used) ans++;
    }


    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]==1){
                return -1;
            }
        }
    }

    return ans;

}

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid={{2,1,1},{1,1,0},{0,1,2}};
    cout<<orangesRotting(grid);
    return 0;
}
