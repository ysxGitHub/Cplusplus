/*
给你输入一个大小为 n x n 的二维数组（邻接矩阵） graph 表示一幅有 n 个节点的图，
    每个人都是图中的一个节点，编号为 0 到 n - 1。

如果 graph[i][j] == 1 代表第 i 个人认识第 j 个人，
    如果 graph[i][j] == 0 代表第 i 个人不认识第 j 个人。

有了这幅图表示人与人之间的关系，请你计算，这 n 个人中，是否存在「名人」？

如果存在，算法返回这个名人的编号，如果不存在，算法返回 -1。

所谓「名人」有两个条件：
    1、所有其他人都认识「名人」。
    2、「名人」不认识任何其他人。

API:  bool knows(int a, int b); a是否认识b
*/
#include<vector>
#include<iostream>

using namespace std;

bool knows(int a, int b){
    vector<vector<int>>know;
    if(know[a][b]){
        return 1;
    }else{
        return 0;
    }
}

// 暴力解法
int findCelebrity1(int n) {
    for(int cand=0; cand<n; cand++){
        int other=0;
        for(other; other<n; other++){
            if(cand==other){continue;}
            // a是否认识b?
            if(knows(cand,other)||!knows(other,cand)){
                break;
            }
        }
        if(other==n){
            return cand;
        }
    }
    return -1;
}

// 创建数组进行逐对排除
int findCelebrity2(int n) {
    vector<int>people(n, 0);
    for(int i=0; i<n; i++){
        people[i]=i;
    }
    while(people.size()>=2){
        int cand = people.back();
        people.pop_back();
        int other = people.back();
        people.pop_back();
        // a是否认识b?
        if(knows(cand, other)||!knows(other,cand)){
            people.push_back(other);
        }else{
            people.push_back(cand);
        }
    }
    int cand = people.back();
    for(int other=0; other<n; other++){
        if(cand==other){continue;}
        if(knows(cand,other)||!knows(other,cand)){
            return -1;
        }
    }
    return cand;
}

// 优化，不要数组
int findCelebrity3(int n) {
    int cand = 0;
    for(int other=1; other<n; other++){
        if(knows(cand,other)||!knows(other,cand)){
            cand=other;
        }
    }
    for(int other=0; other<n; other++){
        if(cand==other){continue;}
        if(knows(cand,other)||!knows(other,cand)){
            return -1;
        }
    }
    return cand;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
