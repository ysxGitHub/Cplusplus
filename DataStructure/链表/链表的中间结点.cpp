/*
给定一个头结点为 head 的非空单链表，返回链表的中间结点。
如果有两个中间结点，则返回第二个中间结点。

注：
    给定链表的结点数介于 1 和 100 之间。
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

ListNode* middleNode(ListNode* head) {
    /*
    利用快慢指针
    */
    ListNode* demmy = new ListNode(-1);
    demmy->next = head;
    ListNode* p1 = demmy;
    ListNode* p2 = demmy;
    while(p1){
        p2 = p2->next;
        if(p1->next==NULL){
            break;
        }
        p1 = p1->next->next;
    }
    return p2;
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

    p1 = middleNode(l1->next);

    while(p1){
        cout<<p1->val<<endl;
        p1 = p1->next;
    }


    return 0;
}
