/*
给你一个points 数组，表示 2D 平面上的一些点，其中 points[i] = [xi, yi] 。

连接点 [xi, yi] 和点 [xj, yj] 的费用为它们之间的 曼哈顿距离 ：|xi - xj| + |yi - yj| ，
    其中 |val| 表示 val 的绝对值。

请你返回将所有点连接的最小总费用。只有任意两点之间 有且仅有 一条简单路径时，才认为所有点都已连接。
*/

#include<vector>
#include<iostream>
#include<queue>
#include<unordered_set>
#include<algorithm>

using namespace std;

class UnionFind{
public:

    UnionFind(int n){
        parent.resize(n, 0);
        rank.resize(n, 0);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
    }

    int findRoot(int x){
        if(parent[x]!=x){
            parent[x] = findRoot(parent[x]);
        }
        return parent[x];
    }

    bool isConnect(int x, int y){
        int x_root = findRoot(x);
        int y_root = findRoot(y); 
        if(x_root==y_root){
            return true;
        } 
        return false;
    }

    void unionVer(int x, int y){
        int x_root = findRoot(x);
        int y_root = findRoot(y); 

        if(rank[x_root]>rank[y_root]){
            parent[y_root] = x_root;
        }
        else if(rank[x_root]<rank[y_root]){
            parent[x_root] = y_root; 
        }
        else{
            parent[y_root] = x_root;
            rank[x_root]++;       
        }
    }
private:
    vector<int>parent;
    vector<int>rank;
};

struct cmp{
    bool operator()(vector<int>&a, vector<int>&b){
        return a.back()>b.back();
    }
};

// Kruskal算法与并查集一致
int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    // vector<vector<int>>edges;
    priority_queue<vector<int>, vector<vector<int>>, cmp>edges;
    // 先要生成所有的边和权重
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            vector<int>tmp;
            tmp.emplace_back(i);
            tmp.emplace_back(j);
            tmp.emplace_back(abs(points[i][0] - points[j][0])+abs(points[i][1] - points[j][1]));
            edges.emplace(tmp);
        }
    }

    UnionFind uf(n);
    // 生成树的边个数
    int remaining = n-1;  
    int cost = 0;  
    // sort(edges.begin(), edges.end(), cmp());

    while(!edges.empty())
    {
        vector<int> e = edges.top();
        edges.pop();
        if(!uf.isConnect(e[0], e[1])){
            uf.unionVer(e[0], e[1]);
            cost += e[2];
            if(!--remaining){
                break;
            }

        }
    }
    if(remaining){
        cost=-1;
    }
    return cost;
}


struct cmp1{
    bool operator()(pair<int, int>&a, pair<int, int>&b){
        return a.second>b.second;
    }
};

class Prim{
private:  
    // 记录哪些节点已经成为最小生成树的一部分   
    vector<bool> inMST;
    // 最小生成树以外的点距离小的放在上面
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp1>pq;
    // 
    vector<vector<pair<int, int>>>graph;
    // 记录最小距离
    int miniSum;
    // 节点数
    int n; 
    // 查找该节点的邻接点，放入pq中
    void cut(int s){
        for(auto&n : graph[s]){
            // 要不在MST中
            if(!inMST[n.first]){
                pq.push(n);
            }
        }
    }
public:
    Prim(vector<vector<pair<int, int>>>&edges){
        n = edges.size();
        graph = edges;
        inMST.resize(n, 0);
        miniSum = 0;
        // 先随机放入一个节点进入MST
        inMST[0]=true;
        cut(0);
        while(!pq.empty()){
            auto v = pq.top();
            pq.pop();
            // 邻接点不再MST中是
            if(!inMST[v.first]){
                // 加上该距离
                miniSum+=v.second;
                // 邻接点以访问
                inMST[v.first]=true;
                // 查找该邻接点的邻接点
                cut(v.first);
            }     
        }
    }
    bool isAllInMST(){
        for(int i=0; i<n; i++){
            if(!inMST[i]){
                return false;
            }
        }
        return true;
    }
    int getMinistSum(){
        return miniSum;
    }
};

int minCostConnectPoints1(vector<vector<int>>& points) {
    int n = points.size();
    vector<vector<pair<int, int>>>edges(n, vector<pair<int, int>>());
    // 先要生成所有的边和权重
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int cost = abs(points[i][0] - points[j][0])+abs(points[i][1] - points[j][1]);
            edges[i].push_back(make_pair(j, cost));
            edges[j].push_back(make_pair(i, cost));
        }
    }
    Prim prim(edges);
    return prim.getMinistSum();
}


int main(int argc, char const *argv[])
{
    vector<vector<int>>points={{0,0},{2,2},{3,10},{5,2},{7,0}};
    cout<<minCostConnectPoints1(points);
    return 0;
}


