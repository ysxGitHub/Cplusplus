#include<vector>
#include<iostream>
#include<queue>
using namespace std;

// 忘备录
class State {
public:
    // 图节点的 id
    int id;
    // 从 start 节点到当前节点的距离
    int distFromStart;
    // 经过的父节点
    int parent;

    State(int id, int distFromStart, int parent) {
        this->id = id;
        this->distFromStart = distFromStart;
        this->parent = parent;
    }

    bool operator < (const State &a)const{
        return this->distFromStart < a.distFromStart; 
    }

};

// 返回节点 from 到节点 to 之间的边的权重
int weight(int from, int to){

};

// 输入节点 s 返回 s 的相邻节点
vector<int> adj(int s){

};

// 输入一幅图和一个起点 start，计算 start 到其他节点的最短距离
vector<int>dijkstra(int start, vector<vector<int>> graph) {
    // 图中节点的个数
    int V = graph.size();
    // 记录最短路径的权重，你可以理解为 dp table
    // 定义：distTo[i] 的值就是节点 start 到达节点 i 的最短路径权重
    // 求最小值，所以 dp table 初始化为正无穷
    vector<int> distTo(V, INT32_MAX);
    // 记录所有经过节点的上一个节点
    vector<int> allParent(V, -1);
    // 优先级队列，distFromStart 较小的排在前面
    priority_queue<State, vector<State>> pq;
    // base case，start 到 start 的最短距离就是 0
    distTo[start] = 0;
    // 从起点 start 开始进行 BFS
    pq.push(State(start,  0, -1));
    // 开始的节点的父节点
    allParent[start] = -1;
    while (!pq.empty()) {
        State curState = pq.top();
        pq.pop();
        // 当前节点
        int curNodeID = curState.id;
        // 当前节点距start的最短距离
        int curDistFromStart = curState.distFromStart;
        
        // // 在这里加一个判断就行了，其他代码不用改
        // if (curNodeID == end) {
        //     return curDistFromStart;
        // }

        // 已经有一条更短的路径到达 curNode 节点了
        if (curDistFromStart > distTo[curNodeID]) {
            continue;
        }
        // 将 curNode 的相邻节点装入队列
        for (auto&nextNodeID : adj(curNodeID)) {
            // 看看从 curNode 达到 nextNode 的距离是否会更短
            int distToNextNode = distTo[curNodeID] + weight(curNodeID, nextNodeID);
            if (distTo[nextNodeID] > distToNextNode) {
                // 更新 dp table
                distTo[nextNodeID] = distToNextNode;
                // 将这个节点以及距离放入队列
                pq.push(State(nextNodeID, distToNextNode, curNodeID));
                // 记录该节点的父节点
                allParent[nextNodeID] = curNodeID;
            }
        }
    }
    // or allParent;
    return distTo;
}


int main(int argc, char const *argv[])
{
    
    return 0;
}
