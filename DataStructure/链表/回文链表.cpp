/*
给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。
    如果是，返回 true ；否则，返回 false 。
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

bool isPalindrome1(ListNode* head) {
    vector<int>nums;
    while(head){
        nums.emplace_back(head->val);
        head=head->next;
    }
    int i=0, j=nums.size()-1;
    while(i<j){
        if(nums[i]!=nums[j]){
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

// 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
ListNode* findHalfList(ListNode* head){
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast->next&&fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
ListNode* reverseList(ListNode* head){
    ListNode* pre = nullptr;
    ListNode* cur = head;
    ListNode* next;
    while(cur){
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}
bool isPalindrome(ListNode* head) {
    if(head->next==nullptr){
        return 1;
    }
    ListNode* halfhead = findHalfList(head);
    ListNode* reversehead = reverseList(halfhead->next);
    ListNode* p = head;
    ListNode* rp = reversehead;
    while(rp){
        if(rp->val!=p->val){
            return 0;
        }
        rp = rp->next;
        p = p->next;
    }
    reversehead = reverseList(reversehead);
    halfhead->next = reversehead;
    return 1;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
