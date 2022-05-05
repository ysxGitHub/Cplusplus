/*
在社交媒体网站上有 n 个用户。给你一个整数数组 ages ，其中 ages[i] 是第 i 个用户的年龄。

如果下述任意一个条件为真，那么用户 x 将不会向用户 y（x != y）发送好友请求：

ages[y] <= 0.5 * ages[x] + 7
ages[y] > ages[x]
ages[y] > 100 && ages[x] < 100
否则，x 将会向 y 发送一条好友请求。

注意，如果 x 向 y 发送一条好友请求，y 不必也向 x 发送一条好友请求。另外，用户不会向自己发送好友请求。

返回在该社交媒体网站上产生的好友请求总数。
*/

#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;


bool check(int x, int y){
    if(y <= 0.5 * x + 7) return false;
    if(y > x) return false;
    if(y > 100 && x < 100) return false;
    return true;
}

int numFriendRequests(vector<int>& ages) {
    int n = ages.size();
    if(n==1) return 0;
    sort(ages.begin(), ages.end());
    int ans=0, i=0, j=0;
    for(int k=0; k<n; k++){
        // 发送交友信息给 ages[k] 的范围
        // 如果左边界指针 i 指向的元素不满足 ages[k]>0.5×ages[i]+7，那么就将左边界向后移动一个位置；
        while(i<k&&!check(ages[i], ages[k])) i++;
        if(j<k) j=k;
        // 如果右边界指针 j 指向的下一个元素满足 ages[k]>0.5×ages[j]+7，那么就将右边界向后移动一个位置。
        while(j<n&&check(ages[j], ages[k])) j++;
        if(j>i) ans += j-i-1;
    }
    return ans;
}

// 利用桶排序
int N = 130;
int numFriendRequests1(vector<int>& ages) {
    // 桶的个数
    vector<int> nums(N);
    // 向桶里装人
    for (int i : ages) nums[i]++;
    // 前缀和
    for (int i = 1; i < N; i++) nums[i] += nums[i - 1];

    int ans = 0;
    int x = 1;
    for (int y = 1; y < N; y++) {
        // 有 a 个年纪为 y 的人
        int a = nums[y] - nums[y - 1];
        if (a == 0) continue;

        if (x < y) x = y;
        // 满足条件时 发送交友信息给 y 的范围
        while (x < N && check(x, y)) x++;
        // [y, x) 为合法的 x 范围，对于每个 y 而言，有 b 个 x
        int b = nums[x - 1] - nums[y - 1] - 1; 
        if (b > 0) ans += b * a;
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    
    return 0;
}
