/*
AOE���ؼ�·��
    AOE�����Ա߱�ʾ��������޻�����
    ��AOE���У��������·�����ȵ�·����Ϊ�ؼ�·����
    �ؼ�·����ʾ��ɹ��̵���̹��ڡ�
*/

#include<iostream>
using namespace std;
 
const int DefaultVertices = 30;
 
template <class T, class E>
struct Edge { // �߽��Ķ���
    int dest; // �ߵ���һ����λ��
    E cost; // ���ϵ�Ȩֵ
    Edge<T, E> *link; // ��һ������ָ��
};
 
template <class T, class E>
struct Vertex { // ����Ķ���
    T data; // ���������
    Edge<T, E> *adj; // �������ͷָ��
};
 
template <class T, class E>
class Graphlnk {
public:
    const E maxValue = 100000; // ����������ֵ��=�ޣ�
    Graphlnk(int sz=DefaultVertices); // ���캯��
    ~Graphlnk(); // ��������
    void inputGraph(); // �����ڽӱ��ʾ��ͼ
    void outputGraph(); // ���ͼ�е����ж���ͱ���Ϣ
    T getValue(int i); // ȡλ��Ϊi�Ķ����е�ֵ
    E getWeight(int v1, int v2); // ���رߣ�v1�� v2���ϵ�Ȩֵ
    bool insertVertex(const T& vertex); // ���붥��
    bool insertEdge(int v1, int v2, E weight); // �����
    bool removeVertex(int v); // ɾ������
    bool removeEdge(int v1, int v2); // ɾ����
    int getFirstNeighbor(int v); // ȡ����v�ĵ�һ���ڽӶ���
    int getNextNeighbor(int v,int w); // ȡ����v���ڽӶ���w����һ�ڽӶ���
    int getVertexPos(const T vertex); // ��������vertex��ͼ�е�λ��
    int numberOfVertices(); // ��ǰ������
private:
    int maxVertices; // ͼ�����Ķ�����
    int numEdges; // ��ǰ����
    int numVertices; // ��ǰ������
    Vertex<T, E> * nodeTable; // �����(���������ͷ���)
};
 
// ���캯��:����һ���յ��ڽӱ�
template <class T, class E>
Graphlnk<T, E>::Graphlnk(int sz) {
    maxVertices = sz;
    numVertices = 0;
    numEdges = 0;
    nodeTable = new Vertex<T, E>[maxVertices]; // �������������
    if(nodeTable == NULL) {
        cerr << "�洢�ռ�������" << endl;
        exit(1);
    }
    for(int i = 0; i < maxVertices; i++)
        nodeTable[i].adj = NULL;
}
 
// ��������
template <class T, class E>
Graphlnk<T, E>::~Graphlnk() {
    // ɾ�����������еĽ��
    for(int i = 0; i < numVertices; i++) {
        Edge<T, E> *p = nodeTable[i].adj; // �ҵ����Ӧ������׽��
        while(p != NULL) { // ���ϵ�ɾ����һ�����
            nodeTable[i].adj = p->link;
            delete p;
            p = nodeTable[i].adj;
        }
    }
    delete []nodeTable; // ɾ�����������
}
 
// �����ڽӱ��ʾ��ͼ
template <class T, class E>
void Graphlnk<T, E>::inputGraph() {
    int n, m; // �洢�������ͱ���
    int i, j, k;
    T e1, e2; // ����
    E weight; // �ߵ�Ȩֵ
    
    cout << "�����붥�����ͱ�����" << endl;
    cin >> n >> m;
    cout << "����������㣺" << endl;
    for(i = 0; i < n; i++) {
        cin >> e1;
        insertVertex(e1); // ���붥��
    }
    
    cout << "������ͼ�ĸ��ߵ���Ϣ��" << endl;
    i = 0;
    while(i < m) {
        cin >> e1 >> e2 >> weight;
        j = getVertexPos(e1);
        k = getVertexPos(e2);
        if(j == -1 || k == -1)
            cout << "�����˵���Ϣ�������������룡" << endl;
        else {
            insertEdge(j, k, weight); // �����
            i++;
        }
    } // while
}
 
// �������ͼ�е����ж���ͱ���Ϣ
template <class T, class E>
void Graphlnk<T, E>::outputGraph() {
    int n, m, i;
    T e1, e2; // ����
    E weight; // Ȩֵ
    Edge<T, E> *p;
    
    n = numVertices;
    m = numEdges;
    cout << "ͼ�еĶ�����Ϊ" << n << ",����Ϊ" << m << endl;
    for(i = 0; i < n; i++) {
        p = nodeTable[i].adj;
        while(p != NULL) {
            e1 = getValue(i); // �����<i, p->dest>
            e2 = getValue(p->dest);
            weight = p->cost;
            cout << "<" << e1 << ", " << e2 << ", " << weight << ">" << endl;
            p = p->link; // ָ����һ���ڽӶ���
        }
    }
}
 
