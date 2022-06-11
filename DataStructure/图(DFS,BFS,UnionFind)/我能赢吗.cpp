/*
在 "100 game" 这个游戏中，两名玩家轮流选择从 1 到 10 的任意整数，累计整数和，先使得累计整数和 达到或超过  100 的玩家，即为胜者。

如果我们将游戏规则改为 “玩家 不能 重复使用整数” 呢？

例如，两个玩家可以轮流从公共整数池中抽取从 1 到 15 的整数（不放回），直到累计整数和 >= 100。

给定两个整数 maxChoosableInteger （整数池中可选择的最大数）和 desiredTotal（累计和），若先出手的玩家是否能稳赢则返回 true ，否则返回 false 。假设两位玩家游戏时都表现 最佳 。
*/
#include <iostream>
#include <vector>
using namespace std;

// visited[i] == 0，说明没有计算过
// visited[i] == 1，说明计算过，结果为 true
// visited[i] == 2，说明计算过，结果为 false
bool visited[1<<21];

bool dfs(int maxChoosableInteger, int desiredTotal, int sum, int state){
    if(visited[state]==1) return true;
    if(visited[state]==2) return false;
    for(int x=1; x<=maxChoosableInteger; ++x){
        if(((1<<x)&state)!=0) continue;
        // 如果选择了 x 以后，大于等于了 desiredTotal，当前玩家赢
        if(x+sum>=desiredTotal){
            visited[state] = 1;
            return true;
        }
        // 当前玩家选择了 x 以后，判断对方玩家一定输吗？
        if(!dfs(maxChoosableInteger, desiredTotal, sum+x, state|(1<<x))){
            visited[state] = 1;
            return true;
        }
    }
    visited[state] = 2;
    return false;
}

bool canIWin(int maxChoosableInteger, int desiredTotal) {
    if(maxChoosableInteger>=desiredTotal) return true;
    // 总和小于 desiredTotal 一定失败
    if(maxChoosableInteger*(maxChoosableInteger+1)<desiredTotal) return false;
    // 判断当前做选择的玩家（先手），是否一定赢
    return dfs(maxChoosableInteger, desiredTotal, 0, 0);
}

