/*
给定两个大小相等的数组 A 和 B，A 相对于 B 的优势可以用满足 A[i] > B[i] 的索引 i 的数目来描述。

返回 A 的任意排列，使其相对于 B 的优势最大化。

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct comp{
    bool operator()(pair<int, int>&a,pair<int, int>&b){
        return a.second < b.second;
    }
};

vector<int> advantageCount1(vector<int>& nums1, vector<int>& nums2) {
    int len = nums1.size()-1;

    vector<pair<int, int>> ans(len+1);
    vector<pair<int, int>> nums2plus;
    sort(nums1.begin(), nums1.end());

    for(int i=0; i<=len; i++){
        nums2plus.emplace_back(nums2[i], i);
    }
    sort(nums2plus.begin(), nums2plus.end());

    int i = 0;
    int m = len, n = len;
    while(0<=n){
        // cout<<"("<<nums1[m]<<","<<nums2plus[n].first<<")";
        if(nums1[m]<=nums2plus[n].first){
            ans[n] = make_pair(nums1[i], nums2plus[n].second);
            ++i;
        }else{
            ans[n] = make_pair(nums1[m], nums2plus[n].second); 
            --m;
        }
        --n;
    }
    sort(ans.begin(), ans.end(), comp());

    vector<int>res;
    for(auto&np: ans){
        res.emplace_back(np.first);
    }
    return res;
}

// 使用优先队列
vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
    int len = nums1.size();
    vector<int> ans(len);
    sort(nums1.begin(), nums1.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> maxpq;
    for(int i=0; i<len; i++){
        maxpq.emplace(i, nums2[i]);
    }
    int left = 0, right = len - 1; 
    while(!maxpq.empty()){
        auto& tmp = maxpq.top();
        if(nums1[right] > tmp.second){
            ans[tmp.first] = nums1[right--]; 
        }else{
            ans[tmp.first] = nums1[left++];
        }
        maxpq.pop();
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
