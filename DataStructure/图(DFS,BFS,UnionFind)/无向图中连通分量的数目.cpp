/*
你有一个包含 n 个节点的图。给定一个整数 n 和一个数组 edges ，
    其中 edges[i] = [ai, bi] 表示图中 ai 和 bi 之间有一条边。

返回 图中已连接分量的数目 。

示例 1:

输入: n = 5 和 edges = [[0, 1], [1, 2], [3, 4]]

0         3
|         | 
1 --- 2   4 

输出: 2

注意:
你可以假设在 edges 中不会出现重复的边。而且由于所以的边都是无向边，[0, 1] 与 [1, 0]  相同，
    所以它们不会同时在 edges 中出现。
*/
#include<vector>
#include<iostream>
#include<queue>
#include<unordered_set>
using namespace std;

// 这里的ans相当于根节点的个数
int ans;

int findRoot(vector<int>& parent, int x){
    if(parent[x]!=x){
        parent[x] = findRoot(parent, parent[x]);
    }
    return parent[x];
}

void unionVer(vector<int>&parent, vector<int>&rank, int x, int y){
    int x_root = findRoot(parent, x);
    int y_root = findRoot(parent, y); 
    if(x_root==y_root){
        return ;
    }    
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
    ans--;
}


int countComponents1(int n, vector<vector<int>>& edges) {
    vector<int>parent(n, 0);
    vector<int>rank(n, 0);
    ans=n;
    for(int i=0; i<n; i++){
        parent[i] = i;
    }
    for(auto&e : edges){
        unionVer(parent, rank, e[0], e[1]);
    }
    
    return ans;
}


void DFS(vector<vector<int>>&graph, int s, vector<int>&visited){
    if(visited[s]!=0){
        return ;
    }
    visited[s] = 1;
    for(auto&e : graph[s]){
        DFS(graph, e, visited);
    }
    visited[s] = 2;
}

int countComponents2(int n, vector<vector<int>>& edges) {
    vector<int>visited(n, 0);
    vector<vector<int>>graph(n, vector<int>());
    for(auto&e : edges){
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    int ans=n;
    for(int i=0; i<n; i++){
        if(visited[i]!=0){
            ans--;
        }
        else{
            DFS(graph, i, visited);
        }
    }
    return ans;
}



int countComponents(int n, vector<vector<int>>& edges) {
    vector<int>visited(n, 0);
    vector<vector<int>>graph(n, vector<int>());
    queue<int>que;
    for(auto&e : edges){
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    int ans=n;
    for(int i=0; i<n; i++){
        if(visited[i]!=0){
            ans--;
        }
        else{
            que.push(i);
            while (!que.empty()){
                int v = que.front();
                que.pop();
                visited[v] = 1;
                for(auto&e : graph[v]){
                    if(visited[e]==0){
                        que.push(e);
                    }
                }
                visited[v] = 2;
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int n = 5; 
    vector<vector<int>>edges = {{0, 1}, {1, 2}, {3, 4}};
    cout<<countComponents(5, edges);
    return 0;
}
