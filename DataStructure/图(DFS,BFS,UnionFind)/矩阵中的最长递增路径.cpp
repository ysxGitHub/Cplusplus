/*
给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。

对于每个单元格，你可以往上，下，左，右四个方向移动。 你 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。
*/

#include <vector>
#include <queue>
using namespace std;

// 记忆化深度优先搜索
const vector<vector<int>>offset={{1,0}, {0,1}, {-1,0}, {0,-1}};
int backtrace(vector<vector<int>>& matrix, vector<vector<int>>& seen, int x, int y){
    if(seen[x][y]!=0) return seen[x][y];
    ++seen[x][y];
    for(const auto&offs: offset){
        int i = offs[0]+x, j = offs[1]+y;
        if(i>=0&&i<matrix.size()&&j>=0&&j<matrix[0].size()&&matrix[x][y]<matrix[i][j]){
            seen[x][y] = max(backtrace(matrix, seen, i, j)+1, seen[x][y]);
        }
    }
    return seen[x][y];
}
int longestIncreasingPath(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int ans = 1;
    vector<vector<int>>seen(m, vector<int>(n, 0));
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            ans = max(ans, backtrace(matrix, seen, i, j));
        }
    }
    return ans;
}


// 拓扑排序
static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int rows, columns;

int longestIncreasingPath(vector< vector<int> > &matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0) {
        return 0;
    }
    rows = matrix.size();
    columns = matrix[0].size();
    auto outdegrees = vector< vector<int> > (rows, vector <int> (columns));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            for (int k = 0; k < 4; ++k) {
                int newRow = i + dirs[k][0], newColumn = j + dirs[k][1];
                if (newRow >= 0 && newRow < rows && newColumn >= 0 && newColumn < columns && matrix[newRow][newColumn] > matrix[i][j]) {
                    ++outdegrees[i][j];
                }
            }
        }
    }
    queue < pair<int, int> > q;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (outdegrees[i][j] == 0) {
                q.push({i, j});
            }
        }
    }
    int ans = 0;
    while (!q.empty()) {
        ++ans;
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            auto cell = q.front(); q.pop();
            int row = cell.first, column = cell.second;
            for (int k = 0; k < 4; ++k) {
                int newRow = row + dirs[k][0], newColumn = column + dirs[k][1];
                if (newRow >= 0 && newRow < rows && newColumn >= 0 && newColumn < columns && matrix[newRow][newColumn] < matrix[row][column]) {
                    --outdegrees[newRow][newColumn];
                    if (outdegrees[newRow][newColumn] == 0) {
                        q.push({newRow, newColumn});
                    }
                }
            }
        }
    }
    return ans;
}
