/*
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

进阶：
    你可以设计一个只使用常数额外空间的算法来解决此问题吗？
    你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
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

// 反转整个链表相当于 head->null, 反转 a->b 也是同理, 注意这里 [a, b)
ListNode* reverseAtoB(ListNode* a, ListNode* b){
    ListNode* pre = nullptr;
    ListNode* cur = a;
    ListNode* next;
    while(cur != b){
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if(head==nullptr){return nullptr;}
    ListNode* a = head, * b = head;
    // base case 
    for(int i=0; i<k; i++){
        // 如果 b 为空 则怎么链表长度不足 k
        if(b==nullptr){
            return head;
        }
        b = b->next;
    }
    // 反转 a->b, 左闭右开
    ListNode* newhead = reverseAtoB(a, b);
    // 递归反转后续链表并连接起来, 相当于新尾部与新头连接 
    a->next = reverseKGroup(b, k);
    return newhead;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
