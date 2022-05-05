/*
给你一个按升序排序的整数数组 num（可能包含重复数字），请你将它们分割成一个或多个长度至少为 3 
    的子序列，其中每个子序列都由连续整数组成。

如果可以完成上述分割，则返回 true ；否则，返回 false 。
*/
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

bool isPossible(vector<int>& nums) {
    // 统计 num 出现的次数， 以及对 num 的需求
    unordered_map<int, int>freq, need;
    for(int n: nums) freq[n]++;
    
    for(int n: nums){
        // 当前 num 的次数已经用完，跳过
        if(freq[n]==0) continue;
        // 检查是否对当前的 num 有需求
        if(need.count(n)&&need[n]>0){
            freq[n]--;
            // 下一个 num 需求 +1
            need[n]--, need[n+1];
        }
        else if(freq[n]>0 && freq[n+1]>0 && freq[n+2]>0){
            // 满足该条件形成一个新的序列
            freq[n]--, freq[n+1]--, freq[n+2]--;
            need[n+3];
        }else{
            // 上面的条件都不能满足
            return false;
        }
    }
    return true;
}

// 显示每个序列划分状况
bool isPossible(vector<int>& nums) {
    unordered_map<int, int> freq;
    unordered_map<int, vector<vector<int>>> need;
    
    for (int v : nums) freq[v]++;
    
    for (int v : nums) {
        if (freq[v] == 0) {
            continue;
        }

        if (need.count(v) && need[v].size() > 0) {
            // v 可以接到之前的某个序列后面
            freq[v]--;
            // 随便取一个需要 v 的子序列
            vector<int> seq = need[v].back();
            need[v].pop_back();
            // 把 v 接到这个子序列后面
            seq.push_back(v);
            // 这个子序列的需求变成了 v + 1
            need[v + 1].push_back(seq);

        } else if (freq[v] > 0 && freq[v + 1] > 0 && freq[v + 2] > 0) {
            // 可以将 v 作为开头
            freq[v]--;
            freq[v + 1]--;
            freq[v + 2]--;
            // 新建一个长度为 3 的子序列 [v,v + 1,v + 2]
            vector<int> seq{v, v + 1, v + 2};
            // 对 v + 3 的需求加一
            need[v + 3].push_back(seq);

        } else {
            return false;
        }
    }
    
    // 打印切分出的所有子序列
    for (auto it : need) {
        for (vector<int>& seq : it.second) {
            for (int v : seq) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
    
    return true;
}


/*
由于题目要求每个子序列的长度至少为 3，显然应该让最短的子序列尽可能长，
    因此应该将 x 加入其中最短的子序列。
*/
bool isPossible(vector<int>& nums) {
    unordered_map<int, priority_queue<int, vector<int>,greater<int>>> mp;
    for (auto& x : nums) {
        // 该 num 不存在 hashtable 中
        if (mp.find(x) == mp.end()) {
            // 小顶堆, 序列短的先添加 num
            mp[x] = priority_queue<int, vector<int>,greater<int>>();
        }
        // 前一个 num 存在 hashtable 中
        if (mp.find(x - 1) != mp.end()) {
            // 前一个 num 所在的最小序列长度
            int prevLength = mp[x - 1].top();
            // 前一个 num 所在的最小序列长度 弹出
            mp[x - 1].pop();
            if (mp[x - 1].empty()) {
                mp.erase(x - 1);
            }
            // 当前 num 序列长度 是 前一个 num 所在的最小序列长度 +1;
            mp[x].push(prevLength + 1);
        } else {
            // 都不成立 自己插入 +1
            mp[x].push(1);
        }
    }
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        priority_queue<int, vector<int>,greater<int>> queue = it->second;
        if (queue.top() < 3) {
            return false;
        }
    }
    return true;
}

