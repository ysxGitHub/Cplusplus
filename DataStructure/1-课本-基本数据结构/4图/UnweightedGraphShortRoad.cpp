/*
    无权图单源最短路
*/
#include<iostream>
#include<queue>
using namespace std;


// 邻接矩阵表示法
class Enode{
public:
    int v1,v2;
    int Weight;
    Enode(){};
    Enode(int i, int j, int w):v1(i-1), v2(j-1), Weight(w){};

};


// 邻接表表示法
class adjVnode{
public: 
    int AdjV;
    int Weight;
    adjVnode* Next;    
    adjVnode(){};
    adjVnode(int v, int w):AdjV(v), Weight(w){};
};

template<typename T>
class Vnode{
public: 
    T Data;
    adjVnode* FirstEdge;
    Vnode(){};
    Vnode(T d):Data(d){
        // FirstEdge = NULL;
        }
    // ~Vnode(){
    //     delete FirstEdge;
    // }
};

template<typename T>
class VGNode{
public:
    VGNode(){};
    VGNode(int v, int e):Nv(v),Ne(e){
        G = new Vnode<T>[Nv];
        Path = new int[Nv];
        Dist = new int[Nv];
        for(int v=0; v<Nv; v++){
            G[v].FirstEdge=NULL;
            G[v].Data = v;
            Path[v] = -1;
            Dist[v] = -1;
        }
    }
    ~VGNode(){
        if(G){
            for(int i=0; i<Nv; i++){
                if(G[i].FirstEdge){
                    adjVnode* p = G[i].FirstEdge->Next;
                    delete G[i].FirstEdge;
                    G[i].FirstEdge = NULL;
                    while (p){
                        adjVnode* temp = p->Next;
                        delete p;
                        p = temp;
                    }
                    delete p;
                }
            }
            delete[] G;
            delete[] Path;
            delete[] Dist;
        }
    }
    void InsertEdge(const Enode& en){
        // 为v1建立新的邻接点
        adjVnode* NewNode = new adjVnode(en.v2, en.Weight);
        // 将v2插入v1的表头
        NewNode->Next = G[en.v1].FirstEdge;
        G[en.v1].FirstEdge = NewNode;

        // // 为v2建立新的邻接点
        // adjVnode* NewNode1 = new adjVnode(en.v1, en.Weight);
        // // 将v1插入v2的表头
        // NewNode1->Next = G[en.v2].FirstEdge;
        // G[en.v2].FirstEdge = NewNode1;
    }


    void UnweightedShorRoad(int sourcenum){

        SNum = sourcenum-1;
        Dist[SNum] = 0;

        queue<Vnode<T>>Que;
        // cout<<G[SNum].Data<<endl;
        Que.push(G[SNum]);
        while (!Que.empty()){

            Vnode<T> V = Que.front();
            Que.pop();

            adjVnode* W=V.FirstEdge;
            while (W){ 
                
                if(Dist[W->AdjV]==-1){
                    Dist[W->AdjV] = Dist[V.Data]+1;
                    Path[W->AdjV] = V.Data+1;
                    Que.push(G[W->AdjV]);
                }

                W = W->Next;
            }
        }
        cout<<"\nDist: ";
        for(int i=0; i<Nv; i++){
            cout<<Dist[i]<<" ";
        }
        cout<<"\nPath: ";
        for(int i=0; i<Nv; i++){
            cout<<Path[i]<<" ";
        }    
    }


    void PrintGraph()const{
        for(int v=0; v<Nv; v++){
            if(G[v].FirstEdge){
                cout<<"(v="<<v+1<<"): "<<G[v].FirstEdge->AdjV+1<<"  ";
                adjVnode* p = G[v].FirstEdge->Next;
                while (p)
                {
                    cout<<p->AdjV+1<<"  ";
                    p = p->Next;
                }
            }
            cout<<endl;
        }

    }

private:
    int Nv; //顶点数
    int Ne; //边数
    Vnode<T>* G;
    int *Dist;
    int *Path;
    int SNum;
};

int main(int argc, char const *argv[])
{

    VGNode<int>vg(7, 12);
    vg.InsertEdge(Enode(3,1,3));
    vg.InsertEdge(Enode(1,2,1));
    vg.InsertEdge(Enode(1,4,1));

    vg.InsertEdge(Enode(4,6,4));
    vg.InsertEdge(Enode(4,7,4));
    vg.InsertEdge(Enode(7,6,7));

    vg.InsertEdge(Enode(3,6,3));

    
    vg.InsertEdge(Enode(2,5,2));
    vg.InsertEdge(Enode(2,4,2));
    vg.InsertEdge(Enode(5,7,5));

    vg.InsertEdge(Enode(4,3,4));
    vg.InsertEdge(Enode(4,5,4));


    vg.PrintGraph();

    vg.UnweightedShorRoad(3);

    return 0;
}