// ȡλ��Ϊi�Ķ����е�ֵ
template <class T, class E>
T Graphlnk<T, E>::getValue(int i) {
    if(i >= 0 && i < numVertices)
        return nodeTable[i].data;
    return NULL;
}
 
// ���رߣ�v1�� v2���ϵ�Ȩֵ
template <class T, class E>
E Graphlnk<T, E>::getWeight(int v1, int v2) {
    if(v1 != -1 && v2 != -1) {
        Edge<T , E> *p = nodeTable[v1].adj; // v1�ĵ�һ�������ı�
        while(p != NULL && p->dest != v2) { // Ѱ���ڽӶ���v2
            p = p->link;
        }
        if(p != NULL)
            return p->cost;
    }
    return maxValue; // ��(v1, v2)������,�ʹ��������ֵ
}
 
// ���붥��
template <class T, class E>
bool Graphlnk<T, E>::insertVertex(const T& vertex) {
    if(numVertices == maxVertices) // ������������ܲ���
        return false;
    nodeTable[numVertices].data = vertex; // �����ڱ�����
    numVertices++;
    return true;
}
 
// �����
template <class T, class E>
bool Graphlnk<T, E>::insertEdge(int v1, int v2, E weight) {
    if(v1 >= 0 && v1 < numVertices && v2 >= 0 && v2 < numVertices) {
        Edge<T, E> *p = nodeTable[v1].adj; // v1��Ӧ�ı�����ͷָ��
        while(p != NULL && p->dest != v2) // Ѱ���ڽӶ���v2
            p = p->link;
        if(p != NULL) // �Ѵ��ڸñߣ�������
            return false;
        p = new Edge<T, E>; // �����½��
        p->dest = v2;
        p->cost = weight;
        p->link = nodeTable[v1].adj; // ����v1������
        nodeTable[v1].adj = p;
        numEdges++;
        return true;
    }
    return false;
}
 
// ����ͼɾ��������鷳
template <class T, class E>
bool Graphlnk<T, E>::removeVertex(int v) {
    if(numVertices == 1 || v < 0 || v > numVertices)
        return false; // ��ջ򶥵�ų�����Χ
    
    Edge<T, E> *p, *s;
    // 1.�������v�ı�������w ��<v,w>
    while(nodeTable[v].adj != NULL) {
        p = nodeTable[v].adj;
        nodeTable[v].adj = p->link;
        delete p;
        numEdges--; // �붥��v������ı�����1
    } // while����
    // 2.���<w, v>����v�йصı�
    for(int i = 0; i < numVertices; i++) {
        if(i != v) { // ���ǵ�ǰ����v
            s = NULL;
            p = nodeTable[i].adj;
            while(p != NULL && p->dest != v) {// �ڶ���i����������v�Ķ���
                s = p;
                p = p->link; // ������
            }
            if(p != NULL) { // �ҵ���v�Ľ��
                if(s == NULL) { // ˵��p��nodeTable[i].adj
                    nodeTable[i].adj = p->link;
                } else {
                    s->link = p->link; // ����p����һ��������Ϣ
                }
                delete p; // ɾ�����p
                numEdges--; // �붥��v������ı�����1
            }
        }
    }
    numVertices--; // ͼ�Ķ��������1
    nodeTable[v].data = nodeTable[numVertices].data; // �,��ʱnumVertices����ԭ��numVerticesС1�����ԣ����ﲻ��ҪnumVertices-1
    nodeTable[v].adj = nodeTable[numVertices].adj;
    // 3.Ҫ����Ķ����Ӧ��λ�ø�д
    for(int i = 0; i < numVertices; i++) {
        p = nodeTable[i].adj;
        while(p != NULL && p->dest != numVertices) // �ڶ���i����������numVertices�Ķ���
            p = p->link; // ������
        if(p != NULL) // �ҵ���numVertices�Ľ��
            p->dest = v; // ���ڽӶ���numVertices�ĳ�v
    }
    return true;
}
 
// ɾ����
template <class T, class E>
bool Graphlnk<T, E>::removeEdge(int v1, int v2) {
    if(v1 != -1 && v2 != -1) {
        Edge<T, E> * p = nodeTable[v1].adj, *q = NULL;
        while(p != NULL && p->dest != v2) { // v1��Ӧ���������ұ�ɾ����
            q = p;
            p = p->link;
        }
        if(p != NULL) { // �ҵ���ɾ���߽��
            if(q == NULL) // ɾ���Ľ���Ǳ�������׽��
                nodeTable[v1].adj = p->link;
            else
                q->link = p->link; // ���ǣ���������
            delete p;
            return true;
        }
    }
    return false; // û���ҵ����
}
 
