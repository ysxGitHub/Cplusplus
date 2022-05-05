/*
给定一个单链表 L 的头节点 head ，单链表 L 表示为：

L0 → L1 → … → Ln - 1 → Ln
请将其重新排列后变为：

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
*/
#include<vector>
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reorderList1(ListNode* head) {
    if(head->next==nullptr||head==nullptr) return ;
    vector<ListNode*> cnt;
    ListNode* p = head;
    while(p){
        cnt.emplace_back(p);
        p = p->next;
    }
    int n = cnt.size();
    for(int i=0; i<n; i++) cnt[i]->next = nullptr;

    for(int i=0; i<n/2; i++){
        cnt[i]->next = cnt[n-1-i];
        if(i+1<(n+1)/2) cnt[i]->next->next = cnt[i+1];
    }
}

ListNode* reverseList(ListNode* head){
    ListNode* pre = nullptr;
    ListNode* cur = head;
    ListNode* next = nullptr;
    while(cur){
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

ListNode* findListMid(ListNode* head){
    ListNode* fast=head;
    ListNode* slow=head;

    while(fast->next!=nullptr&&fast->next->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void mergeList(ListNode* head1, ListNode* head2){
    ListNode* p1;
    ListNode* p2;
    while(head1!=nullptr&&head2!=nullptr){
        p1 = head1->next;
        p2 = head2->next;

        head1->next = head2;
        head1 = p1;

        head2->next = head1;
        head2 = p2;
    }
}

void reorderList(ListNode* head) {
    if(head->next==nullptr) return;

    ListNode* l1 = head;
    ListNode* mid = findListMid(head);
    ListNode* l2 = mid->next;
    mid->next = nullptr;

    l2 = reverseList(l2);

    mergeList(l1, l2);

}

int main(int argc, char const *argv[])
{

    return 0;
}
