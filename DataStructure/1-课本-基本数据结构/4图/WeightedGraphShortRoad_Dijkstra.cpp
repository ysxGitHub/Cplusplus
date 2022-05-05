/*
    有权图单源最短路
*/
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

#define MAX 0x7fffffff

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
    int AdjV=-1;
    int Weight=0;
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
            Dist[v] = MAX;
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

        if (G[en.v1].FirstEdge!=NULL){
            if(G[en.v1].FirstEdge->Weight>en.Weight){
                NewNode->Next = G[en.v1].FirstEdge;
                G[en.v1].FirstEdge = NewNode;
            }
            else{
                if(G[en.v1].FirstEdge->Next==NULL){
                    G[en.v1].FirstEdge->Next = NewNode;
                    NewNode->Next = NULL;
                }
                else{
                    adjVnode* p = G[en.v1].FirstEdge;
                    adjVnode* pn = G[en.v1].FirstEdge->Next;
                    while (pn){
                        if(pn->Weight>=en.Weight){
                            break;
                        }
                        p = p->Next;
                        pn = pn->Next;
                    }
                    p->Next = NewNode;
                    NewNode->Next = pn;
                }
   
            }
        }
        else{
            NewNode->Next = G[en.v1].FirstEdge;
            G[en.v1].FirstEdge = NewNode;
        }
        
        
        // // 将v2插入v1的表头
        // NewNode->Next = G[en.v1].FirstEdge;
        // G[en.v1].FirstEdge = NewNode;
    
        // // 为v2建立新的邻接点
        // adjVnode* NewNode1 = new adjVnode(en.v1, en.Weight);
        // // 将v1插入v2的表头
        // NewNode1->Next = G[en.v2].FirstEdge;
        // G[en.v2].FirstEdge = NewNode1;
    }

    void Dijkstra(int sourcenum){
        SNum = sourcenum-1;
        Dist[SNum] = 0;

        queue<Vnode<T>>Que;
        Que.push(G[SNum]);

        while (!Que.empty()){

            Vnode<T> V = Que.front();
            Que.pop();

            adjVnode* W=V.FirstEdge;
            while (W){ 
                int New_dist = Dist[V.Data] + W->Weight;

                // unfinished: 这里注意要将V的每个邻接点W按New_dist进行升序排列
                // 这里直接按链表处理的，并未排序，（可以使用最大堆进行取值·）
                if(New_dist<Dist[W->AdjV]){
                    Dist[W->AdjV] = New_dist;
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
                cout<<"<"<<G[v].FirstEdge->Weight<<">  ";
                adjVnode* p = G[v].FirstEdge->Next;
                while (p)
                {
                    cout<<p->AdjV+1<<"  ";
                    cout<<"<"<<p->Weight<<">  ";
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
    vg.InsertEdge(Enode(3,1,4));
    vg.InsertEdge(Enode(1,2,2));
    vg.InsertEdge(Enode(1,4,1));

    vg.InsertEdge(Enode(4,3,2));
    vg.InsertEdge(Enode(4,5,2));

    vg.InsertEdge(Enode(4,6,8));
    vg.InsertEdge(Enode(4,7,4));
    vg.InsertEdge(Enode(7,6,1));

    vg.InsertEdge(Enode(3,6,5));

    
    vg.InsertEdge(Enode(2,5,10));
    vg.InsertEdge(Enode(2,4,3));
    vg.InsertEdge(Enode(5,7,6));


    vg.PrintGraph();

    vg.Dijkstra(1);

    return 0;
}



