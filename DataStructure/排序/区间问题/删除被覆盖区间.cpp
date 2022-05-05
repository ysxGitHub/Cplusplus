/*
给你一个区间列表，请你删除列表中被其他区间所覆盖的区间。

只有当 c <= a 且 b <= d 时，我们才认为区间 [a,b) 被区间 [c,d) 覆盖。

在完成所有删除操作后，请你返回列表中剩余区间的数目。
*/
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

int removeCoveredIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](vector<int>&a, vector<int>&b){
        return a[0]==b[0]?a[1]>b[1]:a[0]<b[0];
    });
    int left = intervals[0][0];
    int right = intervals[0][1];
    int n = intervals.size();
    int ans = n;
    for(int i=1; i<n; i++){
        int tl = intervals[i][0], tr = intervals[i][1];
        // cout<<left<<", "<<right<<"; ";
        if(left<=tl && tr<=right) ans--;
        if((left<=tl && tr>right) || tl>=right) {
            left = tl;
            right = tr;
        }
    }
    return ans;
}