/*
给你一个变量对数组 equations 和一个实数值数组 values 作为已知条件，
    其中 equations[i] = [Ai, Bi] 和 values[i] 共同表示等式 Ai / Bi = values[i] 。
    每个 Ai 或 Bi 是一个表示单个变量的字符串。

另有一些以数组 queries 表示的问题，其中 queries[j] = [Cj, Dj] 表示第 j 个问题，
    请你根据已知条件找出 Cj / Dj = ? 的结果作为答案。

返回 所有问题的答案 。如果存在某个无法确定的答案，则用 -1.0 替代这个答案。
    如果问题中出现了给定的已知条件中没有出现的字符串，也需要用 -1.0 替代这个答案。

注意：输入总是有效的。你可以假设除法运算中不会出现除数为 0 的情况，且不存在任何矛盾的结果。

*/

#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<iostream>

using namespace std;

// Floyd
vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unordered_map<string, unordered_map<string, double>>graph;
    unordered_set<string>cnt;
    for(int i=0; i<equations.size(); i++){
        graph[equations[i][0]][equations[i][1]] = values[i];
        graph[equations[i][1]][equations[i][0]] = 1.0/values[i];
        cnt.insert(equations[i][0]);
        cnt.insert(equations[i][1]);
    }
    int Nv = graph.size();
    for(auto&k: cnt){
        for(auto&i: cnt){
            for(auto&j: cnt){
                if(graph[i][k]!=0&&graph[k][j]!=0){
                    graph[i][j] = graph[i][k]*graph[k][j];
                }
            }
        }
    }
    vector<double>res;
    for(auto&q : queries){
        if(graph[q[0]][q[1]]!=0){
            res.emplace_back(graph[q[0]][q[1]]);
        }else{
            res.emplace_back(-1.0);
        }
    }
    return res;
}

// 还可以用DFS,BFS,并查集



int main(int argc, char const *argv[])
{
    
    return 0;
}
