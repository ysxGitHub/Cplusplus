/*


*/
#include<stack>
// #include<vector>
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// 利用「栈」模拟函数递归的过程


void preOrderTravesal(TreeNode* node)
{
    stack<TreeNode*> V;
    TreeNode* T = node;
    while (T||!V.empty())
    {
        while (T)
        {
            // 先序遍历，压入栈之前就打印
            cout<<T->val<<" ";
            V.push(T);
            // 一直找到最左的节点，压入栈中
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

void inOrderTravesal(TreeNode* node)
{
    stack<TreeNode*> V;
    TreeNode* T = node;
    while (T||!V.empty())
    {
        while (T)
        {
            V.push(T);
            // 栈顶一定在最左边
            T = T->left;
        }
        if(!V.empty())
        {
            T = V.top();
            // 中序遍历在每次出栈时打印；
            cout<<T->val<<" ";
            V.pop();
            T = T->right;
        }
    }
    return ;
}



void postOrderTravesal(TreeNode* node)
{
    stack<TreeNode*> V;
    TreeNode* T = node;
    TreeNode* visited = NULL; //用于记录上一次访问得节点
    while (T||!V.empty())
    {
        while (T)
        {
            V.push(T);
            // 一直先左走
            T = T->left;
        }
        if(!V.empty())
        {
            // 
            T = V.top();
            V.pop();
            if(T->right==NULL||visited==T->right) //访问节点得条件（右节点为空，或者访问过右节点）
            {
                cout<<T->val<<" ";
                visited = T ; //记录上一次访问得节点
                T = NULL;  //跳过下一次循环的访问左子节点的过程，直接进入栈的弹出阶段，
                           // 它们的左子节点都肯定被经过且已放入栈中
            }
            else
            {
                V.push(T);    // 将已弹出的根节点放回栈中
                T = T->right; // 经过右子节点
            }
            
        }
    }
    return ;
}

//*****************************遍历**************************法2
stack<TreeNode*>stk;

void pushLeftbranch(TreeNode* node){
    while(node){
        //前序遍历
        //code
        // cout<<node->val<<" ";
        stk.push(node);
        node = node->left; 
    }
}

void traverse(TreeNode* root){
    // visited 指针初始化指向一个新 new 出来的二叉树节点，相当于一个特殊值，
    // 目的是避免和输入二叉树中的节点重复。如nullptr 影响中序遍历
    TreeNode* visited = new TreeNode(-1);
    pushLeftbranch(root);
    while(!stk.empty()){
        TreeNode* node = stk.top();
        if((node->left==nullptr||node->left==visited)&&node->right!=visited){
            //中序遍历
            // code
            cout<<node->val<<" ";   
            pushLeftbranch(node->right);
        }
        if(node->right==visited||node->right==nullptr){
            // 后序遍历
            // code
            // cout<<node->val<<" ";
            visited = node;
            stk.pop();
        }
    }
}

int main(int argc, char const *argv[])
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);    

    traverse(root);
    cout<<endl;
    inOrderTravesal(root);

    return 0;
}
