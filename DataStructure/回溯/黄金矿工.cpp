/*
你要开发一座金矿，地质勘测学家已经探明了这座金矿中的资源分布，并用大小为 m * n 的网格 grid 
    进行了标注。每个单元格中的整数就表示这一单元格中的黄金数量；如果该单元格是空的，那么就是 0。

为了使收益最大化，矿工需要按以下规则来开采黄金：

每当矿工进入一个单元，就会收集该单元格中的所有黄金。
矿工每次可以从当前位置向上下左右四个方向走。
每个单元格只能被开采（进入）一次。
不得开采（进入）黄金数目为 0 的单元格。
矿工可以从网格中 任意一个 有黄金的单元格出发或者是停止。

*/
#include<iostream>
#include<vector>
using namespace std;

/*
tips: 使用递归来尝试所有这些路径并找到具有最大值的路径。
*/

int ans = 0;
vector<vector<int>>chir={{-1,0},{1,0},{0,-1},{0,1}};
void dfs(vector<vector<int>>& grid, int i, int j, int r, int c, int glod){
    
    int rec = grid[i][j];
    // 当前的黄金 + 过去的黄金
    glod += rec; 
    // 比较一下最大的值
    ans = max(glod, ans);
    // 该点以及看到，过置为0
    grid[i][j] = 0;

    for(int k=0; k<4; k++){
        int ii = i + chir[k][0];
        int jj = j + chir[k][1];
        // 筛选合适的位置
        if(ii>=0&&ii<r&&jj>=0&&jj<c&&grid[ii][jj]!=0){
            dfs(grid, ii, jj, r, c, glod);
        }
    }
    // 回溯
    grid[i][j] = rec;
}

int getMaximumGold(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid[0].size();
    // 遍历所有的位置
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(grid[i][j]!=0){
                dfs(grid, i, j, row, col, 0);
            }
        }
    }

    return ans;
}


int main(int argc, char const *argv[])
{
    vector<vector<int>> grid={{0,6,0},{5,8,7},{0,9,0}};
    cout<<getMaximumGold(grid);

    return 0;
}
