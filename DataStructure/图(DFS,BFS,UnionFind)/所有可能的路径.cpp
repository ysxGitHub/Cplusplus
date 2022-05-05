/*
给你一个有 n 个节点的 有向无环图（DAG），请你找出所有从节点 0 到节点 n-1 的路径并输出
    （不要求按特定顺序）

graph[i] 是一个从节点 i 可以访问的所有节点的列表（即从节点 i 到节点 graph[i][j]存在一条有向边）

*/

#include<vector>
#include<iostream>
using namespace std;


vector<vector<int>>ans;
void traverse(vector<vector<int>>& graph, int s, vector<int>& onPath){
    onPath.push_back(s);
    // 最后一个点时
    if(s==graph.size()-1){
        ans.push_back(onPath);
        onPath.pop_back();
        return ;
    }

    for(auto&n : graph[s]){
        traverse(graph, n, onPath);
    }
    onPath.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<int>onPath;
    traverse(graph, 0, onPath);
    return ans;
}

int main(int argc, char const *argv[])
{
    /*
    0->1,2
    1->3
    2->3
    */
    vector<vector<int>> graph = {{1,2},{3},{3},{}};

    allPathsSourceTarget(graph);
    return 0;
}
