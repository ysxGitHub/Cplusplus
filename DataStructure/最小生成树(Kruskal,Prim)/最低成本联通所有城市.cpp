/*
想象一下你是个城市基建规划者，地图上有 n 座城市，它们按以 1 到 n 的次序编号。

给你整数 n 和一个数组 conections，其中 connections[i] = [xi, yi, costi] 
    表示将城市 xi 和城市 yi 连接所要的costi（连接是双向的）。

返回连接所有城市的最低成本，每对城市之间至少有一条路径。如果无法连接所有 n 个城市，返回 -1

该 最小成本 应该是所用全部连接成本的总和。

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
        return a.back()<b.back();
    }
};

// Kruskal算法与并查集一致
int minimumCost(int n, vector<vector<int>>& connections) {
    UnionFind uf(n+1);
    // 生成树的边个数
    int remaining = n-1;  
    int cost = 0;  
    sort(connections.begin(), connections.end(), cmp());

    for(auto&e : connections){
        if(uf.isConnect(e[0], e[1])){
            // 这里不能 return -1; 图中可以存在环，但是能生成树就行
            continue;
        }
        uf.unionVer(e[0], e[1]);
        cost += e[2];
        if(!--remaining){
            break;
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

int minimumCost1(int n, vector<vector<int>>& connections) {
    vector<vector<pair<int, int>>>graph(n, vector<pair<int, int>>());
    for(auto&c : connections){
        graph[c[0]-1].emplace_back(make_pair(c[1]-1,c[2]));
        graph[c[1]-1].emplace_back(make_pair(c[0]-1,c[2]));    
    }
    Prim prim(graph);
    if(prim.isAllInMST()==false){
        return -1;
    }
    return prim.getMinistSum();
}

int main(int argc, char const *argv[])
{
    int n = 3;
    vector<vector<int>>edges={{1,2,5}, {1,3,6}, {2,3,1}};
    cout<<minimumCost1(n, edges);
    return 0;
}
