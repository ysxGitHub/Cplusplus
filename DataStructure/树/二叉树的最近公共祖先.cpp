/*
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，
    最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大
    （一个节点也可以是它自己的祖先）。”
*/

#include<iostream>
#include<unordered_set>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
• 最近公共祖先的情况无外乎三种情况，解答此题最好分别画出三种情况的草图，问题便迎刃而解
	○ 树形一：root为p,q中的一个，这时公共祖先为root
	○ 树形二：p,q分别在root的左右子树上（p在左子树，q在右子树；
        还是p在右子树，q在左子树的情况都统一放在一起考虑）
        这时满足p,q的最近公共祖先的结点也只有root本身
	○ 树形三：p和q同时在root的左子树；或者p,q同时在root的右子树，
        这时确定最近公共祖先需要遍历子树来进行递归求解。
	
• 清楚了这些，开始编写程序，首先要明确递归的方式，需要采用类似后序遍历的方式，先遍历左，
    右子树得到结果，再根据结果判断出当前树形属于前面三种讨论的哪一种，再返回相应的答案。

• 接下来开始着手实现细节：
	○ 明确递归边界：root为空（此时为空树），则直接返回NULL，不存在公共祖先；
        root为p或q中的一个，则直接返回root;
	    这两种情况都是不需要通过递归直接能得出答案的，故直接终止递归返回即可
	○ 用left，right分别去接收遍历左右子树得到的结点（这里递归返回值是结点指针）
	○ 如果left和right均不为空，注意此时left,right并不是理解为子树上p,q的最近公共祖先，
        而是结点p或q自身的指针，这时说明p,q分别存在于root根结点的左右两端，
        是符合树形二的情况，直接返回root。
	○ 如果left，right中有一个不为空，那么通过树形的分析，必然属于树形三;
	    此时left,right代表的含义就是子树上层层向上返回的最近公共祖先，
        最开始的调用层拿到这个结果后直接返回不空的那一个，即是答案。

*/

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL) {
        return NULL;
    }
    // 前序位置
    if (root==p || root==q) {
        // 如果遇到目标值，直接返回
        return root;
    }
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    // 后序位置，已经知道左右子树是否存在目标值
    if (left != NULL && right != NULL) {
        // 当前节点是 LCA 节点
        return root;
    }

    return left != NULL ? left : right;
}




int main(int argc, char const *argv[])
{
    // [3,5,1,6,2,0,8,null,null,7,4]
    TreeNode* root = new TreeNode(3);
    TreeNode* q = root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    TreeNode* p = root->left->right->right = new TreeNode(4);

    TreeNode*tmp = lowestCommonAncestor(root, p, q);
    cout<<tmp->val<<endl;

    return 0;
}
