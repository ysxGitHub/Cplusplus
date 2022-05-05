/*
图：表示“多对多”的关系
    包含：
        一组顶点：通常用V表示顶点集合
        一组边：通常用E表示边的集合
            顶点对（无向边）（v, w）
            有向边<v, w>表示从v指向w的边

图的表示：  
    邻接矩阵表示法
    邻接表表示法

图的遍历：
    深度优先搜索:DFS
    广度优先搜索:BFS
*/
#include<iostream>
using namespace std;


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
        for(int i=0; i<Nv; i++){
            G[i] = new int[v];
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
            }
            delete[] G;
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
                cout<<G[i][j]<<"\t";
            }
            cout<<endl;
        }
    }

private:
    int Nv; //顶点数
    int Ne; //边数
    T *Data;
    int *(*G);
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
        for(int v=0; v<Nv; v++){
            G[v].FirstEdge=NULL;
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
        }
    }
    void InsertEdge(const Enode& en){
        // 为v1建立新的邻接点
        adjVnode* NewNode = new adjVnode(en.v2, en.Weight);
        // 将v2插入v1的表头
        NewNode->Next = G[en.v1].FirstEdge;
        G[en.v1].FirstEdge = NewNode;

        // 为v1建立新的邻接点
        adjVnode* NewNode1 = new adjVnode(en.v1, en.Weight);
        // 将v1插入v2的表头
        NewNode1->Next = G[en.v2].FirstEdge;
        G[en.v2].FirstEdge = NewNode1;
    }
    void PrintGraph(){
        for(int v=0; v<Nv; v++){
            if(G[v].FirstEdge){
                cout<<"(v="<<v<<"): "<<G[v].FirstEdge->Weight<<"  ";
                adjVnode* p = G[v].FirstEdge->Next;
                while (p)
                {
                    cout<<p->Weight<<"  ";
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
};

int main(int argc, char const *argv[])
{
    EGNode<int>eg(5, 25);
    eg.InsertEdge(Enode(1,2,10));
    eg.InsertEdge(Enode(2,3,5));
    eg.PrintGraph();

    VGNode<int>vg(5, 25);
    vg.InsertEdge(Enode(1,2,5));
    vg.InsertEdge(Enode(1,3,6));
    vg.InsertEdge(Enode(1,4,7));
    vg.PrintGraph();

    return 0;
}



