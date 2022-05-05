/*
给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。

返回 你可以获得的最大乘积 。
*/
#include<cmath>

int integerBreak(int n) {
    if(n <= 3) return n - 1;
    int a = n/3;
    int b = n%3;
    if(b==1){
        a--;
        b+=3;
    }
    if(b==0) return pow(3, a);
    return pow(3, a)*b;
}