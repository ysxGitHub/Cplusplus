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

ListNode* reverseList1(ListNode* head) {
    if(head==NULL||head->next==NULL){
        return head;
    }

    ListNode* last = reverseList1(head->next);
    head->next->next = head;
    head->next = nullptr;
    return last;
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
    return last;
}


int main(int argc, char const *argv[])
{
    ListNode* l1 = new ListNode(1);

    vector<int>nums1 = {1,2,3,4,5,6,7};

    ListNode* p1 = l1;
    for(auto&n1: nums1){
        p1->next = new ListNode(n1);
        p1 = p1->next;
    }

    p1 = reverseList1(l1->next);

    while(p1){

        cout<<p1->val<<"  ";
        p1 = p1->next;
    }


    return 0;
}
