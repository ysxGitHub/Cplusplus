/*
在代号为 C-137 的地球上，Rick 发现如果他将两个球放在他新发明的篮子里，它们之间会形成特殊形式的磁力。
    Rick 有 n 个空的篮子，第 i 个篮子的位置在 position[i] ，Morty 想把 m 个球放到这些篮子里，
    使得任意两球间 最小磁力 最大。

已知两个球如果分别位于 x 和 y ，那么它们之间的磁力为 |x - y| 。

给你一个整数数组 position 和一个整数 m ，请你返回最大化的最小磁力。
*/

#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

bool check(int x, vector<int>& position, int m){
    // 最左边已经存在一个小球 cnt = 1;
    int cnt=1, prepos = position[0];
    for(int i=1; i<position.size(); i++){
        // 大于最小最大磁力
        if (position[i] - prepos >= x){
            cnt++;
            prepos = position[i];
        }
        
    }
    return cnt >= m;
}


int maxDistance(vector<int>& position, int m) {
    sort(position.begin(), position.end());
    // 最小 最小最大 磁力也是 1, 最大 最小最大 磁力是最大距离除以球的个数 n-1
    int left = 1, right = (position.back() - position[0])/(m-1);
    int ans = 0;
    // 搜寻最小最大磁力
    while(left <= right){
        int mid = (left + right)/2;
        if(check(mid, position, m)){
            ans = (mid, ans);
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
