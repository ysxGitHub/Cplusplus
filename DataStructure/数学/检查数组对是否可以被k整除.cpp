/*
给你一个整数数组 arr 和一个整数 k ，其中数组长度是偶数，值为 n 。

现在需要把数组恰好分成 n / 2 对，以使每对数字的和都能够被 k 整除。

如果存在这样的分法，请返回 True ；否则，返回 False 。
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
对数组每个数求余,负数就得+k,然后统计每个余数的数量
从0到k-1,
    1的数量要和k-1的数量相同才能, 2和k-2等等
    0的数量要是2的倍数
*/
bool canArrange(vector<int>& arr, int k) {
    vector<int>cnt(k,0);
    for(const auto&a: arr){
        cnt[((a)%k+k)%k]++; //可能会有负数，因此要加上 k
    }
    if(cnt[0]%2) return 0;
    for(int i=1; i<k; ++i){
        if(cnt[i]!=cnt[k-i]) return 0;
    }
    return 1;
}

