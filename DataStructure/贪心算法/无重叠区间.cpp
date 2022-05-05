/*
给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。
    返回 需要移除区间的最小数量，使剩余区间互不重叠 。
*/

#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int n = intervals.size();
    if(n<=1) return 0;

    // 按 end 升序排序
    sort(intervals.begin(), intervals.end(), [](vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    });
    // 至少存在1个区间不重叠
    int cnt=1;
    // 排序后，第一个区间的尾部
    int x_end = intervals[0][1];
    for(auto x: intervals){
        int x_start = x[0];
        // 当一个区间的头部 大于 另一个区间的尾部，则这两个区间不重叠，则不重叠区间 ++
        if(x_start>=x_end){
            cnt++;
            x_end = x[1];
        }
    }

}


// dp 超时
int eraseOverlapIntervals1(vector<vector<int>>& intervals) {
    int n = intervals.size();
    if(n<=1) return 0;

    // 按 start 升序排序
    sort(intervals.begin(), intervals.end(), [](vector<int>&a, vector<int>&b){
        return a[0]<b[0];
    });    

    vector<int>dp(n, 1);
    for(int i=1; i<n; i++){
        for(int j=i-1; j>=0; j--){
            // 现在的区间与原来的区间不重叠时
            if(intervals[i][0]>=intervals[j][1]){
                dp[i] = max(dp[i], dp[j]+1);
            }

        }

    }
    return n - *max_element(dp.begin(), dp.end());
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
