/*
单链表的倒数第 k 个节点
从前往后寻找单链表的第 k 个节点很简单，一个 for 循环遍历过去就找到了，
    但是如何寻找从后往前数的第 k 个节点呢？

那你可能说，假设链表有 n 个节点，倒数第 k 个节点就是正数第 n - k 个节点，
    不也是一个 for 循环的事儿吗？

是的，但是算法题一般只给你一个 ListNode 头结点代表一条单链表，
    你不能直接得出这条链表的长度 n，而需要先遍历一遍链表算出 n 的值，
    然后再遍历链表计算第 n - k 个节点。

也就是说，这个解法需要遍历两次链表才能得到出倒数第 k 个节点。

那么，我们能不能只遍历一次链表，就算出倒数第 k 个节点？可以做到的，
    如果是面试问到这道题，面试官肯定也是希望你给出只需遍历一次链表的解法。

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

ListNode* LastKNode(ListNode* list, int k){
    /*
    p1先走k个节点
    p2再走
    p1到达结尾是
    p2到达n-k
    */
    ListNode* p = list;
    ListNode* p2 = list;
    int i=0;
    while(p){

        if(i>k){
            p2 = p2->next;
        }
        p = p->next;
        i++;
    }
    return p2->next;
}


int main(int argc, char const *argv[])
{
    ListNode* l1 = new ListNode(1);

    vector<int>nums1 = {1,2};

    ListNode* p1 = l1;
    for(auto&n1: nums1){
        p1->next = new ListNode(n1);
        p1 = p1->next;
    }

    cout<<LastKNode(l1, 1)->val<<endl;

    return 0;
}
