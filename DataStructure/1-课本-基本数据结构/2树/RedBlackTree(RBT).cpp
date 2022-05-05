#include<iostream>
using namespace std;
#define RED false
#define BLACK true

/*
红黑树的性质：
    1.节点是红色或黑色
    2.根节点是黑色，每个叶子节点都是黑色的空节点（NULL）
    3.每个红色节点的子节点都是黑色（从每个叶节点到根的所有路径不能有两个连续的红色节点）
    4.从任一节点到其每个叶节点的所有路径都包含相同数目的黑色节点

*/
template <class T>
class RBNode
{
public:
    RBNode():left_child(NULL),right_child(NULL),parent(NULL){}
    RBNode(T d, bool c, RBNode<T> *l=NULL, RBNode<T> *r=NULL, RBNode<T> *p=NULL):data(d),color(c),left_child(l),right_child(r),parent(p){}

public:
    RBNode<T> *left_child;
    RBNode<T> *right_child;
    RBNode<T> *parent;
    bool color;
    T data;
};

template <class T>
class RBTree
{

public:
    RBTree()
    {
        root = NULL;
    }
    RBTree(T *lis, int len)
    {
        root = NULL;
        for (int i = 0; i < len; i++)
        {
            insert(lis[i]);
        }
    }
    ~RBTree()
    {
        deleteTree(root);
    }
    
    RBNode<T> *get_root() const
    {
        return root;
    }

    void set_root(RBNode<T> * node)
    {   
        root = node;
    }
    
    void insert(T var)
    {
        /*
        红黑树节点的插入
        1.普通的二叉树的插入
            先查找插入的位置
            创建新节点，插入tree中
        2.红黑树的调整（旋转 + 变色）
        */
        RBNode<T> *p = root;
        RBNode<T> *node = NULL;
        // 判断根节点是否为空
        if (p == NULL)
        {
            root = new RBNode<T>(var, BLACK, NULL, NULL, NULL);
            return;
        }
        // 进行循环查找要插入的位置
        while (true)
        {
            // cout<<var<<" "<<p->data<<endl;
            if (var < p->data)
            {
                if (p->left_child!=NULL)
                {
                    p = p->left_child;
                }
                else
                {
                    node = new RBNode<T>(var, RED);
                    p->left_child = node;
                    p->left_child->parent = p;
                    break;
                }
            }
            else if (var > p->data)
            {
                if (p->right_child!=NULL)
                {
                    p = p->right_child;
                }
                else
                {
                    node = new RBNode<T>(var, RED);
                    p->right_child = node;
                    p->right_child->parent = p;
                    break;
                }
            }
            else
            {
                return;
            }
        }
        // 平衡
        fixAfterinsert(node);
    }

    RBNode<T> * query(T var)
    {
        RBNode<T> *p = root;
        while (p){
            if(p->data>var){
                p= p->left_child;
            }
            else if(p->data<var){
                p = p->right_child;
            }
            else{
                return p;
            }
        }
        return NULL;
    }

    bool remove(T var)
    {
        if(root==NULL)
        {
            return false;
        }
        RBNode<T>* node = query(var);
        if(node==NULL)
        {
            return false;
        }
        else
        {
            // 删除节点
            deleteNode(node);
            return true;
        }

    }


