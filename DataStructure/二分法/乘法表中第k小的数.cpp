/*
几乎每一个人都用 乘法表。但是你能在乘法表中快速找到第k小的数字吗？
给定高度m 、宽度n 的一张 m * n的乘法表，以及正整数k，你需要返回表中第k 小的数字。
*/
#include<iostream>
using namespace std;


//在m，n的乘法表中，寻找不大于num的元素个数
int smallNumCount(int num, int m, int n) {
    int count = 0;
    //对乘法表的每一行（每一行都是递增）进行搜索，muns[row][col] = row * col
    for (int i = 1; i <= m; i++) {
        count += min(num/i, n);//num/i代表的是如果num也在第i行，它存在的列数，而一行最多只有n个
    }
    return count;
}
/*
如果我们需要在第i行中寻找大于num的个数，我们只要min(num / i, n)，
其中（i是这一行的行号，n是矩阵的列数）num / i代表的是如果num也在第i行，
它存在的列数，所以只要取最小值就是第i行不大于num的个数。
（比如例题1中，我们需要知道第2行，不大于4的个数，min(4 / 2, 3) == 2个（就是2， 4））

那么如果我们需要确定这个乘法表中不大于num的个数就非常简单了，我们只要将每一行
不大于num的个数累加即可。（比如例题1中，我们需要知道乘法表中不大于4的个数，
第一行3个、第二行2个，第三行1个）

现在我们就可以使用二分搜索了，初始化left = 1， right = n * m + 1，
mid = （left + right） / 2，在m，n的乘法表中寻找不超过mid的个数。
*/
int findKthNumber(int m, int n, int k) {
    int left = 1, right = m*n;
    while(left<=right){
        int x = (right - left)/2 + left;
        int cnt = x/n*n;
        for(int i=x/n+1; i<=m; i++){
            cnt += x/i;
        }
        if(cnt>=k){
            right = x - 1;
        }else{
            left = x + 1;
        }
    }
    return left;
}


