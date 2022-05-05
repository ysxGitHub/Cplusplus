/*

给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，
    则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

*/
#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

void twoConnect(Node* root_left, Node* root_right){
    if(root_left==nullptr||root_right==nullptr){
        return;
    }
    root_left->next = root_right;
    twoConnect(root_left->left, root_left->right);
    twoConnect(root_left->right, root_right->left);
    twoConnect(root_right->left, root_right->right);
}


Node* connect(Node* root) {
    if(root==nullptr){
        return root;
    }
    root->next = nullptr;
    twoConnect(root->left, root->right);
    return root;
}



int main(int argc, char const *argv[])
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root = connect(root);

    return 0;
}
