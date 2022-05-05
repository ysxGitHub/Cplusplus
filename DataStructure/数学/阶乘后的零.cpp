/*
给定一个整数 n ，返回 n! 结果中尾随零的数量。

提示 n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1
*/
#include<iostream>  
using namespace std;

/*
思路：主要看阶乘数的因子中含的2和5的个数
但是每个偶数都包含2，所以主要看5的个数。
如 125!  125/125 = 1个5的倍数 
        125/25 = 5个5的倍数
        125/5 = 25个5的倍数
        sum = 25 + 5 + 1
*/ 

int trailingZeroes1(int n) {
    int mod = 5, cnt = 0;
    while(n>=mod){
        cnt += n/mod;
        n /= mod;
    }
    return cnt;
}

int trailingZeroes(int n){
    int cnt = 0;
    for(int d = n; d/5 > 0; d /= 5){
        cnt += d/5;
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