// ȡ����v�ĵ�һ���ڽӶ���
template <class T, class E>
int Graphlnk<T, E>::getFirstNeighbor(int v) {
    if(v != -1) {
        Edge<T, E> *p = nodeTable[v].adj; // ��Ӧ�����һ���߽��
        if(p != NULL) // ���ڣ����ص�һ���ڽӶ���
            return p->dest;
    }
    return -1; // ��һ���ڽӶ��㲻����
}
 
// ȡ����v���ڽӶ���w����һ�ڽӶ���
template <class T, class E>
int Graphlnk<T, E>::getNextNeighbor(int v,int w) {
    if(v != -1) {
        Edge<T, E> *p = nodeTable[v].adj; // ��Ӧ�����һ���߽��
        while(p != NULL && p->dest != w) // Ѱ���ڽӶ���w
            p = p->link;
        if(p != NULL && p->link != NULL)
            return p->link->dest;  // ������һ���ڽӶ���
    }
    return -1; // ��һ���ڽӶ��㲻����
}
 
// ��������vertex��ͼ�е�λ��
template <class T, class E>
int Graphlnk<T, E>::getVertexPos(const T vertex) {
    for(int i = 0; i < numVertices; i++)
        if(nodeTable[i].data == vertex)
            return i;
    return -1;
}
 
// ��ǰ������
template <class T, class E>
int Graphlnk<T, E>::numberOfVertices() {
    return numVertices;
}

// ����ؼ�·�����㷨
template <class T, class E>
void CirticalPath(Graphlnk<T, E>& G) {
    int i, j, k, n;
    E Ae, Al, w;
    
    n = G.numberOfVertices(); // ͼ�Ķ�����
    E *Ve = new E[n];
    E *Vl = new E[n];
    for(i = 0; i < n; i++) // ��ʼ�����翪ʼ�¼�ʱ��
        Ve[i] = 0;
    // �������Ve[i],ʱ��Vi��������ܿ�ʼʱ�䣺��Դ��V0������Vi���·������
    for(i = 0; i < n; i++) {
        j = G.getFirstNeighbor(i); // �ڽӶ���
        while(j != -1) { // �����ڽӶ���
            w = G.getWeight(i, j);
            if(Ve[i] + w > Ve[j]) // Ҫ��ǰ��ʱ����Ļ���ˣ��ſ��Խ���j�¼�
                Ve[j] = Ve[i] + w;
            j = G.getNextNeighbor(i, j); // ��һ���ڽӶ���
        }
    }
    // �������Vl[]
    Vl[n-1] = Ve[n-1]; // ��������¼�ʱ��
    for(j = n-2; j > 0; j--) {
        k = G.getFirstNeighbor(j);
        Vl[j] = Ve[n-1]; // �������ΪVe[n-1]
        while(k != -1) { // �����ڽӱ�
            w = G.getWeight(j, k);
            if(Vl[k] - w < Vl[j])
                Vl[j] = Vl[k] - w; // �¼��������ʼʱ��
            k = G.getNextNeighbor(j, k);
        }
    }

    for(i = 0; i < n; i++) { // ������Ae, A1
        j = G.getFirstNeighbor(i);
        while(j != -1) {
            Ae = Ve[i]; // �ak������ܿ�ʼʱ��
            Al = Vl[j] - G.getWeight(i, j); // ʱ��j��ٿ��ܿ�ʼʱ��-�ak��Ҫ��ʱ��
            if(Al == Ae)
                cout << "<" << G.getValue(i) << "," << G.getValue(j) << ">" << "�ǹؼ��" << endl;
            j = G.getNextNeighbor(i, j);
        }
    }
    delete []Ve; // �ͷŶ�̬����Ŀռ�
    delete []Vl;
}


int main(int argc, char const *argv[])
{
    
    Graphlnk<char, int> G; // ����ͼ����
    
    // ����ͼ
    G.inputGraph();
    cout << "ͼ����Ϣ���£�" << endl;
    G.outputGraph();
    // ���ü���ؼ�·���ĺ���
    cout << "�ؼ�·�����£�" << endl;
    CirticalPath(G);

    return 0;
}

/*
9 11
0 1 2 3 4 5 6 7 8
0 1 6
0 2 4
0 3 5
1 4 1
2 4 1
3 5 2
4 6 9
4 7 7
5 7 4
6 8 2
7 8 4
*/