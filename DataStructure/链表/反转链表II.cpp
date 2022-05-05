/*
给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。
    请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。

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


ListNode* reverseBetween1(ListNode* head, int left, int right) {
    ListNode*demmy = new ListNode(-1);
    demmy->next = head;
    ListNode* p = demmy;
    int i = 1;
    while(i<left){
        p = p->next;
        i++;
    }
    ListNode* tmp = p;
    ListNode* pre = nullptr;
    ListNode* cur = p->next;
    ListNode* next = cur->next;
    while(i<right){
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
        i++;
    }
    tmp->next->next = cur->next;
    if(pre!=nullptr){
        cur->next = pre;
    }
    tmp->next = cur;
    return demmy->next;
}

ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* demmy = new ListNode(-1);
    demmy->next = head;
    ListNode* p = demmy;

    int i=1;
    while(i<left){
        i++;
        p = p->next;
    }
    ListNode* cur = p->next;
    ListNode* next;
    for(i=left; i<right; i++){
        next = cur->next;
        cur->next = next->next;
        next->next = p->next;
        p->next = next;
    }
    return demmy->next;
}



// 反转链表前 N 个节点
ListNode* successor = nullptr; // 后驱节点
// 反转以 head 为起点的 n 个节点，返回新的头结点
ListNode* reverseN(ListNode* head, int n) {
    if (n == 1) {
        // 记录第 n + 1 个节点
        successor = head->next;
        return head;
    }
    // 以 head.next 为起点，需要反转前 n - 1 个节点
    ListNode* last = reverseN(head->next, n - 1);

    head->next->next = head;
    // 让反转之后的 head 节点和后面的节点连起来
    head->next = successor;
    // 返回第 n 个节点
    return last;
}
// 递归
ListNode* reverseBetween2(ListNode* head, int m, int n) {
    // base case
    if (m == 1) {
        return reverseN(head, n);
    }
    // 前进到反转的起点触发 base case
    head->next = reverseBetween2(head->next, m - 1, n - 1);
    return head;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
