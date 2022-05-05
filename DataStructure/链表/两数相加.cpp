/*
给你两个非空的链表，表示两个非负的整数。它们每位数字都是按照逆序的方式存储的，
    并且每个节点只能存储一位数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

eg: 
l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]

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

void sumtwo(int &flag, int &sum, ListNode *p){
    if(flag==1){
        sum+=1;
    }
    if(sum>=10){
        p->val = sum%10;
        flag==1;
    }else{
        p->val = sum;
        flag = 0;
    }
}


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode*p1 = l1;
    ListNode*p2 = l2;
    ListNode*result = new ListNode(0);
    ListNode*p = result;

    int flag = 0;
    while (p1&&p2){
        int sumt = p1->val+p2->val ;
        if(flag==1){
            sumt+=1;
        }
        if(sumt>=10){
            p->val = sumt%10;
            flag = 1;
        }
        else{
            p->val = sumt;
            flag = 0;
        }
        p1 = p1->next;
        p2 = p2->next;

        p->next = new ListNode(0);
        p = p->next;
    }
    while(p1!=NULL){
        int sum1 = p1->val;
        if(flag==1){
            sum1+=1;
        }
        if(sum1>=10){
            p->val = sum1%10;
            flag==1;
        }else{
            p->val = sum1;
            flag = 0;
        }
        p1 = p1->next;

        p->next = new ListNode(0);
        p = p->next;
    }

    while(p2!=NULL){
        int sum2 = p2->val;
        if(flag==1){
            sum2+=1;
        }
        if(sum2>=10){
            p->val = sum2%10;
            flag==1;
        }else{
            p->val = sum2;
            flag = 0;
        }
        p2 = p2->next;

        p->next = new ListNode(0);
        p = p->next;
    }

    if(flag==1){
        p->val = 1;
    }else{
        p = result;
        while(p->next->next){
            p = p->next;
        }
        p->next = NULL;
    }
    
    return result;
}

ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
    ListNode*p1 = l1;
    ListNode*p2 = l2;
    ListNode*result = new ListNode(0);
    ListNode*p = result;
    int flag = 0;
    while(p1!=NULL||p2!=NULL){
        int val1 = p1==NULL ? 0 : p1->val;
        int val2 = p2==NULL ? 0 : p2->val;
        int sumall = val1 + val2 + flag;

        flag = sumall/10;
        p->next = new ListNode(sumall%10);
        p = p->next;

        if(p1!=NULL){
            p1 = p1->next;
        }
        if(p2!=NULL){
            p2 = p2->next;
        }

    }
    if(flag==1){
        p->next = new ListNode(1);
    }
    return result->next;
}


int main(int argc, char const *argv[])
{
    vector<int>num1={9,9,9,9,9,9};
    ListNode* head1 = new ListNode(9);
    ListNode* p1 = head1;
    for(int i=0; i<num1.size(); i++){
        ListNode* tmp = new ListNode(num1[i]);
        p1->next = tmp;
        p1 = p1->next;
    }

    vector<int>num2={9,9,9};
    ListNode* head2 = new ListNode(9);
    ListNode* p2 = head2;
    for(int i=0; i<num2.size(); i++){
        ListNode* tmp = new ListNode(num2[i]);
        p2->next = tmp;
        p2 = p2->next;
    }


    // while (head1) {
    //     cout<<head1->val<<"  ";
    //     head1=head1->next;
    // }

    ListNode* p = addTwoNumbers1(head1, head2);
    while(p){
        cout<<p->val<<"  ";
        p = p->next;
    }

    return 0;
}


