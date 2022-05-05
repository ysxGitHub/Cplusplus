/*
给定整数 n ，返回 所有小于非负整数 n 的质数的数量 。
*/

#include<iostream> 
#include<vector> 
using namespace std;


bool isPrime(int num) {
if (num <= 1) return false;
for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) return false;
}
return true;
}
// 超时
int countPrimes1(int n) {
    int count = 0;
    for (int i = 1; i < n; i++) {
        if (isPrime(i)) count++;
    }
    return count;
}


int countPrimes(int n) {
    if(n<=1) return 0;
    vector<bool> isPrime(n, 1);
    isPrime[0] = isPrime[1] = false;
    // 从 2 开始枚举到 sqrt(n)。
    for (int i = 2; i * i < n; i++) {
        if (!isPrime[i]) continue;
        // 如果当前是素数, 就把从 i*i 开始，i 的所有倍数都设置为 false。
        /*
            要从x^2开始
            任意素数x的倍数有：2x, 3x, 4x, ..., x*x, (x+1)*x, ...
            任意小于x*x的倍数都被之前的素数筛过滤过，如：2 过滤 2x, 4x, ...，3 过滤 3x, ...
            所以从x*x开始过滤之后的倍数，所以x只需遍历到sqrt(N)        
        */
        for (int j = i * i; j < n; j += i) {
            isPrime[j] = false;
        }
    }
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) count++;
    }
    return count;
}

