/*
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

不允许修改 链表。

*/

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode * detectCycle(ListNode *head) {
    /*
    利用快慢指针
    */
    // ListNode* demmy = new ListNode(-1);
    // demmy->next = head;
    ListNode* p1 = head;
    ListNode* p2 = head;
    while(p1&&p1->next){
        p2 = p2->next;
        p1 = p1->next->next;
        if(p2==p1){break;}
    }
    if(p1==NULL||p1->next==NULL){
        return NULL;
    }
    p2 = head;
    while(p1!=p2){
        p1 = p1->next;
        p2 = p2->next;
    }
    return p2;
}

ListNode *detectCycle1(ListNode *head) {
    ListNode* p = head;
    unordered_set<ListNode*>seen;
    while(p){
        seen.insert(p);
        p = p->next;
        if(seen.find(p)!=seen.end()){
            return p;
        }
    }    
    return NULL;
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

    cout<<detectCycle(l1->next)<<endl;

    return 0;
}