    void pre_order(RBNode<T> *node)
    {
        if (node)
        {
            cout << node->data << "("<<node->color<<") ";
            pre_order(node->left_child);
            pre_order(node->right_child);
        }
    }   


private:
    RBNode<T> *root;
    // 右子树的右插入：左旋
    RBNode<T> *rotate_left(RBNode<T> *p)
    {
        /*
         *     P              c
         *   / \            / \
         * pl   c          p   cr
         *    / \        / \
         *  cl  cr     pl   cl
        */
       RBNode<T> *c = p->right_child;
        RBNode<T> *s2 = c->left_child;
        // 1.将pl->c变为pl->cl
        p->right_child = s2;
        if (s2 != NULL)
        {
            s2->parent = p;
        }
        // 2.判断p是否有父节点
        c->parent = p->parent;
        if(p->parent==NULL)
        {
            root = c;
        }
        else if(p->parent->left_child==p)
        {
            p->parent->left_child = c;
        }
        else
        {
            p->parent->right_child = c;
        }
        // 最后设置p为c的左子节点
        c->left_child = p;
        p->parent = c;

        return p;
    }
    // 左子树的左插入：右旋
    RBNode<T> *rotate_right(RBNode<T> *p)
    {
        /*
         *        P              c
         *      / \            / \
         *     c  pr         cl   p
         *   / \                 / \
         * cl  cr              cr   pr
        */
        RBNode<T> *c = p->left_child;
        RBNode<T> *s2 = c->right_child;
        // 1.将pr->c变为pr->cr
        p->left_child = s2;
        if (s2 != NULL)
        {
            s2->parent = p;
        }
        // 2.判断p是否有父节点
        c->parent = p->parent;
        if(p->parent==NULL)
        {
            root = c;
        }
        else if(p->parent->left_child==p)
        {
            p->parent->left_child = c;
        }
        else
        {
            p->parent->right_child = c;
        }
        // 最后设置p为c的右子节点
        c->right_child = p;
        p->parent = c;

        return p;
    }
    /*
    * 2节点新增一个节点的情况 (当要插入的节点的父节点为红色就需要调整)
    *       p(black)      p(black)     p(black)    另外三种情况对称     
    *     / \           / \          / \
    *   pl  pr(red)   pl(red)      pl(red)
    *                /              \
    *              pll(red)         pll(red)
    * 3节点新增一个节点的情况
    * 
    * 
    * 
    */
    void fixAfterinsert(RBNode<T> *node){
        // 将插入的节点设为红色
        node->color=RED;
        while(node!=NULL && node!=root && node->parent->color==RED){
            // 1.node的父节点是node的爷爷节点的左子节点情况的4种问题
            if(node->parent==node->parent->parent->left_child){
                // 根据是否有叔叔节点将4种问题一分为二
                if(node->parent->parent->right_child!=NULL){
                    node->parent->color=BLACK;
                    node->parent->parent->right_child->color=BLACK;
                    node->parent->parent->color=RED;
                    node = node->parent->parent;
                }
                else{
                    if(node==node->parent->right_child){
                        // 插入节点是父节点的右侧节点，要先根据父亲做一次左旋转
                        node = node->parent;
                        node = rotate_left(node);
                    }
                    node->parent->color=BLACK;
                    node->parent->parent->color=RED;
                    // 根据爷爷节点做右旋
                    node = rotate_right(node->parent->parent);
                }
            }
            else{
                 // 根据是否有叔叔节点将4种问题一分为二
                if(node->parent->parent->left_child!=NULL){
                    node->parent->color=BLACK;
                    node->parent->parent->left_child->color=BLACK;
                    node->parent->parent->color=RED;
                    node = node->parent->parent;
                }
                else{
                    if(node==node->parent->left_child){
                        // 插入节点是父节点的左侧节点，要先根据父亲做一次右旋转
                        node = node->parent;
                        node = rotate_right(node);
                    }
                    node->parent->color=BLACK;
                    node->parent->parent->color=RED;
                    // 根据爷爷节点做左旋
                    node = rotate_left(node->parent->parent);
                }
            }
        }

        root->color=BLACK;
    }
    // 找到要删除节点的前置节点(<)
    RBNode<T> * Predecesspr(RBNode<T> *node)
    {
        if(node==NULL){
            return NULL;
        }
        else if(node->left_child!=NULL){
            RBNode<T> *p = node->left_child;
            while(p->right_child!=NULL){
                p = p->right_child;
            }
            return p;
        }
        else{
            // 这种情况在删除种是不会出现的（原因该情况该节点为叶节点），但是找该节点的前置和后置节点的情况还是会存在的
            RBNode<T> *p = node->parent;
            RBNode<T> *ch = node;
            while (p!=NULL && ch==p->left_child){
                ch = p;
                p = p->parent; 
            }
            return p;
        }
    }
    // 找到要删除节点的后置节点(>)
    RBNode<T> * Seccessor(RBNode<T> *node)
    {
        if(node==NULL){
            return NULL;
        }
        else if(node->right_child!=NULL){
            RBNode<T> *p = node->right_child;
            while(p->left_child!=NULL){
                p = p->left_child;
            }
            return p;
        }
        else{
            // 这种情况在删除种是不会出现的（原因该情况该节点为叶节点），但是找该节点的前置和后置节点的情况还是会存在的
            RBNode<T> *p = node->parent;
            RBNode<T> *ch = node;
            while (p!=NULL && ch==p->right_child){
                ch = p;
                p = p->parent; 
            }
            return p;
        }
    }
    void fixAfterRemove(RBNode<T> *node)
    {
        // 情况2和3
        while(node!=root && node->color==BLACK){
            if(node==node->parent->left_child){
                // 找兄弟节点
                RBNode<T> *rNode = node->parent->right_child;
                // 不是真正的兄弟节点（因为兄弟节点为红色表示其节点还有子节点）
                /*     前             后   （pl==node）
                *     P(b)           c(b)
                *   / \            / \
                * pl   c(c)    p(c)   cr
                *    / \       / \
                *  cl  cr    pl  cl
                */
                if(rNode->color==RED){
                    rNode->color = BLACK;
                    node->parent->color = RED;
                    node->parent = rotate_left(node->parent);
                    rNode = node->parent->right_child;
                } // 情况3 兄弟节点没有子节点
                if(rNode->left_child==NULL && rNode->right_child==NULL){
                    rNode->color = RED;
                    node = node->parent;
                } // 情况2 兄弟节点有子节点
                // 不是真正的兄弟节点（因为兄弟节点为红色表示其节点还有子节点）
                /*     前        中          后   （pl==node）
                *     P(c)      p(c)           cl(rN)(c)  
                *   / \        / \             /  \
                * pl   c(b)  pl cl(rN)      p(b)  c(b)
                *    /           \         /
                *  cl            c(b)    pl
                */
                else{
                    // 不存在右节点
                    if(rNode->right_child==NULL){
                        rNode->color=RED;
                        rNode->left_child->color=BLACK;
                        rNode = rotate_right(rNode);
                        rNode = node->parent->right_child;
                    }
                    rNode->color = node->parent->color;
                    node->parent->color = BLACK;
                    rNode->right_child->color = BLACK;
                    node->parent = rotate_left(node->parent);
                    node = root;
                }
            }
            else{
                // 找兄弟节点
                RBNode<T> *rNode = node->parent->left_child;
                // 不是真正的兄弟节点（因为兄弟节点为红色表示其节点还有子节点）
                if(rNode->color==RED){
                    rNode->color = BLACK;
                    node->parent->color = RED;
                    node->parent = rotate_right(node->parent);
                    rNode = node->parent->left_child;
                } // 情况3 兄弟节点没有子节点
                if(rNode->left_child==NULL && rNode->right_child==NULL){
                    rNode->color = RED;
                    node = node->parent;
                } // 情况2 兄弟节点有子节点
                // 不是真正的兄弟节点（因为兄弟节点为红色表示其节点还有子节点）
                else{
                    // 不存在右节点
                    if(rNode->left_child==NULL){
                        rNode->color=RED;
                        rNode->right_child->color=BLACK;
                        rNode = rotate_left(rNode);
                        rNode = node->parent->left_child;
                    }
                    rNode->color = node->parent->color;
                    node->parent->color = BLACK;
                    rNode->left_child->color = BLACK;
                    node->parent = rotate_right(node->parent);
                    node = root;
                }
            }
        }
        // 情况1 替代节点是红色直接设置为黑色
        node->color = BLACK;
    }
    /*
    * 1.删除叶子节点
    * 2.删除节点有一个子节点，用子节点来替代
    * 3.删除节点有两个子节点，此时要获得对应的前置或后置节点来替代
    *   转换为1、2情况
    */
    void deleteNode(RBNode<T> *node)
    {
        // 情况3   删除节点有两个子节点，此时要获得对应的前置或后置节点来替代   转换为1、2情况
        if(node->left_child!=NULL && node->right_child!=NULL){
            // 找到要删除节点的后置节点
            RBNode<T> *successor = Predecesspr(node);
            // 用后置节点的值覆盖要删除节点的信息
            node->data = successor->data;
            // 然后要删除的节点变为后置节点
            node = successor;
        }
        
        RBNode<T> * replacement = node->left_child!=NULL ? node->left_child : node->right_child;
        // 情况2   删除节点有一个子节点，用子节点来替代
        if(replacement!=NULL){
            // 将要删除节点的子节点与其父节点相连
            replacement->parent = node->parent;
            if(node->parent==NULL){
                root = replacement;
            }
            else if(node==node->parent->left_child){
                node->parent->left_child = replacement;
            }
            else{
                node->parent->right_child = replacement;
            }
            // 调整
            if(node->color==BLACK)
            {
                fixAfterRemove(replacement);
            }
            // 删除node
            delete node;
            node->left_child = node->right_child = node->parent = NULL;
        } 
        else if(node->parent==NULL){
            delete root;
            root=NULL;
        } // 情况1  删除叶子节点
        else{
            // 先调整
            if(node->color==BLACK)
            {
                fixAfterRemove(node);
            }
            // 删除
            if(node->parent!=NULL){
                if(node==node->parent->left_child){
                    node->parent->left_child = NULL;
                }
                else{
                    node->parent->right_child = NULL;
                }
                delete node;
                node=NULL;
            }
        }

    }

    void deleteTree(RBNode<T> *node)
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
    RBTree<int> tree(num, 9);
    tree.pre_order(tree.get_root());
    cout<<endl;  
    tree.remove(4);
    tree.pre_order(tree.get_root());
    cout<<endl;  
    return 0;
}



