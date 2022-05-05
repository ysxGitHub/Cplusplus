/*
给你一个由 n 个节点（下标从 0 开始）组成的无向加权图，该图由一个描述边的列表组成，
    其中 edges[i] = [a, b] 表示连接节点 a 和 b 的一条无向边，
    且该边遍历成功的概率为 succProb[i] 。

指定两个节点分别作为起点 start 和终点 end ，请你找出从起点到终点成功概率最大的路径，
    并返回其成功概率。

如果不存在从 start 到 end 的路径，请 返回 0 。只要答案与标准答案的误差不超过 1e-5 ，
    就会被视作正确答案。
*/

#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;


class Dijsktra{
private:
    vector<double>maxPro;
    vector<vector<pair<int, double>>>graph;
public:
    Dijsktra(vector<vector<pair<int, double>>>&graph){
        this->graph = graph;
    }
    // vector<double>getPro()const{
    //     return maxPro;
    // }
    double dijsk(int n, int start, int end){
        maxPro.resize(n, 0.0);
        priority_queue<pair<double, int>, vector<pair<double, int>>, less<>>pq;
        maxPro[start]=1.0;
        pq.emplace(1.0, start);
        while(!pq.empty()){
            auto cur = pq.top();
            double curPro = cur.first;
            int curV = cur.second;
            pq.pop();
            if(curV==end){
                return curPro;
            }   
            if(maxPro[curV]>curPro){
                continue;
            }
            for(auto&vs: graph[curV]){
                double Pronum = vs.second * curPro;
                int nextV = vs.first;
                if(maxPro[nextV]<Pronum){
                    maxPro[nextV] = Pronum;
                    pq.emplace(Pronum, nextV);
                }
            }
        }
        return 0;
    }
};


double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
    if(edges.size()==0){
        return 0.0;
    }
    vector<vector<pair<int, double>>>graph(n);
    for(int i=0; i<edges.size(); i++){
        graph[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
        graph[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
    }
    Dijsktra  dij(graph);
    return dij.dijsk(n, start, end);
}


int main(int argc, char const *argv[])
{
    vector<vector<int>> edges = {{0,1},{1,2},{0,2}};
    vector<double> succProb = {0.5,0.5,0.2};
    cout<<maxProbability(3, edges, succProb, 0, 2);
    return 0;
}
