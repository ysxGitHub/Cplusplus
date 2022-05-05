/*

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

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>>nums;
    queue<TreeNode*>nodes;
    queue<TreeNode*>nodes2;
    nodes.push(root);
    while(!nodes.empty()){
        // 遍历这一层的所有节点
        vector<int>num;
        TreeNode* node;
        while(!nodes.empty()){
            node = nodes.front();
            nodes.pop();
            num.push_back(node->val);
            nodes2.push(node);
        }
        while(!nodes2.empty()){
            node = nodes2.front();
            nodes2.pop();
            // 加入左右子节点
            if(node->left){
                nodes.push(node->left);
            }
            if(node->right){
                nodes.push(node->right);
            }

        }
        nums.push_back(num);
    }
    return nums;
}

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(15);


    vector<vector<int>> nums = levelOrder(root);
    for(auto& ns : nums){
        for(auto& n: ns){
            cout<<n<<"  ";
        }
        cout<<endl;
    }
    
    return 0;
}
