/*
我们有 n 栋楼，编号从 0 到 n - 1 。每栋楼有若干员工。由于现在是换楼的季节，部分员工想要换一栋楼居住。

给你一个数组 requests ，其中 requests[i] = [from_i, to_i] ，表示一个员工请求从编号为 from_i 
    的楼搬到编号为 to_i 的楼。

一开始 所有楼都是满的，所以从请求列表中选出的若干个请求是可行的需要满足 每栋楼员工净变化为 0 。
    意思是每栋楼 离开 的员工数目 等于 该楼 搬入 的员工数数目。比方说 n = 3 且两个员工要离开楼 0 ，
    一个员工要离开楼 1 ，一个员工要离开楼 2 ，如果该请求列表可行，应该要有两个员工搬入楼 0 ，
    一个员工搬入楼 1 ，一个员工搬入楼 2 。

请你从原请求列表中选出若干个请求，使得它们是一个可行的请求列表，并返回所有可行列表中最大请求数目。
*/

#include<vector>
#include<iostream>
#include<algorithm>
// #include<bits/stdc++.h>
using namespace std;


vector<int>detal;
int ans=0, cnt=0, zero;
void dfs(int n, vector<vector<int>>& requests, int pos){
    //  遍历完
    if(pos==requests.size()){
        // 0（状态稳定） 的个数等于 房间的个数时
        if(n==zero){
            // 统计那个阶段的cnt最大
            ans = max(ans, cnt);
        }
    }
    // 不选该变换[from, to]
    dfs(n, requests, pos+1);
    // 选该变换
    int z = zero;
    cnt++;
    auto&a = requests[pos];
    int from = a[0];
    int to = a[1];
    // 如果改变之前该位置为0，则zero要减1；如果改变之后该位置为0，则zero要加1
    zero -= detal[from] == 0;
    detal[from] -= 1;
    zero += detal[from] == 0;
    // 如果改变之前该位置为0，则zero要减1；如果改变之后该位置为0，则zero要加1
    zero -= detal[to] == 0;
    detal[to] += 1;
    zero += detal[to] == 0;

    dfs(n, requests, pos+1);
    zero = z;
    cnt--;
    detal[from] += 1;
    detal[to] -= 1;

}

int maximumRequests(int n, vector<vector<int>>& requests) {
    detal.resize(n);
    zero = n;
    dfs(n, requests, 0);
    return ans;
}

// 二进制枚举
int maximumRequests1(int n, vector<vector<int>>& requests) {
    vector<int> detal(n);
    int m = requests.size();
    int ans = 0;
    for(int mask=0; mask<(1<<m); mask++){
        int cnt = __builtin_popcount(mask);
        if(cnt<ans){
            continue;
        }
        fill(detal.begin(), detal.end(), 0);
        for(int i=0; i<m; i++){
            if(mask&(1<<i)){
                detal[requests[i][0]]-=1;
                detal[requests[i][1]]+=1;
            }
        }
        if(all_of(detal.begin(), detal.end(), [](int x){return x==0;})){
            ans = cnt;
        }
    }
    return ans;

}

int main(int argc, char const *argv[])
{
    
    return 0;
}
