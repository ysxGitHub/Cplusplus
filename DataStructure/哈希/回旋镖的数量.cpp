/*
给定平面上 n 对 互不相同 的点 points ，其中 points[i] = [xi, yi] 。回旋镖 是由点 (i, j, k) 
    表示的元组 ，其中 i 和 j 之间的距离和 i 和 k 之间的欧式距离相等（需要考虑元组的顺序）。

返回平面上所有回旋镖的数量。

*/
#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

int numberOfBoomerangs(vector<vector<int>>& points) {
    int n = points.size();
    if(n<=2){return 0;}
    int ans=0;
    for(int i=0; i<n; i++){
        unordered_map<int, int>cnt;
        for(int j=0; j<n; j++){
            if(i==j){continue; }
            cnt[pow(points[i][0]-points[j][0], 2) + pow(points[i][1]-points[j][1], 2)]++;
        }
        // 每一层遍历都统计 j 到 i 的距离，当有两个这样相等的距离就可以看作回旋镖
        for(auto&it: cnt){
            ans += (it.second*(it.second-1));
        }
    }
    // 并不能将其拿出，可能有的不能组成回旋镖
    // for(auto&it: cnt){
    //     // cout<<it.first<<", "<<it.second<<"; ";
    //     ans += (it.second*(it.second-1));
    // }
    return ans;
}