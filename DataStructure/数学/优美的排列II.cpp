/*
给你两个整数 n 和 k ，请你构造一个答案列表 answer ，该列表应当包含从 1 到 n 的 n 个不同正整数，
    并同时满足下述条件：

假设该列表是 answer = [a1, a2, a3, ... , an] ，那么列表 [|a1 - a2|, |a2 - a3|,
    |a3 - a4|, ... , |an-1 - an|] 中应该有且仅有 k 个不同整数。
返回列表 answer 。如果存在多种答案，只需返回其中 任意一种 。
*/

#include <vector>
#include <iostream>
using namespace std;

vector<int> constructArray(int n, int k) {
    vector<int> ans(n);
    int lo = 1, hi = n;
    // 交替选前 k 个数
    for(int i=0; i<k; i++) {
        ans[i] = i%2==0 ? lo++ : hi--;
    }
    // 处理剩余的数(如果 k 是偶数，剩余的数要从 hi 开始递减，否则从 lo 开始递增)
    for(int i=k; i<n; i++) {
        ans[i] = k%2==0 ? hi-- : lo++;
    }
    return ans;
}
