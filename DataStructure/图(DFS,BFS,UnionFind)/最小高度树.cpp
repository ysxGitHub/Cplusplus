/*
树是一个无向图，其中任何两个顶点只通过一条路径连接。 换句话说，一个任何没有简单环路的连通图都是一棵树。

给你一棵包含 n 个节点的树，标记为 0 到 n - 1 。给定数字 n 和一个有 n - 1 条无向边的 edges 列表
    （每一个边都是一对标签），其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间存在一条无向边。

可选择树中任何一个节点作为根。当选择节点 x 作为根节点时，设结果树的高度为 h 。在所有可能的树中，
    具有最小高度的树（即，min(h)）被称为 最小高度树 。

请你找到所有的 最小高度树 并按 任意顺序 返回它们的根节点标签列表。

树的 高度 是指根节点和叶子节点之间最长向下路径上边的数量。

*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;


/*
从边缘开始，先找到所有度为1的节点，然后把所有度为1的节点进队列，然后不断地bfs，
    最后找到的就是两边同时向中间靠近的节点，那么这个中间节点就相当于把整个距离二分了，
    那么它当然就是到两边距离最小的点啦，也就是到其他叶子节点最近的节点了。
*/
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if(n==1){
        return {0};
    }
    vector<vector<int>>graph(n, vector<int>());
    vector<int>degree(n, 0);
    for(auto& e: edges){
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
        degree[e[0]]++;
        degree[e[1]]++;
    }
    queue<int>que;
    for(int i=0; i<n; i++){
        // 将叶节点入队列
        if(degree[i]==1){
            que.push(i);
        }
    }
    vector<int>res;
    while(!que.empty()){
        int size = que.size();
        res.clear();
        // 一次性弹出所以的叶节点
        for(int j=0; j<size; j++){
            int v = que.front();
            que.pop();
            res.push_back(v);
            degree[v]--;
            // 加入下一次的叶节点
            for(auto&n : graph[v]){
                degree[n]--;
                if(degree[n]==1){
                    que.push(n);
                }
            }
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int n = 6;
    vector<vector<int>> edges = {{3,0},{3,1},{3,2},{3,4},{5,4}};
    findMinHeightTrees(n, edges);

    return 0;
}

