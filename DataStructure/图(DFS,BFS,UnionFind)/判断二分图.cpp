/*
存在一个 无向图 ，图中有 n 个节点。其中每个节点都有一个介于 0 到 n - 1 之间的唯一编号。
    给你一个二维数组 graph ，其中 graph[u] 是一个节点数组，由节点 u 的邻接节点组成。
    形式上，对于 graph[u] 中的每个 v ，都存在一条位于节点 u 和节点 v 之间的无向边。
    该无向图同时具有以下属性：
        不存在自环（graph[u] 不包含 u）。
        不存在平行边（graph[u] 不包含重复值）。
        如果 v 在 graph[u] 内，那么 u 也应该在 graph[v] 内（该图是无向图）
        这个图可能不是连通图，也就是说两个节点 u 和 v 之间可能不存在一条连通彼此的路径。

二分图 定义：如果能将一个图的节点集合分割成两个独立的子集 A 和 B ，
    并使图中的每一条边的两个节点一个来自 A 集合，一个来自 B 集合，
    就将这个图称为 二分图 。

如果图是二分图，返回 true ；否则，返回 false 
*/

#include<vector>
#include<queue>
#include<iostream>
using namespace std;

/*解题技巧
说白了就是遍历一遍图，一边遍历一边染色，
    看看能不能用两种颜色给所有节点染色，且相邻节点的颜色都不相同。
*/


vector<int>visited;
/*
visited中 2：表示为被染色， 1：表示s节点的染色， 0：表示s邻接点的染色
*/ 
bool DFS(vector<vector<int>>& graph, int s, bool color){ 
    // s已经染色   
    if(visited[s]!=2){
        // 判断s染的色与要染的颜色是否相同
        return visited[s]==color;
    }
    // s未染色
    visited[s]=color;

    for(auto& v: graph[s]){
        bool tmp = DFS(graph, v, !color);
        // 存在s已经染色与s要染色不同的
        if(tmp==false){
            return false;
        }
    }

    return true;
}


bool isBipartite1(vector<vector<int>>& graph) {
    int n = graph.size();
    visited.resize(n, 2);

    for(int i=0; i<n; i++){
        if(visited[i]==2){
            if(DFS(graph, i, 1)==false){
                return false;
            }
        }
    }
    return true;
}

// BFS
bool isBipartite2(vector<vector<int>>& graph) {
    int n = graph.size();
    visited.resize(n, 2);
    queue<int>que;

    for(int i=0; i<n; i++){
       if(visited[i]==2){
           que.push(i);
           visited[i]=0;
           while (!que.empty()){
               int v = que.front();
               que.pop();
               for(auto&n : graph[v]){
                   if(visited[v]==visited[n]){
                       return false;
                   }
                   if(visited[n]==2){
                       visited[n] = !visited[v];
                       que.push(n);
                   }
               }
           }
           
       }
    }
    return true;
}

// 并查集
int findRoot(vector<int>&parent, int x){
    if(parent[x]!=x){
        parent[x] = findRoot(parent, parent[x]);
    }
    return parent[x];
}

bool findUnion(vector<int>&parent, int x, int y){
    int x_root = findRoot(parent, x);
    int y_root = findRoot(parent, y);
    if(x_root==y_root){
        return false;
    }
    return true;
}

void unionVal(vector<int>&parent, vector<int>&rank, int x, int y){
    int x_root = findRoot(parent, x);
    int y_root = findRoot(parent, y);
    if(rank[x_root]>rank[y_root]){
        parent[y_root] = x_root;
    }
    else if(rank[y_root]>rank[x_root]){
        parent[x_root] = y_root;
    }
    else{
        parent[y_root] = x_root;
        rank[x_root]++;
    }
}

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int>parent;
    vector<int>rank(n, 0);
    for(int i = 0; i<  n; i++){
        parent.push_back(i);
    }
    // 遍历每个顶点，将当前顶点的所有邻接点进行合并
    for (int j = 0; j < n; j++)
    {
        for(auto&n : graph[j]){
            // 若某个邻接点与当前顶点已经在一个集合中了，说明不是二分图，返回 false。
            if(findUnion(parent, j, n)==false){
                return false;
            }
            // 将当前顶点的邻接点都放在一个集合中
            unionVal(parent, rank, graph[j][0], n);
        }
    }
    return true;
    
}

int main(int argc, char const *argv[])
{
    vector<vector<int>>nums={{1,2,3},{0,2},{1,2,3},{0,2}};
    cout<<isBipartite(nums);
    return 0;
}
