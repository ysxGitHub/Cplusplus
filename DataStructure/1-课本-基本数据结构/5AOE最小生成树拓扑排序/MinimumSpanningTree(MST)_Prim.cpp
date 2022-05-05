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
#include<iostream>
using namespace std;

#define INF (1<<30)
// #define INF 100


// 邻接矩阵表示法
class Enode{
public:
    int v1,v2;
    int Weight;
    Enode(){};
    Enode(int i, int j, int w):v1(i-1), v2(j-1), Weight(w){};

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
        closest = new int [v];
        lowcost = new int [v];
        parent = new int [v];

        for(int i=0; i<Nv; i++){
            G[i] = new int[v];

            lowcost[i] = INF;
            closest[i] = 0;
            parent[i] = -1;

        }
        for(int v=0; v<Nv; v++){
            for(int w=0; w<Nv; w++){
                G[v][w] = INF;
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
            }
            delete[] G;
            delete[] closest;
            delete[] lowcost;
        }
    }
    int** CetGraph()const{
        return G;
    }
    void InsertEdge(const Enode& en){
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
    }

    void Prim()
    {
        closest[0] = -1;//加入第一个点，-1表示该点在集合U中，否则在集合V中
        int num = 0,ans = 0,e = 0;//e为最新加入集合的点
        while (num < Nv-1)//加入m-1条边
        {
            int micost = INF,miedge = -1;
            for(int i=0;i<Nv;i++){
                if(closest[i] != -1)
                {
                    int temp = G[e][i];
                    if(temp < lowcost[i])
                    {
                        lowcost[i] = temp;
                        closest[i] = e;
                    }
                    if(lowcost[i] < micost){
                        miedge = i;
                        micost = lowcost[i];
                        parent[i] = e;
                        // cout<<i<<"  "<<micost<<"  "<<e<<endl;
                    }
                    
                }
            }
            ans += micost;
            e = miedge;
            closest[miedge] = -1;
            num++;
        }
        cout<<"min_dist: "<<ans<<endl;
        for(int i=0; i<Nv; i++){
            cout<<parent[i]+1<<"\t";
        }
    }

private:
    int Nv; //顶点数
    int Ne; //边数
    T *Data;
    int *(*G);
    int *closest, *lowcost;
    int *parent;
};


int main(int argc, char const *argv[])
{
    EGNode<int>eg(7, 49);
    eg.InsertEdge(Enode(1,2,8));
    eg.InsertEdge(Enode(1,3,7));
    eg.InsertEdge(Enode(2,3,6));
    eg.InsertEdge(Enode(2,4,8));
    eg.InsertEdge(Enode(2,6,9));
    eg.InsertEdge(Enode(3,6,4));
    eg.InsertEdge(Enode(3,7,3));
    eg.InsertEdge(Enode(4,5,2));
    eg.InsertEdge(Enode(5,6,10));
    eg.InsertEdge(Enode(6,7,2));

    eg.PrintGraph();
    eg.Prim();
   
    return 0;
}
