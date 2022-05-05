/*
给定一棵二叉树 root，返回所有重复的子树。

对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。

如果两棵树具有相同的结构和相同的结点值，则它们是重复的。

*/

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void levelOrder(TreeNode* root){
    queue<TreeNode*>node;
    node.push(root);
    while (!node.empty()){/* code */
        TreeNode* tmp = node.front();
        cout<<tmp->val<<"  ";
        node.pop();
        if(tmp->left){
            node.push(tmp->left);
        }
        if(tmp->right){
            node.push(tmp->right);
        }
    }
}

unordered_map<string, int>seen;
vector<TreeNode* >ans;

string preOrder(TreeNode* root){
    if(root==nullptr){
        return "*" ;
    }
    string left_subTree = preOrder(root->left);
    string right_subTree = preOrder(root->right);
    string subTree = left_subTree+","+right_subTree+"," + to_string(root->val);
    if(seen.find(subTree)==seen.end()){
        seen[subTree] = 1;
    }else{
        if(seen[subTree]==1){
            ans.push_back(root);
        }
        seen[subTree] += 1;
    }

    return subTree;
}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    preOrder(root);
    return ans;
}


int main(int argc, char const *argv[])
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);
    root->right->left->left = new TreeNode(4);

    levelOrder(root);

    cout<<endl;
    // string s1 = "aaa";
    // string s2 = "bbb";
    // string s = s1 + s2;
    // cout<<s<<endl;
    vector<TreeNode*>numsTree = findDuplicateSubtrees(root);
    for(auto&n : numsTree){
        cout<<n->val<<"  ";
    }

    return 0;
}
