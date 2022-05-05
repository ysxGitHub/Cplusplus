#include<iostream>
using namespace std;

#define INF 10000000


// 邻接矩阵表示法
class Enode{
public:
    int v1,v2;
    int Weight;
    Enode(){};
    Enode(int i, int j, int w):v1(i), v2(j), Weight(w){};

};

template<typename T>
class EGNode{
public:
    EGNode(){
        Data=NULL;
        G = NULL;
    }
    EGNode(int v, int e): Nv(v), Ne(e){
        Data = new T [v];
        G = new int* [v];
        D = new int* [v];
        Path = new int* [v];

        for(int i=0; i<Nv; i++){
            G[i] = new int[v];
            D[i] = new int[v];
            Path[i] = new int[v];
        }

        for(int v=0; v<Nv; v++){
            for(int w=0; w<Nv; w++){
                G[v][w] = 0;
            }
        }
    }
    ~EGNode(){
        if(Data){
            delete[] Data;
            Data = NULL;
        }
        if(G){
            for(int i=0; i<Nv; i++){
                delete[] G[i];
                delete[] D[i];
                delete[] Path[i];
            }
            delete[] G;
            delete[] D;
            delete[] Path;
        }
    }
    int** CetGraph()const{
        return G;
    }
    void InsertEdge(const Enode& en){
        // 1个为 有向图
        // 2个为 无向图
        G[en.v1][en.v2] = en.Weight;
        G[en.v2][en.v1] = en.Weight;
    }
    void PrintGraph(){
        for(int i=0; i<Nv; i++){
            for(int j=0; j<Nv; j++){
                if(G[i][j]!=INF){
                    cout<<G[i][j]<<"\t";
                }
                else{
                    cout<<"INF"<<"\t";
                }
            }
            cout<<endl;
        }
        // 每个顶点之间的最短路径
        cout<<"*************"<<endl;
        for(int i=0; i<Nv; i++){
            for(int j=0; j<Nv; j++){
                cout<<D[i][j]<<"\t";
            }
            cout<<endl;
        }
        // 每个顶点直接要经过的路径
        cout<<"*************"<<endl;
        for(int i=0; i<Nv; i++){
            for(int j=0; j<Nv; j++){
                cout<<Path[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
    void Floyd(){
        for(int i=0; i<Nv; i++){
            for(int j=0; j<Nv; j++){
                D[i][j] = G[i][j];
                Path[i][j] = -1;
            }
        }
        for (int k=0; k<Nv; k++){
            for(int i=0; i<Nv; i++){
                for(int j=0; j<Nv; j++){
                    int new_dist = D[i][k]+D[k][j];
                    if(new_dist<D[i][j]){
                        D[i][j] = new_dist;
                        Path[i][j] = k;
                    }
                }
            }
        }
    }
    void FindMin(){
        int Number;
        int MinDist = INF;
        for (int i=0; i<Nv; i++){
            int MaxDist = 0;
            for (int j=0; j<Nv; j++){
                if (MaxDist<D[i][j]&&D[i][j]!=0){
                    MaxDist = D[i][j];
                }
            }
            if (MinDist>MaxDist){
                MinDist = MaxDist;
                Number = i;
            }
        }
        cout<<"Num: "<<Number<<" MinDist: "<<MinDist<<endl;
    }


private:
    int Nv; //顶点数
    int Ne; //边数
    T *Data;
    int *(*G);
    int *(*D);
    int *(*Path);
};


int main(int argc, char const *argv[])
{
    // EGNode<int>eg(3, 9);
    // eg.InsertEdge(Enode(0,1,6));
    // eg.InsertEdge(Enode(0,2,13));
    // eg.InsertEdge(Enode(1,0,10));
    // eg.InsertEdge(Enode(2,0,5));
    // eg.InsertEdge(Enode(1,2,4));
    // eg.InsertEdge(Enode(2,1,INF));

    EGNode<int>eg(6, 36);
    eg.InsertEdge(Enode(0,1,1));
    eg.InsertEdge(Enode(0,2,70));
    eg.InsertEdge(Enode(0,3,INF));
    eg.InsertEdge(Enode(4,0,100));
    eg.InsertEdge(Enode(0,5,INF));

    eg.InsertEdge(Enode(1,2,INF));
    eg.InsertEdge(Enode(1,3,60));
    eg.InsertEdge(Enode(4,1,80));
    eg.InsertEdge(Enode(1,5,50));

    eg.InsertEdge(Enode(2,3,70));
    eg.InsertEdge(Enode(2,4,INF));
    eg.InsertEdge(Enode(2,5,80));

    eg.InsertEdge(Enode(4,3,50));
    eg.InsertEdge(Enode(3,5,60));

    eg.InsertEdge(Enode(4,5,60));

    eg.Floyd();
    eg.PrintGraph();

    // 找最小距离
    eg.FindMin();

    return 0;
}

