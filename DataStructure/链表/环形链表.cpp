/*
给你一个链表的头节点 head ，判断链表中是否有环。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。

如果链表中存在环 ，则返回 true 。 否则，返回 false 。
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

bool hasCycle(ListNode *head) {
    /*
    利用快慢指针
    */
    ListNode* demmy = new ListNode(-1);
    demmy->next = head;
    ListNode* p1 = demmy;
    ListNode* p2 = demmy;
    while(p1&&p1->next){
        p2 = p2->next;
        p1 = p1->next->next;
        if(p2==p1){
            return 1;
        }
    }
    return 0;    
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

    // p1->next = l1->next;

    cout<<hasCycle(l1->next)<<endl;

    return 0;
}
