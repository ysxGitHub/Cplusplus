/*
给定一个单词列表 words 和一个整数 k ，返回前 k 个出现次数最多的单词。

返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率， 按字典顺序 排序。
*/
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

using psi = pair<int, string>;
struct cmp{
    bool operator()(const psi &a, const psi &b){
        return a.first==b.first?a.second>b.second:a.first<b.first;
    }
};
vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int>cnt;

    // auto cmp = [](const psi& a, const psi& b) {
    //         return a.first==b.first?a.second>b.second:a.first<b.first;
    //     };

    // priority_queue<psi, vector<psi>, decltype(cmp)>pq(cmp);

    priority_queue<psi, vector<psi>, cmp>pq;

    for(const auto&word: words){
        cnt[word]++;
    }
    for(const auto&[k, v]: cnt){
        pq.emplace(v, k);
    }
    vector<string>ans;
    for(int i=0; i<k; ++i){
        ans.emplace_back(pq.top().second);
        pq.pop();
    }
    return ans;
}

