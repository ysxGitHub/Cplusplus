/*
给你一个链表数组，每个链表都已经按升序排列。
请你将所有链表合并到一个升序链表中，返回合并后的链表。

优先队列 pq 中的元素个数最多是 k，所以一次 poll 或者 add 方法的时间复杂度是 O(logk)；
所有的链表节点都会被加入和弹出 pq，所以算法整体的时间复杂度是 O(Nlogk)，
其中 k 是链表的条数，N 是这些链表的节点总数。
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class cmp{
public:
    bool operator()(ListNode* a, ListNode* b){
        // 1<2<3 else 3>2>1
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size()==0){
        return nullptr;
    }
    ListNode* head = new ListNode(-1);
    ListNode* p = head;

    // 最小堆
    priority_queue<ListNode*, vector<ListNode*>, cmp>mlist;
    
    for(auto& ls: lists){
        if(ls!=NULL){
            mlist.push(ls);
        }
    }
    while(!mlist.empty()){
        ListNode* tmp = mlist.top();
        mlist.pop();
        p->next = tmp;
        if(tmp->next!=NULL){
            mlist.push(tmp->next);
        }
        p = p->next;
    }
    return head->next;
}

int main(int argc, char const *argv[])
{
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);

    vector<int>nums1 = {1,5,8};
    vector<int>nums2 = {2,3,5,10};
    vector<int>nums3 = {4,6,7,9,11};

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

    ListNode* p3 = l3;
    for(auto&n3: nums3){
        p3->next = new ListNode(n3);
        p3 = p3->next;
    }

    vector<ListNode*>vl;
    vl.push_back(l1->next);
    vl.push_back(l2->next);
    vl.push_back(l3->next);

    ListNode* p = mergeKLists(vl);
    while(p){
        cout<<p->val<<"  ";
        p = p->next;
    }


    // priority_queue<ListNode*, vector<ListNode*>, cmp>sss;
    // sss.push(l1);
    // sss.push(l2);
    // sss.push(l3);
    // cout<<sss.top()->val<<endl;


    return 0;
}
