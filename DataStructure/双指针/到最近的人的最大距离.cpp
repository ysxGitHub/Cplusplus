/*
给你一个数组 seats 表示一排座位，其中 seats[i] = 1 代表有人坐在第 i 个座位上，seats[i] = 0 代表座位 i 上是空的（下标从 0 开始）。

至少有一个空座位，且至少有一人已经坐在座位上。

亚历克斯希望坐在一个能够使他与离他最近的人之间的距离达到最大化的座位上。

返回他到离他最近的人的最大距离。
*/
#include <vector>
using namespace std;

//法1：计算座位到最近的人的最大距离
/*
令 left[i] 为座位 i 到坐在 i 左边的人的最近距离。同理 right[i] 为座位 i 到坐在 i 右边的人的最近距离。那么该座位到最近的人的距离为 min(left[i], right[i])。
*/
int maxDistToClosest(vector<int>& seats) {
    int N = seats.size();
    vector<int> left(N, N), right(N, N);
    for (int i = 0; i < N; ++i) {
        if (seats[i] == 1) left[i] = 0;
        else if (i > 0) left[i] = left[i-1] + 1;
    }

    for (int i = N-1; i >= 0; --i) {
        if (seats[i] == 1) right[i] = 0;
        else if (i < N-1) right[i] = right[i+1] + 1;
    }

    int ans = 0;
    for (int i = 0; i < N; ++i)
        if (seats[i] == 0)
            ans = max(ans, min(left[i], right[i]));
    return ans;
}

// 法2： 双指针
int maxDistToClosest(vector<int>& seats) {
    int N = seats.size();
    int prev = -1, future = 0;
    int ans = 0;

    for (int i = 0; i < N; ++i) {
        if (seats[i] == 1) {
            prev = i;
        } else {
            while (future < N && seats[future] == 0 || future < i)
                future++;

            int left = prev == -1 ? N : i - prev;
            int right = future == N ? N : future - i;
            ans = max(ans, min(left, right));
        }
    }
    return ans;
}

// 法3： 按零分组
int maxDistToClosest(vector<int>& seats) {
    int prev=-1, maxnid=1;
    int n = seats.size();
    for (int i = 0; i < n; i++) {
        //遇到1时计算有多少个0
        if (seats[i]==1) {
            //前面遇到过1，要除以2
            if (prev>=0) maxnid=max((i-prev)/2,maxnid);
            //前面没有1不需要除2
            else maxnid=i;
            prev=i;
        }
    }
    //最后的0个数再判断一次
    maxnid=max((n-1)-prev, maxnid);
    return maxnid;
}