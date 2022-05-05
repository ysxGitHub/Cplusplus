/*
最小生成树
    是一棵树，无回路，v个顶点一定有v-1条边。
    包含全部顶点，v-1条边都在图里。
    边的权重和最小
如何得到最小生成树
    贪心算法
        只能用图里有的边
        只能正好用掉v-1条边
        不能有回路
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <limits>
#include <utility>

#define forsn(i, s, n) for(int i = s; i < n; ++i)
#define forn(i, n) forsn(i, 0, n)

using std::vector;
using std::pair;
using std::list;
using std::make_pair;

typedef vector<int> vint;
typedef pair<double, pair<int, int>> edge;
typedef list<edge> edges;

vint rank;
vint parent;

void create_set(int x) {
    // 树高度
    rank[x] = 0;
    // 父节点
    parent[x] = x;
}

int find_set(int x) {
    // 如果x的父节点不是x继续寻找
    if (x != parent[x]){
        parent[x] = find_set(parent[x]);
    }
    // 返回x的父节点
    return parent[x];
}

// 并查集
void merge_set(int x, int y) {
    // 如果树x高比树y的高
    if (rank[x] > rank[y]){
        // 将y的父节点设置为x，即将y拼在x下
        parent[y] = x;
    }
    else{ // 如果树y高比树x的高
        // 将x的父节点设置为y，即将x拼在y下
        parent[x] = y;
    }
    // 如何树x与树y同样高
    if (rank[x] == rank[y]) {
        // 将x拼在y下，y的树高++
        ++rank[y];
    }
}

double kruskal(int n, edges& es) {
    // vector<int>rank[n]
    rank.resize(n);
    // vector<int>parent[n]
    parent.resize(n);
    double cost = 0;
    // 生成树的边个数
    int remaining = n-1;
    // 创建集合，初始化父节点
    forn(i, n){
        create_set(i);
    } 
    // 排序
    es.sort();
    for (auto& edge : es) {
        int u = find_set(edge.second.first);
        int v = find_set(edge.second.second);
        if (u == v) {
            // 如果两个顶点有同一个父节点跳出此次循环
            continue;
        }
        // 否则，合并两个顶点
        merge_set(u, v);
        // 加上此次的权重
        cost += edge.first;
        if (!--remaining) {
            break;
        }
    }
    // 如果remaining>0则返回无穷大
    if (remaining) {
        return std::numeric_limits<double>::infinity();
    }
    return cost;
}

int main() {
    int n, m;
    // 读取文件
    std::ifstream input("Kruskal_Data.txt");
    // n为顶点, m为边的个数
    input >> n >> m;
    // list<pair<double, pair<int, int>>> es;
    edges es;
    forn(i, m) {
        double weight;
        int u, v;
        input >> u >> v >> weight;
        // 加入es链表中
        es.push_back(make_pair(weight, make_pair(u, v)));
    }
    std::cout << "Cost of minimum spanning tree: " << kruskal(n, es) << std::endl;
}


