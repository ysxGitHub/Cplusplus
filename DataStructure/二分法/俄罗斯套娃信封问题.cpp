/*
给你一个二维整数数组 envelopes ，其中 envelopes[i] = [wi, hi] ，表示第 i 个信封的宽度和高度。

当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

请计算 最多能有多少个 信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

注意：不允许旋转信封。
*/
#include <iostream>
#include <algorithom>
#include <vector>
using namespace std;

// 面试题 17.08. 马戏团人塔

// dp超时
int maxEnvelopes1(vector<vector<int>>& envelopes) {
    if (envelopes.empty()) {
        return 0;
    }

    int n = envelopes.size();
    sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2) {
        return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
    });

    vector<int> f(n, 1);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (envelopes[j][1] < envelopes[i][1]) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    return *max_element(f.begin(), f.end());
}

int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2) {
        return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]));

    int n = envelopes.size();
    vector<int>pokerHeap(n, 0);
    int piles = 0, poker = 0;
    int left, right, mid;
    for(int i=0; i<n; i++){
        poker = envelopes[i][1];
        right = piles, left=0;
        while(left<right){
            mid = (left+right)/2;
            if(pokerHeap[mid] >= poker){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        if(left==piles){
            piles++;
        }
        pokerHeap[left] = poker;
    }
    return piles;
}

