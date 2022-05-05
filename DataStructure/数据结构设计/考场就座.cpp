/*
在考场里，一排有 N 个座位，分别编号为 0, 1, 2, ..., N-1 。

当学生进入考场后，他必须坐在能够使他与离他最近的人之间的距离达到最大化的座位上。
    如果有多个这样的座位，他会坐在编号最小的座位上。
    (另外，如果考场里没有人，那么学生就坐在 0 号座位上。)

返回 ExamRoom(int N) 类，它有两个公开的函数：
    其中，函数 ExamRoom.seat() 会返回一个 int （整型数据），代表学生坐的位置；
    函数 ExamRoom.leave(int p) 代表坐在座位 p 上的学生现在离开了考场。
    每次调用 ExamRoom.leave(p) 时都保证有学生坐在座位 p 上。
*/
#include<bits/stdc++.h>

using namespace std;

static int N;

struct cmp {
    int distance(pair<int, int>interval) const {
        int x = interval.first, y = interval.second;
        if (x == -1) return y;
        if (y == N) return y - x - 1;
        // 中点和端点之间的长度
        return (y - x) / 2;
    }
    bool operator()(pair<int, int>a, pair<int, int>b) const {
        int dist_a = distance(a);
        int dist_b = distance(b);
        // 线段长的放在后面，序号小的放在后面
        return dist_a == dist_b ? a.first > b.first: dist_a < dist_b;
    }
};

class ExamRoom {
private:
    set<pair<int, int>, cmp>pq;
    unordered_map<int, pair<int, int>>startMap;
    unordered_map<int, pair<int, int>>endMap;

    void removeInterval(int x, int y) {
        auto interval = make_pair(x, y);
        pq.erase(interval);
        startMap.erase(x);
        endMap.erase(y);
    }
    void addInterval(int x, int y) {
        auto interval = make_pair(x, y);
        pq.insert(interval);
        startMap[x] = interval;
        endMap[y] = interval;
    }

public:

    ExamRoom(int n) {
        N = n;
        addInterval(-1, n);
    }

    int seat() {
        auto longest = *pq.rbegin();
        int x = longest.first;
        int y = longest.second;
        int seat;
        if (x == -1) {
            seat = 0;
        }
        else if (y == N) {
            seat = N - 1;
        }
        else {
            seat = (y - x) / 2 + x;
        }
        removeInterval(x, y);
        addInterval(x, seat);
        addInterval(seat, y);
        return seat;
    }

    void leave(int p) {
        auto right = startMap[p];
        auto left = endMap[p];
        removeInterval(left.first, left.second);
        removeInterval(right.first, right.second);
        addInterval(left.first, right.second);
    }
};

class ExamRoom {
    int n;
    set<int> s;
public:
    ExamRoom(int N) {
        n = N;
    }
    
    int seat() {
        // 座位为空直接插入 0 位置
        if (s.empty()) {
            s.insert(0);
            return 0;
        }
        int pos = 0, pre = -1, maxDist = 0;
        // 遍历已经插入的位置
        for (int cur : s) {
            // 两个位置之间的中点距离
            int dist = (cur - pre) >> 1;
            // 如果这个两个位置之间的距离/2 大于 最大距离 
            if (dist > maxDist) {
                // pos 保存位置, 考虑开始位置，否则 pos = 左边的位置 + 距离/2
                pos = pre == -1 ? 0 : pre + dist;
                maxDist = dist;
            }
            // 迭代替换
            pre = cur;
        }
        // 考虑最后一个位置的特殊情况 
        if (n - pre - 1 > maxDist) pos = n - 1;
        s.insert(pos);
        return pos;
    }
    
    void leave(int p) {
        s.erase(p);
    }
};


int main(int argc, char const *argv[])
{
    ExamRoom exam(8);
    cout<<exam.seat()<<endl;
    cout<<exam.seat()<<endl;
    cout<<exam.seat()<<endl;
    exam.leave(0);
    exam.leave(7);
    cout<<exam.seat()<<endl;
    cout<<exam.seat()<<endl;
    cout<<exam.seat()<<endl;
    cout<<exam.seat()<<endl;    
    cout<<exam.seat()<<endl;
    cout<<exam.seat()<<endl;
    return 0;
}
