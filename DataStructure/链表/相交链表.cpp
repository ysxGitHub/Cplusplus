/*
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。
如果两个链表不存在相交节点，返回 null 。
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

// 两个链表交叉查询
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *pa = headA;
    ListNode *pb = headB;

    while (pa!=pb){
        if(pa==NULL){
            pa = headB;
        }else{
            pa = pa->next;
        }
        if(pb==NULL){
            pb = headA;
        }else{
            pb = pb->next;
        }
    }
    return pa;
}


// 两个链表先统计长度，长链表先走x步
int count_list_len(ListNode* head){
    int count=0;
    ListNode* p = head;
    while (p){
        count++;
        p=p->next;
    } 
    return count;
}

ListNode* relocate_start_node(ListNode* longhead, int dist){
    ListNode* p = longhead;
    while (dist){
        p=p->next;        
        dist--;
    }
    return p;
}

ListNode* CrossPoint(ListNode* head1, ListNode* head2){
    ListNode* longhead = head1;
    ListNode* shorthead = head2;
    int p1len = count_list_len(head1);
    int p2len = count_list_len(head2);
    if(p2len>p1len){
        longhead = head2;
        shorthead = head1;
    }
    int dist = abs(p1len-p2len);
    longhead = relocate_start_node(longhead, dist);

    while (shorthead){
        if(shorthead==longhead){
            return shorthead;
        }
        shorthead = shorthead->next;
        longhead = longhead->next;
    }
    return NULL;    
    
}



int main(int argc, char const *argv[])
{
    ListNode* head1 = new ListNode(0);

    ListNode* p1 = head1;
    for(int i=1; i<4; i++){
        ListNode* node = new ListNode(i);
        p1->next = node;
        p1 = p1->next;
    }

    ListNode* head2 = new ListNode(0);

    ListNode* p2 = head2;
    for(int i=1; i<2; i++){
        ListNode* node = new ListNode(i);
        p2->next = node;
        p2 = p2->next;
    }

    for(int i=0; i<2; i++){
        ListNode* same_node = new ListNode(i+10);
        p1->next = same_node;
        p1 = p1->next;        
        p2->next = same_node;
        p2 = p2->next;
    }

    cout<<getIntersectionNode(head1->next, head2->next)->val<<endl;

    return 0;
}
