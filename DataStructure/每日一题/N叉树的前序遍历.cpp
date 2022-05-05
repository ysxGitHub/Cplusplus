/*
给定一个 n 叉树的根节点  root ，返回 其节点值的 前序遍历 。

n 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 null 分隔（请参见示例）。
*/
#include<vector>
#include<stack>
#include<iostream>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

vector<int>ans;
vector<int> preorder(Node* root) {
    if(root==nullptr){
        return ans;
    }
    ans.emplace_back(root->val);
    for(auto& c: root->children){
        preorder(c);
    }
    return ans;
}


vector<int> preorder1(Node* root) {
    if(root==nullptr){
        return ans;
    }
    stack<Node* >stk;
    stk.emplace(root);
    while(!stk.empty()){
        Node* parent = stk.top();
        ans.emplace_back(parent->val);
        stk.pop();
        for(auto it=parent->children.rbegin(); it!=parent->children.rend(); ++it){
            stk.emplace(*it);
        }
    }
    return ans;
}

