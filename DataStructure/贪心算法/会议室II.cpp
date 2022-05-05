/*
给你一个会议时间安排的数组 intervals ，每个会议时间都会包括开始和结束的时间 
    intervals[i] = [starti, endi] ，返回 所需会议室的最小数量 。

输入：intervals = [[0,30],[5,10],[15,20]]
输出：2

输入：intervals = [[7,10],[2,4]]
输出：1

1 <= intervals.length <= 10^4
0 <= start_i < end_i <= 10^6

*/
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int minMeetingRooms(vector<vector<int>>& intervals) {
    int n = intervals.size();
    if (n==1) return 1;
    vector<int> istart(n), iend(n);
    for(int i=0; i<n; i++){
        istart[i] = intervals[i][0];
        iend[i] = intervals[i][1];
    }
    sort(istart.begin(), istart.end());
    sort(iend.begin(), iend.end());
    
    int i=0, j=0;
    int cnt=0, ans=0;
    while (i<n && j<n){
        if(istart[i]<iend[j]){
            // 遇到一个会议, count++;
            cnt++;
            i++;
        }else{
            // 结束一个会议, count--;
            cnt--;
            j++;
        }
        // count 记录正在会议的次数
        ans = max(ans, cnt);
    }
    
}


// 差分思想
void Difference(vector<int>& diff, int l, int r, int v){
    diff[l] +=v;
    diff[r+1] -= v;
}

int minMeetingRooms1(vector<vector<int>>& intervals) {
    int n = intervals.size();
    int maxtime = -1, mintime = INT32_MAX;
    for(int i=0; i<n; i++){
        if(intervals[i][0]<mintime) mintime = intervals[i][0];
        if(intervals[i][1]>maxtime) maxtime = intervals[i][1];
    }
    vector<int>diff(maxtime-mintime+1);
    for(int i=0; i<n; i++){
        Difference(diff, intervals[i][0]-mintime, intervals[i][1]-mintime, 1);
    }
    for(int i=1; i<diff.size(); i++){
        diff[i] += diff[i-1];
    }
    return *max_element(diff.begin(), diff.end());
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> intervals = {{0,30},{5,10},{15,20}};

    return 0;
}
