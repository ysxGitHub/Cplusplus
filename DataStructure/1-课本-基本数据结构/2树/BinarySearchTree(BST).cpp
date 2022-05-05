#include<iostream>
using namespace std;

template<class T>
class Node
{
public:
    T data;
    Node<T>* left_child;
    Node<T>* right_child;
    Node<T>* parent;

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

    Node<T>* insert_rec(Node<T>* node, T var)
    {
        if(node==NULL)
        {
            Node<T>* temp= new Node<T>;
            temp->left_child = NULL;
            temp->right_child = NULL;
            temp->parent=NULL;
            temp->data = var;
            node = temp;
        }
        else if(var<node->data)
        {
            node->left_child = insert_rec(node->left_child, var);
            node->left_child->parent = node;
        }
        else if(var>node->data)
        {
            node->right_child = insert_rec(node->right_child, var);
            node->right_child->parent = node;
        }
        return node;
    }
    void insert_no_rec(T var)
    {
        Node<T>* p = root;
        if(p==NULL)
        {
            Node<T>* temp= new Node<T>;
            temp->left_child = NULL;
            temp->right_child = NULL;
            temp->parent=NULL;
            temp->data = var;
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
                    temp->parent=NULL;
                    temp->data = var;
                    p->left_child = temp;
                    p->left_child->parent = p;
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
                    temp->parent=NULL;
                    temp->data = var;
                    p->right_child = temp;
                    p->right_child->parent = p; 
                    return;     
                }
            }
            else
            {
                return;
            }
            
        }
        
    }

    Node<T>* query_rec(Node<T>* node, T var)
    {
        if(node!=NULL)
        {
            if(var<node->data)
            {
                return query_rec(node->left_child, var);
            }
            else if (var>node->data)
            {
                return query_rec(node->right_child, var);
            }
            else
            {
                return node;
            }
        }
        else
        {
            return NULL;
        }
    }
    Node<T>* query_no_rec(T var)
    {
        Node<T>* p = root;
        while (p)
        {
            if(p->data>var)
            {
                p= p->left_child;
            }
            else if(p->data<var)
            {
                p = p->right_child;
            }
            else
            {
                return p;
            }
        }
        return NULL;
    }

    bool delete_node(T var)
    {
        if(root)
        {
            Node<T>* node = query_no_rec(var);
            if(node==NULL)
            {
                return false;
            }
            else if((node->left_child==NULL)&&(node->right_child==NULL)) //叶节点
            {
                remove_node_1(node);
                return true;
            }
            else if(node->right_child==NULL) //只有左孩子
            {
                remove_node_21(node);
                return true;
            }
            else if(node->left_child==NULL)  //只有右孩子
            {
                remove_node_22(node);
                return true;
            }
            else //两个孩子都有
            {
                Node<T>* min_node = node->right_child;
                while (min_node->left_child)
                {
                    min_node = min_node->left_child;
                }
                node->data = min_node->data;
                if(min_node->right_child)
                {
                    remove_node_22(min_node);
                    return true;
                }
                else
                {
                    remove_node_1(min_node);
                    return true;
                }
            }
        }
        return false;
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
    void in_order(Node<T>* node)
    {
        if(node)
        {
            in_order(node->left_child);
            cout<<node->data<<"  ";
            in_order(node->right_child);
        }

    }
    void post_order(Node<T>* node)
    {
        if(node)
        {
            post_order(node->left_child);
            post_order(node->right_child);
            cout<<node->data<<"  ";
        }
    }

    int postOrderHeight(Node<int>* node)
    {
        int hl, hr, maxh;
        if(node)
        {
            hl = postOrderHeight(node->left_child);
            hr = postOrderHeight(node->right_child);
            maxh = (hl>hr)? hl: hr;
            return (maxh+1); 
        }
        else
        {
            return 0;
        }
    }

    void treeAllLeaf(Node<int>* node)
    {
        if(node)
        {
            treeAllLeaf(node->left_child);
            treeAllLeaf(node->right_child);
            if(node->left_child==NULL&&node->right_child==NULL)
            {
                cout<<node->data<<" ";
            }
        }
    }

    Node<T>* get_root() const
    {
        return root;
    }


private:
    Node<T>* root;
    // 要删除的节点为叶节点
    void remove_node_1(Node<T>* node)
    {
        if(node->parent==NULL)
        {
            delete root;
            root = NULL;
        }
        if(node==node->parent->left_child)
        {
            delete node->parent->left_child;
            node->parent->left_child = NULL;
        }
        else
        {
            delete node->parent->right_child;
            node->parent->right_child = NULL;
        }
    }
    // 要删除的节点只有一个左孩子
    void remove_node_21(Node<T>* node)
    {
        if(node->parent==NULL) 
        {
            Node<T>* temp = root;
            root = node->left_child;
            node->left_child->parent = NULL;
            delete temp;
        }       
        else if(node==node->parent->left_child)
        {
            Node<T>* temp = node;
            node->parent->left_child = node->left_child;
            node->left_child->parent = node->parent;
            delete temp;
        }
        else
        {
            Node<T>* temp = node;
            node->parent->right_child = node->left_child;
            node->left_child->parent = node->parent;
            delete temp; 
        }
    }
    // 要删除的节点只有一个右孩子
    void remove_node_22(Node<T>* node)
    {
        if(node->parent==NULL) 
        {
            Node<T>* temp = root;
            root = node->right_child;
            node->right_child->parent = NULL;
            delete temp;
        }       
        else if(node==node->parent->left_child)
        {
            Node<T>* temp = node;
            node->parent->left_child = node->right_child;
            node->right_child->parent = node->parent;
            delete temp;
        }
        else
        {
            Node<T>* temp = node;
            node->parent->right_child = node->right_child;
            node->right_child->parent = node->parent;
            delete temp; 
        }
    }

};

int main(int argc, char const *argv[])
{
    int num[] = {4,6,7,9,2,1,3,5,8};
    BinaryTree<int> tree(num, 9);

    tree.pre_order(tree.get_root());
    cout<<endl;
    tree.in_order(tree.get_root());
    cout<<endl;
    tree.post_order(tree.get_root());
    cout<<endl;
    cout<<"tree height:"<<tree.postOrderHeight(tree.get_root())<<endl;
    cout<<"tree All leaves: ";
    tree.treeAllLeaf(tree.get_root());
    cout<<endl;
    cout<<tree.query_no_rec(4)->data<<endl;

    tree.delete_node(4);
    tree.delete_node(5);
    tree.in_order(tree.get_root());
    cout<<endl;
    return 0;
}

