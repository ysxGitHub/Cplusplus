#include <iostream>

using namespace std;

template <class T>
class AVLNode
{
public:
    T data;
    AVLNode<T> *left_child = NULL;
    AVLNode<T> *right_child = NULL;
    AVLNode<T> *parent = NULL;
    int bf = 0;
};

template <class T>
class AVLTree
{

public:
    AVLTree()
    {
        root = NULL;
    }
    AVLTree(T *lis, int len)
    {
        root = NULL;
        for (int i = 0; i < len; i++)
        {
            insert_no_rec(lis[i]);
        }
    }
    ~AVLTree()
    {
        deleteTree(root);
    }

    void insert_no_rec(T var)
    {
        AVLNode<T> *p = root;
        AVLNode<T> *node = NULL;
        if (p == NULL)
        {
            AVLNode<T> *temp = new AVLNode<T>;
            temp->left_child = NULL;
            temp->right_child = NULL;
            temp->parent = NULL;
            temp->data = var;
            root = temp;
            return;
        }
        while (true)
        {
            if (var < p->data)
            {
                if (p->left_child)
                {
                    p = p->left_child;
                }
                else
                {
                    AVLNode<T> *temp = new AVLNode<T>;
                    temp->left_child = NULL;
                    temp->right_child = NULL;
                    temp->parent = NULL;
                    temp->data = var;
                    p->left_child = temp;
                    p->left_child->parent = p;
                    node = temp;
                    break;
                }
            }
            else if (var > p->data)
            {
                if (p->right_child)
                {
                    p = p->right_child;
                }
                else
                {
                    AVLNode<T> *temp = new AVLNode<T>;
                    temp->left_child = NULL;
                    temp->right_child = NULL;
                    temp->parent = NULL;
                    temp->data = var;
                    p->right_child = temp;
                    p->right_child->parent = p;
                    node = temp;
                    break;
                }
            }
            else
            {
                return;
            }
        }
        rebalance(node);
    }

    void pre_order(AVLNode<T> *node)
    {
        if (node)
        {
            cout << node->data << "  ";
            pre_order(node->left_child);
            pre_order(node->right_child);
        }
    }
    void in_order(AVLNode<T> *node)
    {
        if (node)
        {
            in_order(node->left_child);
            cout << node->data << "  ";
            in_order(node->right_child);
        }
    }
    void post_order(AVLNode<T> *node)
    {
        if (node)
        {
            post_order(node->left_child);
            post_order(node->right_child);
            cout << node->data << "  ";
        }
    }

    int postOrderHeight(AVLNode<int>* node)
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

    void treeAllLeaf(AVLNode<int>* node)
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

    AVLNode<T> *get_root() const
    {
        return root;
    }

