/*
给定一棵二叉树中的两个节点 p 和 q，返回它们的最近公共祖先节点（LCA）。
*/
#include<iostream>
// #include<unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node left;
    Node right;
    Node parent;
};

Node* lowestCommonAncestor(Node* p, Node * q) {
    // 施展链表双指针技巧
    Node* a = p, *b = q;
    while (a != b) {
        // a 走一步，如果走到根节点，转到 q 节点
        if (a == NULL) a = q;
        else           a = a.parent;
        // b 走一步，如果走到根节点，转到 p 节点
        if (b == NULL) b = p;
        else           b = b.parent;
    }
    return a;
}