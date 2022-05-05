/*
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
    你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
*/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseNode(ListNode* head, ListNode* tail){
    ListNode* pre = nullptr;
    ListNode* cur = head;
    ListNode* next = nullptr;
    while(cur!=tail){
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next; 
    }
    return pre;
}

ListNode* swapPairs(ListNode* head) {
    ListNode* a = head, *b = head;
    for(int i=0; i<2; i++){
        if(b==nullptr){return head;}
        b = b->next;
    }
    ListNode* newHead = reverseNode(a, b);
    a->next = swapPairs(b);
    return newHead;
}