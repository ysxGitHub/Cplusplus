/*
给定一个二叉树，编写一个函数来获取这个树的最大宽度。树的宽度是所有层中的最大宽度。
    这个二叉树与满二叉树（full binary tree）结构相同，但一些节点为空。

每一层的宽度被定义为两个端点（该层最左和最右的非空节点，两端点间的null节点也计入长度）之间的长度。
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int widthOfBinaryTree(TreeNode* root) {
    if(root==nullptr) return 0;
    queue<pair<TreeNode*, long long>> que;
    que.emplace(root, 1);
    long long ans = 1;
    while(!que.empty()){
        int size = que.size();
        int pre = -1;
        long long offset = que.front().second*2;
        for(int i=0; i<size; i++){
            auto &cur = que.front();
            TreeNode* curNode =  cur.first;
            long long num = cur.second;
            if(i==0){
                pre = num;
            }else{
                ans = max(ans, num - pre + 1);
            }
            que.pop();
            if(curNode->left){
                que.emplace(curNode->left, num*2-offset);
            }
            if(curNode->right){
                que.emplace(curNode->right, num*2+1-offset);
            }
        }
    }
    return ans;
}
