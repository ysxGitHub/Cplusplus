#include<iostream>
using namespace std;
#include<queue>
#include<stack>

template<typename T>
class MinHeap
{

public:
    MinHeap()
    {
        elements = NULL;
        m_size=0;
        capacity=0;
    }
    MinHeap(int maxsize): capacity(maxsize)
    {
        m_size = 0;
        elements = new T[maxsize+1];
        // 哨兵
        // elements[0]=-10000;
    }
 
    ~MinHeap()
    {
        delete[] elements;
        m_size=0;
        capacity=0;
    }

    // MinHeap<T>& operator=(MinHeap<T>& p){
    //     if(elements!=NULL){
    //         delete[] elements;
    //         elements=NULL;
    //     }
    //     capacity = p.capacity;
    //     elements = new T[p.capacity+1];

    //     for(int i=0; i<capacity; i++){
    //         elements[i] = p.elements[i];
    //     }
        
    //     return *this;
    // }

    bool Insert(T val)
    {
        if(capacity!=0)
        {
            int i;
            if(m_size==capacity)
            {
                return false;
            }
            // 指向堆的最后面
            i = ++m_size;
            // 当父节点的值大于要插入的值时
            for(; elements[i/2]>val; i/=2)
            {
                // cout<<"i="<<i<<endl;
                // if(i==0)
                // {break;}

                // 将父节点的值下移
                elements[i] = elements[i/2];
            }
            // 将要插入的值放入移动后的空位
            elements[i] = val;
            return true;
        }
        else{return false;}
    }    
    // 从最小堆中删除最小节点
    T Delete()
    {
        int parent, child;

        // 取出根节点
        T minitem = elements[1];
        // 得到最小堆最后一个元素, 并将size-1;
        T temp = elements[m_size--];
        // 判断父节点是否有左儿子, 如果有进行循环（从根节点进行）
        for(parent=1; parent*2<=m_size; parent=child)
        {
            // child指向左儿子
            child = parent*2;
            if((child!=m_size)&& // 判断是否有右儿子
            (elements[child]>elements[child+1])) // 判断右儿子的值是否小于左儿子
            {
                child++;
            }
            if(temp<=elements[child]) // 如果最后的值小于等于
            {break;}
            else
            {
                elements[parent] = elements[child];
            }
        }
        elements[parent] = temp;
        return minitem;
    }

    void set_sentry(T data)
    {
        elements[0] = data;
        // m_size++;
    }
    void set_Size(int size)
    {
        if(size<capacity)
        {
            m_size = size;
        }
    }

    int get_Capacity() const
    {
        return capacity;
    }

    int get_Size() const
    {
        return m_size;
    }

    T get_Data(int i) const
    {

        return elements[i];
    }
    
private:
    T* elements;
    int m_size;
    int capacity;
};

template<class T>
class Node
{
public:
    T data;
    Node<T>*left, *right, *parent;
    Node()
    {
        left = NULL;
        right = NULL;
        parent = NULL;
    }
    Node(T x, Node<T> *l=NULL, Node<T> *r=NULL, Node<T> *p=NULL)
    {
        data = x;
        left = l;
        right = r;
        parent = p;
    }
    bool operator<=(Node<T> &r)
    {
        if(data<=r.data){return true;}
        else{return false;}
    }
    bool operator<(Node<T> &r)
    {
        if(data<r.data){return true;}
        else{return false;}
    }
    bool operator>=(Node<T> &r)
    {
        if(data>=r.data){return true;}
        else{return false;}
    }
    bool operator>(Node<T> &r)
    {
        if(data>r.data){return true;}
        else{return false;}
    }    
};

template<typename T>
class HuffmanTree
{
public:
    HuffmanTree(T* num, int len)
    {   
        Node<T> *temp=NULL;
        Node<T> *first, *second;
        Node<T> *parent=NULL;
        MinHeap<Node<T>>hp(len*2);
        temp = new Node<T>(-10000);
        hp.set_sentry(*temp);
        for(int i=0; i<len; i++)
        {
            temp = new Node<T>(num[i]);
            hp.Insert(*temp);
        }
        for(int i=0; i<len-1; i++)
        {
            first = new Node<T>;
            second = new Node<T>;
            *first = hp.Delete();
            *second = hp.Delete();
            parent = new Node<T>;
            parent->left = first;
            parent->right = second;
            parent->data = first->data+second->data;
            first->parent = parent;
            second->parent = parent;
            hp.Insert(*parent);
        }
        root = parent;
        // thp = hp;
    }
    ~HuffmanTree()
    {
        destory(root);
    }
    Node<T>* getRoot()
    {
        return root;
    }
    void preOrderTravesal(Node<T>* node)
    {
        stack<Node<T>*> V;
        Node<T>* N = node;
        while (N||!V.empty())
        {
            while (N)
            {
                cout<<N->data<<" ";
                V.push(N);
                encode.push(1);
                N = N->left;
            }
            if(!V.empty())
            {
                N = V.top();
                encode.push(0);
                N = N->right;
                V.pop();
            }
        }
        cout<<endl;
        // while (!encode.empty())
        // {
        //     cout<<encode.front()<<" ";
        //     encode.pop();
        // }
        return ;
    }
    
    int WPL(Node<T>* node, int Depth){
        if(!node->left&&!node->right){
            return (Depth*node->data);
        }else{
            return (WPL(node->left, Depth+1) + WPL(node->right, Depth+1));
        }

    }

private:
    queue<int> encode;
    Node<T>* root;  
    // MinHeap<Node<T>>thp; 
    void destory(Node<T>* treeroot)
    {
        if(treeroot!=NULL)
        {
            destory(treeroot->left);
            destory(treeroot->right);
            delete treeroot;
        }
    }
};


int main(int argc, char const *argv[])
{
    int num[] = {10,15,12,3,4,13,1};
    HuffmanTree<int> hf(num, 7);
    hf.preOrderTravesal(hf.getRoot());
    // huffman编码的最佳编码长度
    cout<<hf.WPL(hf.getRoot(),0)<<endl;
    return 0;
}


