/*
给你一个整数 n ，请你在无限的整数序列 [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...]
    中找出并返回第 n 位上的数字。
*/
#include<cmath>
// 9 90*2 900*3 9000*4 ......
int findNthDigit(int n) {
    int d = 1, count = 9;
    while (n > (long) d * count) {
        n -= d * count;
        d++;
        count *= 10;
    }
    // 第几位的idx
    int index = n - 1;
    // 开始于第几位
    int start = (int) pow(10, d - 1);
    // 得到当前所在的数A
    int num = start + index / d;
    // 得到当前还需要在A上移动几位
    int digitIndex = index % d;
    int digit = (num / (int) (pow(10, d - digitIndex - 1))) % 10;
    return digit;
}