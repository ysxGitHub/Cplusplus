/*
给定整数 n 和 k，返回  [1, n] 中字典序第 k 小的数字。
*/

/*
思路：
    可以看作 10 叉树
    第一步 要先统计 区间 中的节点数 例如 1~2, 2~3, ...
    第二步 该区间的节点数 要与 k 比较 大小, 
        如果大于则进入该区间的子树, 否则继续 第一步
    直到找到等于 k 个数的节点数的位置
*/ 
#include<iostream>

using namespace std;

int getPrefixCount(int prefix, int n){
    // 当前前缀 与 下一个前缀  如 1, 2  注意 int 会溢出
    long curpre = prefix, nextpre = prefix + 1;
    // 记录两个前缀之间的节点数 如 1~2
    int cnt = 0;
    // 当前的前缀肯定要小于最大数值
    while(curpre<=n){
        // nextpre 的上界也是 n , +1 因为需要算上 1 
        cnt += min((long)n+1, nextpre) - curpre;
        curpre *= 10;
        nextpre *= 10;
    }
    return cnt;
} 


int findKthNumber(int n, int k) {
    // 前缀
    int prefix = 1;
    // 指针 记录现在的位置 p==k时, prefix 就是答案
    int p = 1;
    while(p<k){
        // 得到当前 前缀区间的节点数
        int precnt = getPrefixCount(prefix, n);
        // 当前 前缀区间的节点数 大于 k 时, 进入子节点寻找
        if(precnt + p > k){
            prefix *=10;
            p++;
        }else{ // 当前 前缀区间的节点数 小于 k 时, 进入下一个前缀区间
            prefix++;
            p += precnt;
        }
    }
    return prefix;
}

int main(int argc, char const *argv[])
{
    cout<<findKthNumber(10, 2);
    return 0;
}
