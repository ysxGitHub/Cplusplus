#include<iostream>
using namespace std;

// 并查集 查找与合并
template<typename T>
class Node{
public:
    T Data;
    int Parent;

};

template<typename T>
class DisjointSet
{
public:
    DisjointSet():MaxSize(-1){
        MyArray = NULL;
    }
    DisjointSet(int m, T data[], int parent[]):MaxSize(m){
        MyArray = new Node<T>[m];
        for(int i=0; i<m; i++){
            MyArray[i].Data = data[i];
            MyArray[i].Parent = parent[i];
        }
    }

    ~DisjointSet(){
        if(MyArray!=NULL){
            delete[] MyArray;
        } 
    }

    int findroot(T x){
        int i;
        for(i=0; i<MaxSize&&MyArray[i].Data!=x; i++){};
        if(i>=MaxSize){
            return -1;
        }
        for(; MyArray[i].Parent>=0; i=MyArray[i].Parent);
        return i;
    }
    void Unioned(T x, T y){
        int root_x, root_y;
        root_x = findroot(x);
        root_y = findroot(y);
        if(root_x==root_y){
            cout<<"in a set!"<<endl;
        }
        else{
            if(root_x<root_y){
                MyArray[root_y].Parent = root_x;
            }
            else if(root_x>root_y){
                MyArray[root_x].Parent = root_y;
            }
            else{
                MyArray[root_y].Parent = root_x;
                MyArray[root_x].Parent--;
            }
            cout<<"joint a set!"<<endl;
        }
    }

private:
    int MaxSize;
    Node<T>* MyArray;
};

void DisjointSet_test()
{
    char data[] = "abcdefghij"; 
    int parent[] = {-3, 0, -2, 0, 2, -2, 0, 2, 5, 5};
    DisjointSet<char> DS(10, data, parent);
    DS.Unioned('b', 'd');
}

// 利用并查集找图中是否有无向环
void initialise(int parent[], int rank[]){
    for(int i=0; i<6; i++){
        parent[i]=-1;
        rank[i]=0;
    }
}

int find_root(int x, int parent[]){
    int x_root = x;
    while (parent[x_root]!=-1)
    {
        x_root = parent[x_root];
    }
    return x_root;
}

// 路径压缩
// int find_root(int x, int parent[]){
//     if(parent[x] < 0){
//         return x;
//     }
//     else{
//         return parent[x] = find_root(parent[x], parent);
//     }
// }

// 返回0合并失败，都在同一个集合中(按秩归并)
int union_ver(int x, int y, int parent[], int rank[]){
    int x_root = find_root(x, parent);
    int y_root = find_root(y, parent);
    if(x_root==y_root){return 0;}
    else{
        // parent[x_root] = y_root;
        if(rank[x_root]>rank[y_root]){
            parent[y_root] = x_root;
        }
        else if(rank[x_root]<rank[y_root]){
            parent[x_root] = y_root;
        }
        else{
            parent[x_root] = y_root;
            rank[y_root]++;
        }
        return 1;
    }
}

int main(int argc, char const *argv[])
{
    DisjointSet_test();

    // 利用并查集找图中是否有无向环
    int parent[6] = {0};
    int rank[6] = {0};
    int edges[6][2]={
        {0,1},{1,2},{1,3},
        {2,3},{3,4},{2,5},
    };
    initialise(parent, rank);
    for(int i=0;i<6;i++){
        if(union_ver(edges[i][0], edges[i][1], parent, rank)==0){
            cout<<"Cycle detected!"<<endl;
            exit(0);
        }
    }
    cout<<"No cycles found!"<<endl;
    return 0;
}



