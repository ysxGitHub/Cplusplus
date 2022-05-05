/*
电子游戏“辐射4”中，任务 “通向自由” 要求玩家到达名为 “Freedom Trail Ring” 的金属表盘，
    并使用表盘拼写特定关键词才能开门。

给定一个字符串 ring ，表示刻在外环上的编码；给定另一个字符串 key ，表示需要拼写的关键词。
    您需要算出能够拼写关键词中所有字符的最少步数。

最初，ring 的第一个字符与 12:00 方向对齐。您需要顺时针或逆时针旋转 ring 以使 key 的一个字符在 
    12:00 方向对齐，然后按下中心按钮，以此逐个拼写完 key 中的所有字符。

旋转 ring 拼出 key 字符 key[i] 的阶段中：

您可以将 ring 顺时针或逆时针旋转 一个位置 ，计为1步。旋转的最终目的是将字符串 ring 的一个字符与 
    12:00 方向对齐，并且这个字符必须等于字符 key[i] 。
如果字符 key[i] 已经对齐到12:00方向，您需要按下中心按钮进行拼写，这也将算作 1 步。按完之后，
    您可以开始拼写 key 的下一个字符（下一阶段）, 直至完成所有拼写。
*/

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

// 返回 a b 之间的最小距离
int culdis(int len, int a, int b){
    return min((len + a - b)%len, (len + b - a)%len);
}

int findRotateSteps(string ring, string key) {
    int n = ring.size(), m = key.size();
    vector<int> pos[26];
    // 记录环中每个字母的位置
    for(int i=0; i<n; i++) pos[ring[i]-'a'].emplace_back(i);
    // dp[i][j] 的定义： 在匹配 key 中第 i 个字母的时候，使用 ring 中第 j 个位置，所需要的操作。
    vector<vector<int>>dp(m, vector<int>(n, INT32_MAX));
    for(int i=0; i<m; i++){
        for(auto j: pos[key[i]-'a']){
            if(i==0){
                // 第一个 key 中的字母，不用考虑前一个位置
                dp[i][j] = min(dp[i][j], 0 + culdis(n, 0, j) + 1);
                continue;
            }
            for(auto k: pos[key[i-1]-'a']){
                //非第一个的字母， 需要看一下从前面的字母，怎么转移来是操作数最小的。
                dp[i][j] = min(dp[i][j], dp[i-1][k] + culdis(n, k, j) + 1);
            }
        }
    }
    // 返回 key 最后一个字母 最短距离
    return *min_element(dp[m-1].begin(), dp[m-1].end());
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
