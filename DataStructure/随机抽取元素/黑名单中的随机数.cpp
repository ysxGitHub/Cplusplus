/*
给定一个整数 n 和一个 无重复 黑名单整数数组 blacklist 。设计一种算法，从 [0, n - 1] 
    范围内的任意整数中选取一个 未加入 黑名单 blacklist 的整数。
    任何在上述范围内且不在黑名单 blacklist 中的整数都应该有 同等的可能性 被返回。

优化你的算法，使它最小化调用语言 内置 随机函数的次数。

实现 Solution 类:
    Solution(int n, int[] blacklist) 初始化整数 n 和被加入黑名单 blacklist 的整数
    int pick() 返回一个范围为 [0, n - 1] 且不在黑名单 blacklist 中的随机整数

*/

#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<iostream>
#include<ctime>
#include<algorithm>
using namespace std;



class Solution1 {
private:
    vector<int> _bl;
    int _sz;
public:
    Solution1(int n, vector<int>& blacklist) {
        srand((unsigned)time(NULL));
        _bl = blacklist;
        sort(_bl.begin(), _bl.end());
        _sz = n - blacklist.size();
    }

    int pick() {
        int k = rand() % _sz;
        int lo = 0;
        int hi = _bl.size() - 1;
        while(lo < hi){
            int mid = (lo + hi + 1)/2;
            if(_bl[mid] - mid > k){
                hi = mid - 1;
            }
            else if(_bl[mid] - mid <= k){
                lo = mid;
            }
        }
        return lo == hi && _bl[lo] - lo <= k ? k + lo + 1 : k;
    }
};


class Solution {
private:
    unordered_map<int, int>m;
    int sz;

public:
    Solution(int n, vector<int>& blacklist) {
        srand((unsigned)time(NULL));
        // 后一半的起点
        sz = n - blacklist.size();
        unordered_set<int> w;
        // w先插入后边的所有元素，再擦去后边里存在black中的元素，只保留后部white元素，
        // w的大小与black中小于sz的元素个数一样多
        for(int i=sz; i<n; i++) w.insert(i);
        for(int b: blacklist) w.erase(b);
        // 将b中小于sz的元素映射到后部w位置上
        auto wb = w.begin();
        for(int b: blacklist){
            if(b<sz){
                m[b] = *wb++;
            }
        }

    }
    

    int pick() {
        int idx = rand() / sz;
        if(m.count(idx)){
            return m[idx];
        }
        return idx;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
