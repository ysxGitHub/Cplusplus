/*
拓扑序：
    如果图中从V到W有一条有向路径，则V一定排在W之前。
    满足此条件的顶点序列称为一个拓扑序。
    获得一个拓扑序的过程就是拓扑排序。
    顶点活动网(AOV)如果有合理的拓扑序，
    则必定是有向无环图(DAG)

*/ 
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
 
void TopSort(vector<vector<int>> &G, int n, vector<int> &inDegree)
{
    int num = 0;
    queue<int> q;
    for (int i = 0; i < n; ++i)
    {
        // 入度为0的先入队列
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        // 得到度为0的
        int u = q.front();
        cout << u << " ";
        q.pop();
        // 去掉度为0的之后，找其相邻的下一个，将其进行度减
        for (size_t i = 0; i < G[u].size(); ++i)
        {
            int v = G[u][i];   // v is the successor vertices of u
            inDegree[v]--;
            // 入度为0的先入队列
            if (inDegree[v] == 0)
            {
                q.push(v);
            }
        }
        G[u].clear();  // clear all out edge of vertices u
        // 入度为0，顶点++
        num++;
    }
    cout << endl;
 
    if (num == n)
    {
        cout << "topological sorting successed";
    }
    else
    {
        cout << "there is a ring in the graph, can't do topological sorting";
    }
    return;
}
 
 
int main()
{
    int n, m;
    ifstream input("TopSort_Data.txt");
    input >> n >> m;
    vector<vector<int>> G(n);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        input >> x >> y;
        G[x].push_back(y);
    }
    cout << "the topological sorting is: " << endl;
    // 入度
    vector<int> inDegree(n);
    for (auto x : G)
    {
        for (auto y : x)
        {
            inDegree[y]++;
        }
    }

    TopSort(G, n, inDegree);
 
    return 0;
}
