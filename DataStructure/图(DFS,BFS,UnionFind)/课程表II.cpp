/*
现在你总共有 numCourses 门课需要选，记为 0 到 numCourses - 1。
    给你一个数组 prerequisites ，其中 prerequisites[i] = [ai, bi] ，
    表示在选修课程 ai 前 必须 先选修 bi 。

例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示：[0,1] 。
返回你为了学完所有课程所安排的学习顺序。可能会有多个正确的顺序，你只要返回 任意一种 就可以了。
    如果不可能完成所有课程，返回 一个空数组 。
*/

#include<queue>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;


vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>>graph(numCourses, vector<int>());
    vector<int>indegreed(numCourses, 0);
    for(auto&p : prerequisites){
        // p[0]课程依赖p[1]课程 
        graph[p[1]].push_back(p[0]);
        // 度++
        ++indegreed[p[0]];
    }
    queue<int>que;
    for(int i=0; i<numCourses; i++){
        // 度==0 先入队列，没有依赖课程
        if(indegreed[i]==0){
            que.push(i);
        }
    }
    vector<int> visited;
    while(!que.empty()){
        // 出队列
        int v = que.front();
        que.pop();
        // 记录 最先可以学习的课程（度为零）
        visited.push_back(v);
        for(auto&e: graph[v]){
            // 依赖于v的课程度可以减一
            --indegreed[e];
            // 度为零的入队列
            if(indegreed[e]==0){
                que.push(e);
            }
        }
    }

    if(visited.size()!=numCourses){
        return {};
    }
    return visited;
}

class Solution {
private:
    // 0：表示未访问；1：表示正在访问；2：表示访问过
    vector<int>visited;
    // 保留访问的结果
    vector<int>res;
    // 是否存在环；
    bool isnocycle = true;
public:
    void dfs(vector<vector<int>>&graph, int s){
        // 开始时标记为正在访问
        visited[s] = 1;
        for(auto e: graph[s]){
            // -> 等于0时表示没有被访问过
            if(visited[e]==0){
                dfs(graph,e);
                // 发现环，直接返回
                if(isnocycle==false){
                    return ;
                }
            }
            // -> 等于1时表示正在被访问过，现在再次遇到，所以存在环
            else if(visited[e]==1){
                isnocycle=false;
                return;
            }
        }
        // -> 等于2时表示被访问过的，可加入访问过的结果中
        visited[s] = 2;
        res.push_back(s);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses, vector<int>());
        visited.resize(numCourses,0);
        for(auto&p : prerequisites){
            graph[p[1]].push_back(p[0]);
        }
        for(int i=0; i<numCourses&&isnocycle; i++){
            if(visited[i]==0){
                dfs(graph, i);
            }
        }
        if(isnocycle==false){
                return {};
        }
        // 注意下标 0 为栈底，因此需要将数组反序输出
        reverse(res.begin(), res.end());
        return res;
    }
};


int main(int argc, char const *argv[])
{
    
    return 0;
}
