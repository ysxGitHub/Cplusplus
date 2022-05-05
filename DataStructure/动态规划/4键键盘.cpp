/*
假设你有一个特殊的键盘包含下面的按键：
    A：在屏幕上打印一个 'A'。
    Ctrl-A：选中整个屏幕。
    Ctrl-C：复制选中区域到缓冲区。
    Ctrl-V：将缓冲区内容输出到上次输入的结束位置，并显示在屏幕上。
现在，你可以 最多 按键 n 次（使用上述四种按键），返回屏幕上最多可以显示 'A' 的个数 。


输入: n = 3
输出: 3
解释: 
我们最多可以在屏幕上显示三个'A'通过如下顺序按键：
    A, A, A

输入: n = 7
输出: 9
解释: 
我们最多可以在屏幕上显示九个'A'通过如下顺序按键：
    A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V

提示:
    1 <= n <= 50
*/

#include<vector>
#include<iostream>
using namespace std;

int maxA(int n) {
    vector<int>dp(n+1);
    for(int i=1; i<=n; i++){
        // 按 A 
        dp[i] = dp[i-1]+1;
        // 按 C-V, 要先按 C-A C-C
        // 屏幕上共有 dp[i-2] * ( i - j + 1) 个 A
        for(int j=2; j<i; j++){
            dp[i] = max(dp[i], dp[i-2] * ( i - j + 1));
        }
    }
    return dp[n];
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
