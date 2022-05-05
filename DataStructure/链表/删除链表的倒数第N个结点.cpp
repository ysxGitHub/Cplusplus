/*
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
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


ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* p1 = head;
    ListNode* p2 = head;
    ListNode* tmp = NULL;
    int i=0;
    while (p1){
        if(i>=n){
            tmp=p2;
            p2=p2->next;
        }     
        p1=p1->next;
        i++;
    }
    if(tmp==NULL&&p2==head){
        return head->next;
    }
    tmp->next = p2->next;
    return head;
}

ListNode* LastKNode(ListNode* list, int k){
    ListNode* p = list;
    ListNode* p2 = list;
    int i=0;
    while(p){

        if(i>=k){
            p2 = p2->next;
        }
        p = p->next;
        i++;
    }
    return p2;
}


ListNode* removeNthFromEnd1(ListNode* head, int n) {
    //  头部插入空节点
    ListNode* demmy = new ListNode(-1);
    demmy->next = head;
    // 先找到倒数第n个节点的前一个节点 -> 倒数n+1
    ListNode* x = LastKNode(demmy, n+1);
    x->next = x->next->next;
    return demmy->next;
}

int main(int argc, char const *argv[])
{
    ListNode* l1 = new ListNode(1);

    vector<int>nums1 = {1,2,3};

    ListNode* p1 = l1;
    for(auto&n1: nums1){
        p1->next = new ListNode(n1);
        p1 = p1->next;
    }

    // p1 = removeNthFromEnd(l1->next, 1);
    // while(p1){
    //     cout<<p1->val<<endl;
    //     p1 = p1->next;
    // }

    // p1 = removeNthFromEnd1(l1->next, 1);
    // while(p1){
    //     cout<<p1->val<<endl;
    //     p1 = p1->next;
    // }

    return 0;
}