/*
给定一个奇数位升序，偶数位降序的链表，将其重新排序。

输入: 1->8->3->6->5->4->7->2->NULL
输出: 1->2->3->4->5->6->7->8->NULL

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

/*
思路：
    1. 按奇偶位置拆分链表，得1->3->5->7->NULL和8->6->4->2->NULL
    2. 反转偶链表，得1->3->5->7->NULL和2->4->6->8->NULL
    3. 合并两个有序链表，得1->2->3->4->5->6->7->8->NULL
*/

ListNode* merge(ListNode* head1, ListNode* head2) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
    while (temp1 != nullptr && temp2 != nullptr) {
        if (temp1->val <= temp2->val) {
            temp->next = temp1;
            temp1 = temp1->next;
        } else {
            temp->next = temp2;
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    if (temp1 != nullptr) {
        temp->next = temp1;
    } else if (temp2 != nullptr) {
        temp->next = temp2;
    }
    return dummyHead->next;
}

ListNode* reverseList(ListNode* head) {
    if(head==NULL||head->next==NULL){
        return head;
    }

    ListNode* pre = nullptr;
    ListNode* cur = head;
    ListNode* next = NULL;
    while(cur){
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

pair<ListNode*, ListNode*> partition(ListNode* head){
    ListNode* evenHead = head->next;
    ListNode* odd, *even = head, evenHead;

    while(even&&even->next){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = nullptr;
    return {head, evenHead};
}

ListNode* sortOddEvenList(ListNode* head){
    if (head==nullptr||head->next==nullptr) return head;
    auto twoHead = partition(head);
    ListNode* evenList = reverseList(twoHead.second);
    return merge(twoHead.first, evenList);
}

