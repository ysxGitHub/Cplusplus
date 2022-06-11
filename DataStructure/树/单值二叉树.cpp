/*
如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
只有给定的树是单值二叉树时，才返回 true；否则返回 false。
*/


bool helper(TreeNode* root, const int& val){
    if(!root) return 1;
    if(root->val!=val) return 0;
    return helper(root->left, val)&helper(root->right, val);
}
bool isUnivalTree(TreeNode* root) {
    int val = root->val;
    return helper(root, val);
}