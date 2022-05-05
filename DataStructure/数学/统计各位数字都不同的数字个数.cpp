/*
给你一个整数 n ，统计并返回各位数字都不同的数字 x 的个数，其中 0 <= x < 10^n 。
*/

/*
对于其他情况，由于不能含有前导 0，最高位可选择的数值个数为 9，而从次高位开始到最低位，
    可选的个数从 9 开始逐一递减。

利用乘法原理，每位数可选的数值个数相乘即是长度为 n 的数的可能方案数 cur，
    而所有长度 [1,n] 的方案数累加即是答案。
*/

int countNumbersWithUniqueDigits(int n) {
    if(n==0) return 1;
    int last = 9, cur = 0, ans = 10;
    for(int i = 2; i <= n; i++){
        cur = last * (10 - i + 1);
        ans += cur;
        last = cur;
    }
    return ans;
}

int main(int argc, char const *argv[])
{

    return 0;
}