    AVLNode<T>* query_no_rec(T var)
    {
        AVLNode<T>* p = root;
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
            AVLNode<T>* node = query_no_rec(var);
            if(node==NULL)
            {
                return false;
            }
            else if((node->left_child==NULL)&&(node->right_child==NULL)) //?????????
            {
                remove_node_1(node);
                return true;
            }
            else if(node->right_child==NULL) //???????????????
            {
                remove_node_21(node);
                return true;
            }
            else if(node->left_child==NULL)  //???????????????
            {
                remove_node_22(node);
                return true;
            }
            else //??????????????????
            {
                AVLNode<T>* min_node = node->right_child;
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


private:
    AVLNode<T> *root;
    // ??????????????????????????????
    AVLNode<T> *rotate_left(AVLNode<T> *c, AVLNode<T> *p)
    {
        AVLNode<T> *s2 = c->left_child;
        p->right_child = s2;
        if (s2 != NULL)
        {
            s2->parent = p;
        }
        c->left_child = p;
        p->parent = c;

        p->bf = 0;
        c->bf = 0;

        return c;
    }
    // ??????????????????????????????
    AVLNode<T> *rotate_right(AVLNode<T> *c, AVLNode<T> *p)
    {
        AVLNode<T> *s2 = c->right_child;
        p->left_child = s2;
        if (s2 != NULL)
        {
            s2->parent = p;
        }
        c->right_child = p;
        p->parent = c;

        p->bf = 0;
        c->bf = 0;

        return c;
    }
    // ???????????????????????????/?????????
    AVLNode<T> *rotate_right_left(AVLNode<T> *c, AVLNode<T> *p)
    {
        AVLNode<T> *g = c->left_child;
        AVLNode<T> *s3 = g->right_child;
        c->left_child = s3;
        if (s3 != NULL)
        {
            s3->parent = c;
        }
        g->right_child = c;
        c->parent = g;

        AVLNode<T> *s2 = g->left_child;
        p->right_child = s2;
        if (s2 != NULL)
        {
            s2->parent = p;
        }
        g->left_child = p;
        p->parent = g;

        if (g->bf > 0)
        {
            p->bf = 0;
            c->bf = -1;
        }
        else if (g->bf < 0)
        {
            p->bf = 1;
            c->bf = 0;
        }
        else
        {
            p->bf = 0;
            c->bf = 0;
        }
        g->bf = 0;

        return g;
    }

    // ???????????????????????????/?????????
    AVLNode<T> *rotate_left_right(AVLNode<T> *c, AVLNode<T> *p)
    {
        AVLNode<T> *g = c->right_child;
        AVLNode<T> *s2 = g->left_child;
        c->right_child = s2;
        if (s2 != NULL)
        {
            s2->parent = c;
        }
        g->left_child = c;
        c->parent = g;

        AVLNode<T> *s3 = g->right_child;
        p->left_child = s3;
        if (s3 != NULL)
        {
            s3->parent = p;
        }
        g->right_child = p;
        p->parent = g;

        if (g->bf > 0)
        {
            p->bf = -1;
            c->bf = 0;
        }
        else if (g->bf < 0)
        {
            p->bf = 0;
            c->bf = 1;
        }
        else
        {
            p->bf = 0;
            c->bf = 0;
        }
        g->bf = 0;

        return g;
    }

    void rebalance(AVLNode<T> * node)
    {
        // ??????balance factor
        while (node->parent != NULL)
        {
            // ??????????????????????????????
            AVLNode<T> *g = NULL;
            // ?????????????????????
            AVLNode<T> *n = NULL;
            // ???????????????????????????parent
            AVLNode<T> *x = NULL;
            // ???????????????????????????
            if (node->parent->left_child == node)
            {
                // ?????????node->parent??????????????????node->parent.bf=1????????????????????????????????????????????????node->parent.bf=2
                if (node->parent->bf > 0)
                {
                    g = node->parent->parent;
                    x = node->parent;
                    // ??????node.bf=-1?????????node?????????????????? ?????????????????????
                    if (node->bf < 0)
                    {
                        n = rotate_left_right(node, node->parent);
                    }
                    else
                    {
                        n = rotate_right(node, node->parent);
                    }
                }
                // ?????????node->parent??????????????????node->parent.bf=-1????????????????????????????????????????????????node->parent.bf=0
                else if (node->parent->bf < 0)
                {
                    node->parent->bf = 0;
                    break;
                }
                // ?????????node->parent???????????????node->parent.bf=0????????????????????????????????????????????????node->parent.bf=1
                else
                {
                    node->parent->bf = 1;
                    node = node->parent;
                    continue;
                }
            }
            else
            {
                // ?????????node->parent??????????????????node->parent.bf=-1????????????????????????????????????????????????node->parent.bf=-2
                if (node->parent->bf < 0)
                {
                    g = node->parent->parent;
                    x = node->parent;
                    // ??????node.bf=1?????????node?????????????????? ?????????????????????
                    if (node->bf > 0)
                    {
                        n = rotate_right_left(node, node->parent);
                    }
                    else
                    {
                        n = rotate_left(node, node->parent);
                    }
                }
                // ?????????node->parent??????????????????node->parent.bf=1????????????????????????????????????????????????node->parent.bf=0
                else if (node->parent->bf > 0)
                {
                    node->parent->bf = 0;
                    break;
                }
                // ?????????node->parent???????????????node->parent.bf=0????????????????????????????????????????????????node->parent.bf=-1
                else
                {
                    node->parent->bf = -1;
                    node = node->parent;
                    continue;
                }
            }
            // ????????????????????????
            n->parent = g;
            if (g != NULL)
            {
                if (x == g->left_child)
                {
                    g->left_child = n;
                }
                else
                {
                    g->right_child = n;
                }
                break;
            }
            // g???NULL??????n???root
            else
            {
                root = n;
                break;
            }
        }
    }

    // ??????????????????????????????
    void remove_node_1(AVLNode<T>* node)
    {
        AVLNode<T>* pNode = node->parent;
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
        rebalance(pNode);
    }
    // ???????????????????????????????????????
    void remove_node_21(AVLNode<T>* node)
    {
        if(node->parent==NULL) 
        {
            AVLNode<T>* temp = root;
            root = node->left_child;
            node->left_child->parent = NULL;
            delete temp;
        }       
        else if(node==node->parent->left_child)
        {
            AVLNode<T>* temp = node;
            node->parent->left_child = node->left_child;
            node->left_child->parent = node->parent;
            delete temp;
        }
        else
        {
            AVLNode<T>* temp = node;
            node->parent->right_child = node->left_child;
            node->left_child->parent = node->parent;
            delete temp; 
        }
        rebalance(node->left_child);
    }
    // ???????????????????????????????????????
    void remove_node_22(AVLNode<T>* node)
    {
        if(node->parent==NULL) 
        {
            AVLNode<T>* temp = root;
            root = node->right_child;
            node->right_child->parent = NULL;
            delete temp;
        }       
        else if(node==node->parent->left_child)
        {
            AVLNode<T>* temp = node;
            node->parent->left_child = node->right_child;
            node->right_child->parent = node->parent;
            delete temp;
        }
        else
        {
            AVLNode<T>* temp = node;
            node->parent->right_child = node->right_child;
            node->right_child->parent = node->parent;
            delete temp; 
        }
        rebalance(node->right_child);
    }

    void deleteTree(AVLNode<T> *node)
    {
        if (NULL == node)
        {
            return;
        }
        deleteTree(node->left_child);
        deleteTree(node->right_child);
        delete node;
        // node=NULL;
    }

};

int main(int argc, char const *argv[])
{
    int num[] = {4, 6, 7, 9, 2, 1, 3, 5, 8};
    AVLTree<int> tree(num, 9);
    tree.pre_order(tree.get_root());
    cout<<endl;
    tree.in_order(tree.get_root());
    cout<<endl;
    cout<<tree.postOrderHeight(tree.get_root())<<endl;
    tree.treeAllLeaf(tree.get_root());
    cout<<endl;

    tree.delete_node(1);
    tree.pre_order(tree.get_root());
    cout<<endl;
    tree.in_order(tree.get_root());
    cout<<endl;

    return 0;
}


