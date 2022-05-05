/*
你将会获得一系列视频片段，这些片段来自于一项持续时长为 time 秒的体育赛事。这些片段可能有所重叠，
    也可能长度不一。

使用数组 clips 描述所有的视频片段，其中 clips[i] = [starti, endi] 表示：
    某个视频片段开始于 starti 并于 endi 结束。

甚至可以对这些片段自由地再剪辑：

例如，片段 [0, 7] 可以剪切成 [0, 1] + [1, 3] + [3, 7] 三部分。
我们需要将这些片段进行再剪辑，并将剪辑后的内容拼接成覆盖整个运动过程的片段（[0, time]）。
    返回所需片段的最小数目，如果无法完成该任务，则返回 -1 。
*/
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int videoStitching(vector<vector<int>>& clips, int time) {
    int n = clips.size();
    sort(clips.begin(), clips.end(), [](vector<int>&a, vector<int>&b){
        return a[1]==b[1] ? a[0]<b[0] : a[1]>b[1];
    });

    int ctime = time, i = 0, cnt = 0;
    while(time!=0){
        // 当短片段结尾的位置大于等于长片段当前最后的时间
        if(i<n && clips[i][1]>=time){
            // 保留短片段开始的位置
            ctime = min(clips[i][0], ctime);
            i++;
        }else{
            // 短片段结尾的位置 都小于 长片段当前最后的时间
            if(ctime<time){
                // 更新 time = 短片段开始的位置
                time = ctime;
                // 并且 短片段 需要数加一
                cnt++;
            }else{
                return -1;
            }
        }
    }
    return cnt;
}

// dp  令 dp[i] 表示将区间 [0,i) 覆盖所需的最少子区间的数量
/*
首先枚举 ii，同时对于任意一个子区间 [a_j,b_j) 若其满足 a_j < i ≤ b_j，
    那么它就可以覆盖区间 [0, i) 的后半部分，而前半部分则可以用 dp[a_j] 
    对应的最优方法进行覆盖，因此我们可以用 dp[a_j] + 1 来更新 dp[i]。
*/
int videoStitching1(vector<vector<int>>& clips, int time) {
    vector<int>dp(time+1,101);
    dp[0] = 0;
    for(int i=1; i<=time; i++){
        for(auto& it : clips){
            if(it[0]<=i&&i<=it[1]) 
                dp[i] = min(dp[i], dp[it[0]]+1);
        } 
    }
    return dp[time]==101 ? -1 : dp[time];
}

// 与跳跃游戏相似
int videoStitching2(vector<vector<int>>& clips, int time) {
    int n = clips.size();
    sort(clips.begin(), clips.end(), [](vector<int>&a, vector<int>&b){
        return a[0]==b[0] ? a[1]>b[1] : a[0]<b[0];
    });
    if(clips[0][0]!=0) return -1;

    int curend = 0, nextend = 0, i = 0, ans=0;
    
    while(i<n&&clips[i][0]<=curend){
        while(i<n&&clips[i][0]<=curend){
            nextend = max(nextend, clips[i][1]);
            i++;
        }
        ans++;
        curend = nextend;
        if(curend>=time) return ans;
    }
    return -1;

}