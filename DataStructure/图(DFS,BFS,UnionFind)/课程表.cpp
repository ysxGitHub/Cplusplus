/*
你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。

在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，
    其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。

例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。
*/

#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

/***利用并查集???***/
int find_root(int x, vector<int>&parent){
    while(parent[x]!=-1){
        x = parent[x];  
    }
    return x;
}

bool union_ver(int x, int y, vector<int>&rank, vector<int>&parent){
    int x_root = find_root(x, parent);
    int y_root = find_root(y, parent);
    if(x_root==y_root){
        return false;
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
    return true;
}

bool canFinish_un(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int>rank(numCourses, 0);
    vector<int>parent(numCourses, -1);
    for(auto&p : prerequisites){
        if(union_ver(p[0], p[1], rank, parent)==false){
            return false;
        }
    }
    return true;
}

/*******************DFS**********************/
static bool ans=true;
void DFS(vector<vector<int>>& graph, int s, vector<int>&visited){
    visited[s]=1;
    for(auto & v : graph[s]){
        if(visited[v]==0){
            DFS(graph, v, visited);
            if(ans==false){
                return;
            }
        }
        if(visited[v]==1){
            ans=false;
        }
    }
    visited[s]=2;
}

bool canFinish1(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>>graph(numCourses, vector<int>());
    vector<int>visited(numCourses, 0);
    // graph[0]={1,2,3}; 表示0->1,2,3;
    for(auto&ps : prerequisites){
        if(ps[0]==ps[1]){
            return false;
        }
        graph[ps[0]].push_back(ps[1]);
    }
    // ans=false时返回
    for(int i=0; i<numCourses&&ans; i++){
        if(graph[i].empty()){
            continue;
        }
        // 经过的点，不再进行遍历
        if(visited[i]==0){
            DFS(graph, i, visited);
        }
    }
    return ans;
}


bool BFS(vector<vector<int>>& graph, vector<int>&indegree)
{
    int visited=0;
    queue<int>q;
    for(int i=0; i<indegree.size(); i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int v = q.front();
        visited++;
        q.pop();
        for(auto&e: graph[v]){
            --indegree[e];
            if(indegree[e]==0){
                q.push(e);
            }
        }
    }
    return visited==indegree.size() ? true : false;
}

bool canFinish2(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>>graph(numCourses, vector<int>());
    vector<int>indegree(numCourses, 0);
    for(auto&ps : prerequisites){
        if(ps[0]==ps[1]){
            return false;
        }
        graph[ps[0]].push_back(ps[1]);
        ++indegree[ps[1]];
    } 
    return BFS(graph, indegree);
}

int main(int argc, char const *argv[])
{
    int numCourses = 5;
    vector<vector<int>> prerequisites = {{1,4}};
    cout<<canFinish2(numCourses, prerequisites);

    return 0;
}
