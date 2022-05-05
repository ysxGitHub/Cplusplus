/*
给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。

构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。复制链表中的指针都不应指向原链表中的节点 。

例如，如果原链表中有 X 和 Y 两个节点，其中 X.random --> Y 。那么在复制链表中对应的两个节点 x 和 y ，同样有 x.random --> y 。

返回复制链表的头节点。

就是链表的deepcopy
*/
#include <iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


Node* copyRandomList(Node* head) {
    if(head==nullptr) return head;

    // 1->2->3  ==>  1->1'->2->2'->3->3'
    Node* node = head;
    while(node){
        Node* tmp = node->next;
        node->next = new Node(node->val, node->next, nullptr);
        node = tmp;
    }

    // 处理random指针
    node = head;
    while(node){
        node->next->random = node->random?node->random->next:nullptr;
        node = node->next->next;
    }

    // 还原原始链表，即分离原链表和克隆链表
    node = head;
    Node* newHead = head->next;
    while(node->next){
        Node* tmp = node->next;
        node->next = node->next->next;
        node = tmp;
    }
    return newHead;
}