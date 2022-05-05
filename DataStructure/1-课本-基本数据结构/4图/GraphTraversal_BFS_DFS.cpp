#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<stack>
#include<cstring>


using namespace std;

template<class T, class S>
void BFS(T graph, S source){
    // 先进先出
    queue<S>road;
    unordered_set<S>seen;
    // 记录从哪个点过来的
    unordered_map<S, S>parent;
    road.push(source);
    seen.insert(source);
    parent[source] = '-';
    while (!road.empty()){
        // 得到最先入队列的点
        S vertex = road.front();
        road.pop();
        // 得到与之相连的点
        string nodes = graph[vertex];
        // 遍历与之相连的点
        for(auto n : nodes){
            // 对没有遍历到的点进行遍历
            if(seen.find(n)==seen.end()){
                road.push(n);
                // 记录遍历过的点
                seen.insert(n);
                // 设置该点的经过点
                parent[n] = vertex; 
            }
        }
        cout<<vertex<<"  ";
    }
    cout<<endl;
    for(auto a: parent){
        cout<<"parent: "<<a.second<<"   child: "<<a.first<<endl;
    }
}


template<class T, class S>
void DFS(T graph, S source){
    // 先进后出
    stack<S>road;
    unordered_set<S>seen;
    road.push(source);
    seen.insert(source);
    while (!road.empty()){
        // 得到最后入栈的点
        S vertex = road.top();
        road.pop();
        // 得到与之相连的点
        string nodes = graph[vertex];
        // 遍历与之相连的点
        for(auto n : nodes){
            // 对没有遍历到的点进行遍历
            if(seen.find(n)==seen.end()){
                road.push(n);
                seen.insert(n);
            }
        }
        cout<<vertex<<"  ";
    }
    cout<<endl;
}


int main(int argc, char const *argv[])
{
    unordered_map<char, string>graph;
    // 'A': vertex  " ": edge
    graph['A'] = "BC";
    graph['B'] = "ACD";
    graph['C'] = "ABDE";
    graph['D'] = "BCEF";
    graph['E'] = "CD";
    graph['F'] = "D";

    char source = 'A';

    BFS(graph, source);

    DFS(graph, source);

    return 0;
}

