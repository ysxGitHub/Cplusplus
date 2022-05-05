/*
你准备参加一场远足活动。给你一个二维 rows x columns 的地图 heights ，
    其中 heights[row][col] 表示格子 (row, col) 的高度。一开始你在最左上角的格子 (0, 0) ，
    且你希望去最右下角的格子 (rows-1, columns-1) （注意下标从 0 开始编号）。
    你每次可以往 上，下，左，右 四个方向之一移动，你想要找到耗费 体力 最小的一条路径。

一条路径耗费的 体力值 是路径上相邻格子之间 高度差绝对值 的 最大值 决定的。

请你返回从左上角走到右下角的最小 体力消耗值 。
*/

#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

class Dijkstra{
private:
    vector<vector<pair<int, int>>>graph;
    vector<int>toDist;
public:
    Dijkstra(vector<vector<pair<int, int>>>&graph){
        this->graph = graph;
    }
    int dijkstra(int n, int start, int end){
        toDist.resize(n, INT32_MAX/2);
        // pair<距离, 点>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;
        toDist[start] = 0;
        pq.emplace(0, start);
        while(!pq.empty()){
            auto &cur = pq.top();
            int curV = cur.second;
            int curDist = cur.first;
            pq.pop();
            if(curV==end){
                return curDist;
            }
            if(toDist[curV]<curDist){
                continue;
            }
            for(auto&gs : graph[curV]){
                int nextV = gs.second;
                // 这里记录连续格子的差值绝对值最大
                int dist = max(gs.first, curDist);
                if(dist<toDist[nextV]){
                    toDist[nextV] = dist;
                    pq.emplace(dist, nextV);
                }
            }
        }
        return -1;
    }
};


int minimumEffortPath(vector<vector<int>>& heights) {
    int m = heights.size();
    int n = heights[0].size();
    vector<vector<pair<int, int>>>graph(m*n);
    vector<vector<int>>offset = {{0,1},{0,-1},{1,0},{-1,0}};
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<4; k++){
                int x = i+offset[k][0];
                int y = j+offset[k][1];
                if(x<0||y<0||x>=m||y>=n){continue;}
                graph[i*n+j].emplace_back(abs(heights[i][j]-heights[x][y]), x*n+y);
            }
        }
    }
    Dijkstra d(graph);
    return d.dijkstra(m*n, 0, m*n-1);
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
