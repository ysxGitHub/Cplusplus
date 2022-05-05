/*
将两个升序链表合并为一个新的 升序 链表并返回。
    新链表是通过拼接给定的两个链表的所有节点组成的。 
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

代码中还用到一个链表的算法题中是很常见的「虚拟头结点」技巧，也就是 dummy(head) 节点。
你可以试试，如果不使用 dummy 虚拟节点，代码会复杂很多，
而有了 dummy 节点这个占位符，可以避免处理空指针的情况，降低代码的复杂性。
*/

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* head = new ListNode(0);
    ListNode* p = head;

    ListNode* p1 = list1;
    ListNode* p2 = list2;

    while(p1||p2){
        // p->next = new ListNode(0);

        if(p1==NULL&&p2!=NULL){
            p->next = p2;
            p2 = p2->next;
        }
        else if(p2==NULL&&p1!=NULL){
            p->next = p1;
            p1 = p1->next;
        } 
        else if(p1!=NULL&&p2!=NULL){
            if(p1->val<=p2->val){
                p->next = p1;
                p1 = p1->next;
            }else{
                p->next = p2;
                p2 = p2->next;
            }
        }
        else{
            break;
        }

        p = p->next;
    }

    return head->next;
}


int main(int argc, char const *argv[])
{
    ListNode* l1 = new ListNode;
    ListNode* l2 = new ListNode;

    vector<int>nums1 = {3,4,7};
    vector<int>nums2 = {2,3,5,10};

    ListNode* p1 = l1;
    for(auto&n1: nums1){
        p1->next = new ListNode(n1);
        p1 = p1->next;
    }

    ListNode* p2 = l2;
    for(auto&n2: nums2){
        p2->next = new ListNode(n2);
        p2 = p2->next;
    }

    ListNode* p = mergeTwoLists(l1->next, l2->next);
    while(p){
        cout<<p->val<<"  ";
        p = p->next;
    }
    
    return 0;
}

