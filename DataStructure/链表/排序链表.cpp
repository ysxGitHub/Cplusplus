/*
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
进阶：你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
*/
#include<queue>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct cmp{
    bool operator()(ListNode* a, ListNode* b)const{
        return a->val>b->val;
    }
};

ListNode* sortList(ListNode* head) {
    ListNode* tmp = head;
    priority_queue<ListNode*,vector<ListNode*>, cmp> cnt;
    while(tmp){
        cnt.push(tmp);
        tmp = tmp->next;
    }
    head = new ListNode(-1);
    tmp = head;
    while(!cnt.empty()){
        auto it = cnt.top();
        cnt.pop();
        it->next = nullptr;
        tmp->next = it;
        tmp = tmp->next;
    }
    return head->next;
}

ListNode* sortList(ListNode* head) {
    if (head == nullptr) {
        return head;
    }
    int length = 0;
    ListNode* node = head;
    // 统计链表的长度
    while (node != nullptr) {
        length++;
        node = node->next;
    }
    ListNode* dummyHead = new ListNode(0, head);
    for (int subLength = 1; subLength < length; subLength <<= 1) {
        ListNode* prev = dummyHead, *curr = dummyHead->next;
        while (curr != nullptr) { // 当前节点不为空
            ListNode* head1 = curr;
            // 拆分子链1，最后 cur 不能为空
            for (int i = 1; i < subLength && curr->next != nullptr; i++) {
                curr = curr->next;
            }
            ListNode* head2 = curr->next;
            // 断开连接
            curr->next = nullptr;
            curr = head2;
            // 拆分子链2，注意现在 cur 实为 cur->next 所以要判断 现在的 cur 是否为空
            for (int i = 1; i < subLength && curr != nullptr && curr->next != nullptr; i++) {
                curr = curr->next;
            }
            ListNode* next = nullptr;
            if (curr != nullptr) {
                next = curr->next;
                // 断开连接
                curr->next = nullptr;
            }
            // 合并链表
            ListNode* merged = merge(head1, head2);
            prev->next = merged;
            while (prev->next != nullptr) {
                prev = prev->next;
            }
            // cur 指向下一个位置
            curr = next;
        }
    }
    return dummyHead->next;
}

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

