/*
序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，
    同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，
    你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

提示: 输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。
    你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

*/
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<sstream> 
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void levelOrder(TreeNode* root){
    if(root==nullptr){return ;}
    queue<TreeNode*>memo;
    memo.push(root);
    while(!memo.empty()){
        TreeNode* tmp = memo.front();
        cout<<tmp->val<<" ";
        memo.pop();
        if(tmp->left){
            memo.push(tmp->left);
        }
        if(tmp->right){
            memo.push(tmp->right);
        }
    }

}

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    string nums="";
    queue<TreeNode*>nodes;
    nodes.push(root);
    while(!nodes.empty()){
       TreeNode* node = nodes.front();
       nodes.pop();
       if(node==nullptr){
           nums += "* ";
       }else{
           nums += to_string(node->val);
           nums +=" ";
           nodes.push(node->left);
           nodes.push(node->right);
       }
    }
    return nums;
}


// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    vector<TreeNode*> tree;
    stringstream str(data);
    string t = "";
    while(str>>t){
        if(t=="*"){
            tree.push_back(nullptr);
        }else{
            tree.push_back(new TreeNode(stoi(t)));
        }
    }

    int pos = 1;
    for(int i = 0; i < tree.size(); i++){
        // 10 * 30 40 50 * * * 60 * *
        /*
            10
           *  30
             40 50
        */
        if(tree[i] == nullptr){
            continue;
        }
        tree[i]->left = tree[pos++];
        tree[i]->right = tree[pos++];
    }
    return tree[0];
}



// Encodes a tree to a single string.
string serialize1(TreeNode* root) {
    if(root==nullptr){
        return "*";
    }
    return to_string(root->val)+ " " + serialize1(root->left) + " " + serialize1(root->right);
}

TreeNode* dfs1(queue<string>&q){
    string t = q.front();
    q.pop();
    if(t=="*"){
        return nullptr;
    }
    TreeNode* root = new TreeNode(stoi(t));
    root->left = dfs1(q);
    root->right = dfs1(q);
    return root; 
}


// Decodes your encoded data to tree.
TreeNode* deserialize1(string data) {
    queue<string>q;
    stringstream str(data);
    string t = "";
    while(str>>t){
        // cout<<t<<"  ";
        q.emplace(t);
    }
    return dfs1(q);
}


int main(int argc, char const *argv[])
{
    TreeNode* root = new TreeNode(10);
    // root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->right->left = new TreeNode(40);
    root->right->right = new TreeNode(50);
    root->right->right->right = new TreeNode(60);

    levelOrder(root);
    cout<<endl;

    string s = serialize(root);
    cout<<s<<endl;

    root = deserialize(s);

    levelOrder(root);
    cout<<endl;

    return 0;
}
