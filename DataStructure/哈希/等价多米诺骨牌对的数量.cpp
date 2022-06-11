/*
给你一个由一些多米诺骨牌组成的列表 dominoes。

如果其中某一张多米诺骨牌可以通过旋转 0 度或 180 度得到另一张多米诺骨牌，我们就认为这两张牌是等价的。

形式上，dominoes[i] = [a, b] 和 dominoes[j] = [c, d] 等价的前提是 a==c 且 b==d，或是 a==d 且 b==c。

在 0 <= i < j < dominoes.length 的前提下，找出满足 dominoes[i] 和 dominoes[j] 等价的骨牌对 (i, j) 的数量。
*/
#include <unordered_map>
#include <vector>
using namespace std;

// 法1：hash
using PII = pair<int, int>;
struct myHash{
    size_t operator()(const PII&num) const noexcept{
        return std::hash<int>()(num.first)^std::hash<int>()(num.second);
    }
};
struct MyEqual{
    bool operator()(const PII&a, const PII&b) const{
        if(a.first==b.first&&a.second==b.second||a.first==b.second&&a.second==b.first) return 1;
        return 0;
    }
};
int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    unordered_map<pair<int, int>, int, myHash, MyEqual>cnt;
    for(const auto&dom: dominoes){
        cnt[{dom[0], dom[1]}]++;
    }
    int ans = 0;
    for(const auto&[a, b]: cnt){
        if(b!=1){
            ans+=b*(b-1)/2;
        }
    }
    return ans;
}

// 法2：
int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    vector<int> num(100);
    int ret = 0;
    for (auto& it : dominoes) {
        // 让每一个二元对都变为指定的格式，即第一维必须不大于第二维。这样两个二元对「等价」当且仅当两个二元对完全相同。
        int val = it[0] < it[1] ? it[0] * 10 + it[1] : it[1] * 10 + it[0];
        ret += num[val];
        num[val]++;
    }
    return ret;
}
