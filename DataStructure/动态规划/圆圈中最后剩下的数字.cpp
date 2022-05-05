/*
0,1,···,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字（删除后从下一个数字开始计数）。求出这个圆圈里剩下的最后一个数字。

例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。
*/

//类似 1823 找出游戏的获胜者
#include <iostream>
#include <list>
using namespace std;


// 方法1：
struct node//链表节点
{
    int val;
    node(int value) {
        val = value;
    }
    node* next;
};

int lastRemaining(int n, int m) {
    if(m==1) return n-1;//一次一个直接返回最后一个即可

    node* head = new node(0);
    node* team = head;//创建一个链表
    for(int i=1;i<n;i++) {
        team->next=new node(i);
        team=team->next;
    }
    team->next=head;//使形成环
    int index=0;//从0开始计数
    while (head->next!=head) {//当剩余节点不止一个的时候
        //如果index=m-2 那就说明下个节点(m-1)该删除了
        if(index==m-2) {
            head->next=head->next->next;
            index=0;
        }
        else {
            index++;
        }
        head=head->next;
    }
    return head->val;
}

// 方法2
int lastRemaining(int n, int m) {
    if(m==1) return n-1;
    list<int>l;
    for(int i=0; i<n; i++) {
        l.push_back(i);
    }
    int index=0;
    while (l.size()>1) {
        index=(index+m-1)%(l.size());
        auto it = l.begin();
        for(int i = 0; i < index; i++) it++;
        l.erase(it);
    }
    return l.front();
}



// 方法3
/*
动态规划解析：
状态定义： 设「i,m 问题」的解为 dp[i] ；
转移方程： 通过以下公式可从 dp[i - 1] 递推得到 dp[i] ；
dp[i] = (dp[i - 1] + m) % i

初始状态：「1,m 问题」的解恒为 0 ，即 dp[1] = 0；
返回值： 返回「n,m 问题」的解 dp[n]；


//  n-1约瑟夫环的索引index(n-1)        删除一个数后的n约瑟夫环索引index(n)
//                0           --->                     m%n
//                1           --->                     (m+1)%n
//                2           --->                     (m+2)%n
//               ...                                  ...
//                n-2         --->                     (m+n-2)%n
//  由以上得出递推式：index(n-1)  --->      index(n) = (m+index(n-1))%n
// 也就是说，现在的环索引为0的对应原来的索引为3的，换句话说，旧环的索引3跑到新环的索引0位置上了。
*/
int lastRemaining(int n, int m) {
    int x = 0;
    for(int i=2; i<=n; i++){
        x = (x+m)%i;
    }
    return x;
}

int main(int argc, char const *argv[])
{
    cout<<lastRemaining(10, 2)<<endl;
    return 0;
}

