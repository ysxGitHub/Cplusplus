// 判断是否为同一颗二叉搜索树
// 1.分别建两颗搜索树的判断方法
// 2.不建树
// 3.只建一棵树，再判断其他序列是否与该树一致

#include <iostream>

using namespace std;

template<class T>
class Node
{
public:
    T data;
    Node<T>* left_child;
    Node<T>* right_child;
    int flag = 0;
};

template<class T>
class BinaryTree
{

public:
    BinaryTree()
    {
        root=NULL;
    }
    BinaryTree(T* lis, int len)
    {
        root=NULL;
        for(int i=0; i<len; i++)
        {
            insert_no_rec(lis[i]);
        }
    }
    ~BinaryTree()
    {
        deleteTree(root);
    }

    void deleteTree(Node<T>* node)
    {
        if(NULL==node)
        {
            return;
        }
        deleteTree(node->left_child);
        deleteTree(node->right_child);
        delete node;
        // node=NULL;
    }

    void insert_no_rec(T var)
    {
        Node<T>* p = root;
        if(p==NULL)
        {
            Node<T>* temp= new Node<T>;
            temp->left_child = NULL;
            temp->right_child = NULL;
            temp->data = var;
            temp->flag=0;
            root = temp;
            return ;
        }
        while (true)
        {
            if(var<p->data)
            {
                if(p->left_child)
                {
                    p = p->left_child;
                }
                else
                {
                    Node<T>* temp= new Node<T>;
                    temp->left_child = NULL;
                    temp->right_child = NULL;
                    temp->data = var;
                    temp->flag=0;
                    p->left_child = temp;
                    return;
                }
            }
            else if (var>p->data)
            {
                if(p->right_child)
                {
                    p = p->right_child;
                }
                else
                {
                    Node<T>* temp= new Node<T>;
                    temp->left_child = NULL;
                    temp->right_child = NULL;
                    temp->data = var;
                    temp->flag=0;
                    p->right_child = temp;
                    return;     
                }
            }
            else
            {
                return;
            }
            
        }
        
    }
    void pre_order(Node<T>* node)
    {
        if(node)
        {
            cout<<node->data<<"  ";
            pre_order(node->left_child);
            pre_order(node->right_child);
        }
    }

    Node<T>* get_root() const
    {
        return root;
    }

    int check(Node<T>* node, T v)
    {
        if(node->flag)
        {
            if(v<node->data){return check(node->left_child, v);}
            else if(v>node->data){return check(node->right_child, v);}
            else{return 0;} // 如果相等这认为该值已经出现过了，
        }
        else // 没有被访问过时
        {
            if(v==node->data)
            {
                node->flag=1;
                return 1;
            }
            else // 如果不相等
            {return 0;}
        }

    }

private:
    Node<T>* root;
};


int main(int argc, char const *argv[])
{
    int num1[] = {3,2,4,1};
    int num2[] = {3,1,4,2};
    BinaryTree<int> tree1(num1, 4);

    tree1.pre_order(tree1.get_root());
    cout<<endl;

    // 3.只建一棵树，再判断其他序列是否与该树一致
    for(int i=0; i<4; i++)
    {
        if(!tree1.check(tree1.get_root(), num2[i]))
        {
            cout<<"not same!"<<endl;
        }
    }
    return 0;
}


