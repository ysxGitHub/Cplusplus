/*
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
*/

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

struct cmp{
    bool operator()(const pair<int, int>&a, const pair<int, int>&b){
        return a.second<b.second;
    }
};
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int>cnt;
    for(auto&num : nums){
        cnt[num]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>pq;
    for(auto it=cnt.begin(); it!=cnt.end(); ++it){
        pq.push({it->first, it->second});
    }
    vector<int>ans;
    while(k--){
        ans.push_back(pq.top().first);
        pq.pop();
    }
    return ans;
}

