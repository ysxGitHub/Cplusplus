/*
给你一个大小为 m x n 的二进制网格 grid 。网格表示一个地图，其中，0 表示水，1 表示陆地。
    最初，grid 中的所有单元格都是水单元格（即，所有单元格都是 0）。

可以通过执行 addLand 操作，将某个位置的水转换成陆地。给你一个数组 positions 
    ，其中 positions[i] = [ri, ci] 是要执行第 i 次操作的位置 (ri, ci) 。

返回一个整数数组 answer ，其中 answer[i] 是将单元格 (ri, ci) 转换为陆地后，地图中岛屿的数量。

岛屿 的定义是被「水」包围的「陆地」，通过水平方向或者垂直方向上相邻的陆地连接而成。
    你可以假设地图网格的四边均被无边无际的「水」所包围。

请仔细阅读下方示例与解析，更加深入了解岛屿的判定。

示例:

输入: m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]]
输出: [1,1,2,3]
解析:

起初，二维网格 grid 被全部注入「水」。（0 代表「水」，1 代表「陆地」）

0 0 0
0 0 0
0 0 0
操作 #1：addLand(0, 0) 将 grid[0][0] 的水变为陆地。

1 0 0
0 0 0 Number of islands = 1
0 0 0
操作 #2：addLand(0, 1) 将 grid[0][1] 的水变为陆地。

1 1 0
0 0 0 岛屿的数量为 1
0 0 0
操作 #3：addLand(1, 2) 将 grid[1][2] 的水变为陆地。

1 1 0
0 0 1 岛屿的数量为 2
0 0 0
操作 #4：addLand(2, 1) 将 grid[2][1] 的水变为陆地。

1 1 0
0 0 1 岛屿的数量为 3
0 1 0
拓展：

你是否能在 O(k log mn) 的时间复杂度程度内完成每次的计算？（k 表示 positions 的长度）
*/

#include<vector>
#include<unordered_map>
#include<iostream>

using namespace std;

class UnionFind{
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n){
        parent.resize(n,-1);
        rank.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }
    int findParent(int x){
        if(parent[x]!=x){
            parent[x] = findParent(parent[x]);
        }
        return parent[x];
    }
    // bool isConnect(int x, int y){
    //     if(findParent(x)==findParent(y)){
    //         return true;
    //     }else{
    //         return false;
    //     }
    // }
    int Union(int x, int y){
        int x_root = findParent(x);
        int y_root = findParent(y);

        if(x_root == y_root){return y_root;}

        if(rank[x_root]>rank[y_root]){
            parent[y_root] = x_root;
        }
        else if(rank[x_root]<rank[y_root]){
            parent[x_root] = y_root;
        }else{
            parent[y_root] = x_root;
            rank[x_root]++;
        }
        return -1;
    }


};


vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
    int len = positions.size();
    vector<int> ans(len, 0);
    UnionFind uf(m*n);
    vector<vector<int>>offset = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<int>land(m*n, 0);

    for(int i=0; i<len; i++){
        unordered_map<int, int>posParent;
        // 将要成为陆地的坐标
        int x = positions[i][0];
        int y = positions[i][1];
        int cur = x * n + y;
        // 已经遍历过
        if(land[cur]){
            ans[i] = ans[i-1];
            continue; 
        }
        // 标记一下
        land[cur]=1;
        for(int k=0; k<4; k++){
            int a = x + offset[k][0];
            int b = y + offset[k][1];
            if(a<0||b<0||a>=m||b>=n){continue; }
            // 隔壁也是陆地
            if(land[a * n + b]){
                // 将要成为陆地的位置 与 隔壁 是否有共同 parent
                posParent[uf.Union(cur, a * n + b)]++;
            }
            
        }
        // 旁边都不是陆地，或者第一个成为陆地
        if(posParent.size()==0){
            if(i!=0){
                ans[i] = ans[i-1] + 1;
            }else{
                ans[i] = 1;
            }
        }else{
            // 旁边是陆地的个数，但是没有连在一起，但是插入当前陆地就会连在一起了
            ans[i] = ans[i-1] - posParent[-1] + 1;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> positions = {{7,0}};
    vector<int> ans = numIslands2(8, 2, positions);
    for(int n: ans){
        cout<<n<<", ";
    }
    return 0;
}
