/*
有 n 个网络节点，标记为 1 到 n。

给你一个列表 times，表示信号经过 有向 边的传递时间。 
    times[i] = (ui, vi, wi)，其中 ui 是源节点，vi 是目标节点，
    wi 是一个信号从源节点传递到目标节点的时间。

现在，从某个节点 K 发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，
    返回 -1 。

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
    vector<int>allParent;
public:
    Dijkstra(vector<vector<pair<int, int>>>&graph){
        this->graph = graph;
    }
    vector<int>getParent()const{
        return allParent;
    }
    vector<int>getDist()const{
        return toDist;
    }
    void dijkstra(int n, int start){
        toDist.resize(n, INT32_MAX/2);
        allParent.resize(n, -1);
        // pair<距离, 点>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;
        toDist[start] = 0;
        allParent[start] = -1;
        pq.emplace(0, start);
        while(!pq.empty()){
            auto &cur = pq.top();
            int curV = cur.second;
            int curDist = cur.first;
            pq.pop();
            if(toDist[curV]<curDist){
                continue;
            }
            for(auto&gs : graph[curV]){
                int nextV = gs.first;
                int dist = gs.second + toDist[curV];
                if(dist<toDist[nextV]){
                    toDist[nextV] = dist;
                    allParent[nextV] = curV;
                    pq.emplace(dist, nextV);
                }
            }
        }
    }
};

int networkDelayTime(vector<vector<int>>& times, int n, int k) {

    vector<vector<pair<int, int>>> graph(n);
    for(auto&gs: times){
        graph[gs[0]-1].emplace_back(gs[1]-1, gs[2]);
    }

    Dijkstra dk(graph);
    dk.dijkstra(n, k-1);

    int res = -1;
    for(auto&d : dk.getDist()){
        if(d==INT32_MAX/2){
            return -1;
        }else{
            res = max(res, d);
        }
    }
    return res;
}


int main(int argc, char const *argv[])
{
    vector<vector<int>>time = {{1,2,1},{2,3,2},{1,3,4}};
    cout<<networkDelayTime(time, 3, 1);
    return 0;
}
