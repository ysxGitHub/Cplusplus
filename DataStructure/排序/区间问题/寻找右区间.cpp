/*
给你一个区间数组 intervals ，其中 intervals[i] = [starti, endi] ，且每个 starti 都 不同 。

区间 i 的 右侧区间 可以记作区间 j ，并满足 startj >= endi ，且 startj 最小化 。

返回一个由每个区间 i 的 右侧区间 的最小起始位置组成的数组。如果某个区间 i 不存在对应的 右侧区间 ，则下标 i 处的值设为 -1 。
*/
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findRightInterval(vector<vector<int>>& intervals) {
    vector<pair<int, int>> startIntervals;
    int n = intervals.size();
    // 只需要记录 begin() 位置
    for (int i = 0; i < n; i++) {
        startIntervals.emplace_back(intervals[i][0], i);
    }
    sort(startIntervals.begin(), startIntervals.end());

    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        // 每次拿出 end() 位置 与 begin() 进行比较
        auto it = lower_bound(startIntervals.begin(), startIntervals.end(), make_pair(intervals[i][1], 0));
        if (it != startIntervals.end()) {
            ans[i] = it->second;
        }
    }
    return ans;
}
