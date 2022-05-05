/*
假设有从 1 到 n 的 n 个整数。用这些整数构造一个数组 perm（下标从 1 开始），
    只要满足下述条件 之一 ，该数组就是一个 优美的排列 ：
        perm[i] 能够被 i 整除
        i 能够被 perm[i] 整除
给你一个整数 n ，返回可以构造的 优美排列 的 数量 。
*/

#include<iostream>
#include<vector>
using namespace std;

int backtrace(vector<bool>&seen, int n, int i){
    if(i>n) return 1;
    int cnt = 0;
    for(int num=1; num<=n; num++){
        if(seen[num]||(num%i&&i%num)) continue;
        seen[num] = 1;
        cnt += backtrace(seen, n, i+1);
        seen[num] = 0;
    }
    return cnt;
}

int countArrangement(int n) {
    vector<bool> seen;
    return backtrace(seen, n, 1);
}



int main(int argc, char const *argv[])
{

    return 0;
}
