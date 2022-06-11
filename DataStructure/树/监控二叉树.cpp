/*
给定一个二叉树，我们在树的节点上安装摄像头。

节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。

计算监控树的所有节点所需的最小摄像头数量。
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int result=0;
int trevesal(TreeNode* root){
    // 空节点默认为 有覆盖状态，避免在叶子节点上放摄像头
    if(!root) return 2;
    int left = trevesal(root->left);
    int right = trevesal(root->right);
    // 如果左右节点都覆盖了的话, 那么本节点的状态就应该是无覆盖,没有摄像头
    if(left==2&&right==2) return 0;
    // 左右节点都是无覆盖状态,那 根节点此时应该放一个摄像头
    // (0,0) (0,1) (0,2) (1,0) (2,0)
    // 状态值为 1 摄像头数 ++;
    if(left==0||right==0){
        result++;
        return 1;
    }
    // 左右节点的 状态为 (1,1) (1,2) (2,1) 也就是左右节点至少存在 1个摄像头，
    // 那么本节点就是处于被覆盖状态
    if(left==1||right==1) return 2;
    return -1;
}
int minCameraCover(TreeNode* root) {
    if(trevesal(root)==0) result++;
    return result;
}