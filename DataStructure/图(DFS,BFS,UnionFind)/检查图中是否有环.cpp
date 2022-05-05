#include<iostream>
#include<vector>
using namespace std;

void init_arr(int n, vector<int>& parent, vector<int>& rank){
    parent.resize(n);
    rank.resize(n);
    for(int i=0; i<n; i++){
        parent[i] = -1;
        rank[i] = 0;
    }
}

int find_root(int x, vector<int>& parent){
    while(parent[x]!=-1){
        x = parent[x];
    }
    return x;
}

bool union_ver(int x, int y, vector<int>& parent, vector<int>& rank){
    int x_root = find_root(x, parent);
    int y_root = find_root(y, parent);
    if(x_root==y_root){
        cout<<x<<" and "<<y<<" in a cycle"<<endl;
        return false;
    }
    else{
        if(rank[x_root]>rank[y_root]){
            parent[y_root] = x_root;
        }
        else if(rank[x_root]<rank[y_root]){
            parent[x_root] = y_root;
        }
        else{
            parent[y_root] = x_root;
            rank[x_root]++;
        }
        cout<<x<<" and "<<y<<" union"<<endl;
        return true;
    }
}

bool check_cycle(int n, vector<vector<int>>nums){
    vector<int>parent;
    vector<int>rank;
    init_arr(n, parent, rank);
    for(auto& edge: nums){
        if(union_ver(edge[0], edge[1], parent, rank)==0){
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int vertex = 5;
    vector<vector<int>>nums={{0, 1}, {1, 2}, {2, 3}, {3, 4}};
    cout<<check_cycle(vertex, nums)<<endl;
    return 0;
}

