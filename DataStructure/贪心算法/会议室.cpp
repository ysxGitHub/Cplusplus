/*
给定一个会议时间安排的数组 intervals ，每个会议时间都会包括开始和结束的时间 
    intervals[i] = [starti, endi] ，请你判断一个人是否能够参加这里面的全部会议。

输入：intervals = [[0,30],[5,10],[15,20]]
输出：false

输入：intervals = [[7,10],[2,4]]
输出：true

0 <= intervals.length <= 10^4
intervals[i].length == 2
0 <= start_i < end_i <= 10^6

*/
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;


bool canAttendMeetings(vector<vector<int>>& intervals) {
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    if(n<=1) return true;
    for(int i=1; i<n; i++){
        if(intervals[i-1][0]==intervals[i][0]||intervals[i-1][1]>intervals[i][0]){
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> nums = {{7,10},{2,4}};
    cout<<canAttendMeetings(nums);
    return 0;
}
