/*
给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
*/
#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if(k==0||head==nullptr||head->next==nullptr) return head;
    ListNode* p = head;
    int cnt = 0;
    while(p->next){
        p = p->next;
        cnt++;
    }
    ++cnt;
    p->next = head;
    k = cnt - k%(cnt);
    --k;
    p = head;
    while(k--){
        p = p->next;
    }
    head = p->next;
    p->next = nullptr;
    return head;
}