/*
在一个有向图中，节点分别标记为 0, 1, ..., n-1。图中每条边为红色或者蓝色，且存在自环或平行边。

red_edges 中的每一个 [i, j] 对表示从节点 i 到节点 j 的红色有向边。
    类似地，blue_edges 中的每一个 [i, j] 对表示从节点 i 到节点 j 的蓝色有向边。

返回长度为 n 的数组 answer，其中 answer[X] 是从节点 0 到节点 X 
    的红色边和蓝色边交替出现的最短路径的长度。如果不存在这样的路径，那么 answer[x] = -1。
*/
#include <vector>
#include <iostream>
#include <queue>
using namespace std;


vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
    vector<vector<int>>redGraph(n), blueGraph(n);
    for(auto & red: redEdges){
        redGraph[red[0]].emplace_back(red[1]);
    }
    for(auto & blue: blueEdges){
        blueGraph[blue[0]].emplace_back(blue[1]);
    }
    int step = 0;
    vector<int>ans(n, INT32_MAX);
    vector<bool> redSeen(n), blueSeen(n);
    queue<pair<int, bool>>que;
    que.emplace(0, true); // red
    que.emplace(0, false); // blue
    redSeen[0] = 1, blueSeen[0] = 1;
    while(!que.empty()){
        int size = que.size();
        while(size--){
            auto& cur = que.front();
            int curNode = cur.first, curColor = cur.second;
            que.pop();
            ans[curNode] = min(ans[curNode], step);
            if(curColor){ // 下一个颜色要是 blue
                for(auto &next: blueGraph[curNode]){
                    if(blueSeen[next]) continue;
                    que.emplace(next, false);
                    blueSeen[next] = 1;
                }

            }else{ // 下一个颜色要是 red
                for(auto &next: redGraph[curNode]){
                    if(redSeen[next]) continue;
                    que.emplace(next, true);
                    redSeen[next] = 1;
                }
            }
        }
        step++;
    }
    for(int i=0; i<n; i++){
        if(ans[i]==INT32_MAX) ans[i] = -1;
    }
    return ans;
}
