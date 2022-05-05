/*
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
    请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
*/
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>>ans;
    int n = intervals.size();
    sort(intervals.begin(), intervals.end(), [](vector<int>&a, vector<int>&b){
        return a[0]==b[0]?a[1]>b[1]:a[0]<b[0];
    });
    vector<int>res = intervals[0];
    for(int i=1; i<n; i++){
        vector<int> tmp = intervals[i];
        if(tmp[0]<=res[1]){
            res[1] = res[1]>tmp[1]?res[1]:tmp[1];
        }else{
            ans.emplace_back(res);
            res = tmp; 
        }
    }
    ans.emplace_back(res);
    return ans;
}


