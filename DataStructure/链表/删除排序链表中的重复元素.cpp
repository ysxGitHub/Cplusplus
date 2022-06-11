/*
给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。
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

ListNode* deleteDuplicates(ListNode* head) {
    if(head==nullptr||head->next==nullptr){
        return head;
    }
    ListNode* left = head, * right = head->next, * preright = head;
    while(right){
        if(preright->val != right->val){
            left = left->next;
            left->val = right->val;
        }
        preright = preright->next;
        right = right->next;
    }
    left->next = nullptr;
    return head;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
