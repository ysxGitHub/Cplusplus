/*
给你一个单链表，随机选择链表的一个节点，并返回相应的节点值。每个节点 被选中的概率一样 。

实现 Solution 类：

Solution(ListNode head) 使用整数数组初始化对象。
int getRandom() 从链表中随机选择一个节点并返回该节点的值。链表中所有节点被选中的概率相等。
*/

/*
水塘采样
具体例子#
我们先从具体案例中理解水塘抽样算法的实现,再从抽象的角度来理解.

假如 10000 个数,我们要抽取十个随机数.

一万个数的样本集合数组记作 S.

十个随机数的数组记作 R,代表 result.

先取数组S中前十个数填充进数组 R.

算法的第一次迭代流程是这样的:

从第十一个数 (下标为10) 开始迭代,生成一个 0 到 10 的随机整数 j ,如果 j<10 (假如 j=4 ),
    我们就将数组 R 中的第5项(R[4])替换成 S 数组中的第 11 项 (S[10]).
遍历完成生成的 R 数组,就是我们要求的随机数组.

    vector<int> S(10000);
    int N = S.size();
    //生成一万个数的数组
    for (int r = 0;r < N; r ++){
        S[r] = rand() % 10001;
    }

    int k = 10;
    vector<int> R(k);
    //S前K个数填充R数组
    for (int f = 0;f < k; f++){
        R[f] = S[f];
    }
    int j ;
    //遍历数组S,根据算法,替换R数组中的元素,最终生成结果R数组.
    for (int i = k;i < S.size();i++){
        j = rand() % (i+1);
        if (j < k)  R[j] = S[i];
    }
    //打印R数组的结果
    for (int i =0;i < R.size();i++) {
        cout<<R[i]<<", ";
    }
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


class Solution {
public:
    ListNode* head;
    Solution(ListNode* head) {
        this->head = head;
    }

    int getRandom() {
        int res = -1, i=0;
        ListNode* p = head;
        while(p){
            i++;
            // 生成一个 [0, i) 之间的整数
            // 这个整数等于 0 的概率就是 1/i
            if(rand()%i == 0) res = p->val;
            p = p->next;
        }
        return res;
    }
    vector<int> getRandom(int k) {
        ListNode* p = head;
        vector<int>res(k);
        // 前 k 个元素先默认选上
        for(int i=0; i<k&&p; i++){
            res[i] = p->val;
            p = p->next;
        }
        int j = k;
        while(p){
            j++;
            // 生成一个 [0, j) 之间的整数, 这个整数小于 k 的概率就是 k/j
            if(rand()%j < k) res.push_back(p->val);
            p = p->next;
        }
        return res;
    }

};