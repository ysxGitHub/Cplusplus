#include<iostream>
#include<stack>
#include<queue>
using namespace std;

template<class T>
class Linklist
{

public:
    Linklist()
    {
        this->right = NULL;
        this->left = NULL;
    }
    Linklist(T data): m_data(data)
    {
        this->right = new Linklist<T>;
        this->left = new Linklist<T>;
        this->right = NULL;
        this->left = NULL;
    }
    ~Linklist()
    {
        delete this->right;
        delete this->left;
        this->right = NULL;
        this->left = NULL;
    }
    T m_data;
    Linklist<T> * left;
    Linklist<T> * right;
};


void preOrderTravesal(Linklist<int>* node)
{
    stack<Linklist<int>*> V;
    Linklist<int>* T = node;
    while (T||!V.empty())
    {
        while (T)
        {
            cout<<T->m_data<<" ";
            V.push(T);
            T = T->left;
        }
        if(!V.empty())
        {
            T = V.top();
            T = T->right;
            V.pop();
        }
    }
    return ;
}

void inOrderTravesal(Linklist<int>* node)
{
    stack<Linklist<int>*> V;
    Linklist<int>* T = node;
    while (T||!V.empty())
    {
        while (T)
        {
            V.push(T);
            T = T->left;
        }
        if(!V.empty())
        {
            T = V.top();
            cout<<T->m_data<<" ";
            V.pop();
            T = T->right;
        }
    }
    return ;
}



void postOrderTravesal(Linklist<int>* node)
{
    stack<Linklist<int>*> V;
    Linklist<int>* T = node;
    Linklist<int>* temp = NULL; //用于记录上一次访问得节点
    while (T||!V.empty())
    {
        while (T)
        {
            V.push(T);
            T = T->left;
        }
        if(!V.empty())
        {
            T = V.top();
            V.pop();
            if(T->right==NULL||temp==T->right) //访问节点得条件
            {
                cout<<T->m_data<<" ";
                temp = T ; //记录上一次访问得节点
                T = NULL; //跳过下一次循环的访问左子节点的过程，直接进入栈的弹出阶段，
                          // 它们的左子节点都肯定被经过且已放入栈中
            }
            else
            {
                V.push(T);  // 将已弹出的根节点放回栈中
                T = T->right; // 经过右子节点
            }
            
        }
    }
    return ;
}


void preOrderTravesalRec(Linklist<int>* node)
{
    if(node)
    {
        cout<<node->m_data<<" ";
        preOrderTravesalRec(node->left);
        preOrderTravesalRec(node->right);
    }
}

void inOrderTravesalRec(Linklist<int>* node)
{
    if(node)
    {
        inOrderTravesalRec(node->left);
        cout<<node->m_data<<" ";
        inOrderTravesalRec(node->right);
    }
}

void postOrderTravesalRec(Linklist<int>* node)
{
    if(node)
    {
        postOrderTravesalRec(node->left);
        postOrderTravesalRec(node->right);
        cout<<node->m_data<<" ";
    }
}

void levelOrderTraversal(Linklist<int>* node)
{
    queue<Linklist<int>*> V;
    Linklist<int>* T = node;
    V.push(T);
    while (!V.empty())
    {
        T = V.front();
        V.pop();
        cout<<T->m_data<<" ";
        if(T->left)
        {
            V.push(T->left);
        }
        if(T->right)
        {
            V.push(T->right);
        }

    }
    
}

void treeAllLeaf(Linklist<int>* node)
{
    if(node)
    {
        treeAllLeaf(node->left);
        if(node->left==NULL&&node->right==NULL)
        {
            cout<<node->m_data<<" ";
        }
        treeAllLeaf(node->right);
    }
}

int postOrderHeight(Linklist<int>* node)
{
    int hl, hr, maxh;
    if(node)
    {
        hl = postOrderHeight(node->left);
        hr = postOrderHeight(node->right);
        maxh = (hl>hr)? hl: hr;
        return (maxh+1); 
    }
    else
    {
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    Linklist<int>l0(0);
    Linklist<int>l1(1);
    Linklist<int>l2(2);
    Linklist<int>l3(3);
    Linklist<int>l4(4);
    Linklist<int>l5(5);
    Linklist<int>l6(6);
    Linklist<int>l7(7);
    Linklist<int>l8(8);
    Linklist<int>l9(9);

    l0.left = &l1;
    l0.right = &l2;
    l1.left = &l3;
    l1.right = &l4;
    l2.left = &l5;
    l2.right = &l6;
    l3.left = &l7;
    l3.right = &l8;
    l4.left = &l9;
    
    preOrderTravesal(&l0);
    cout<<endl;

    inOrderTravesal(&l0);
    cout<<endl;

    postOrderTravesal(&l0);
    cout<<endl;

    cout<<"Travesal Order Rec"<<endl;

    Linklist<int>* T = &l0;
    preOrderTravesalRec(T);
    cout<<endl;

    Linklist<int>* T2 = &l0;
    inOrderTravesalRec(T2);
    cout<<endl;

    Linklist<int>* T3 = &l0;
    postOrderTravesalRec(T3);
    cout<<endl;

    levelOrderTraversal(&l0);
    cout<<endl;

    treeAllLeaf(&l0);
    cout<<endl;

    cout<<"tree height: "<<postOrderHeight(&l0)<<endl;

    return 0;
}




