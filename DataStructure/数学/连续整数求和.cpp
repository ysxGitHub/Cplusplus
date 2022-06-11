/*
给定一个正整数 n，返回 连续正整数满足所有数字之和为 n 的组数 。
*/
#include <iostream>
#include <cmath>
using namespace std;

/*
i: 1, N: 15
i: 2, N: 14
i: 3, N: 12
i: 4, N: 9
i: 5, N: 5
当有i+1个数字时，数组中第i+1个数与第一个数的差为i，所以N每执行一次循环都减i。若能整除i，那么这些连续整数的开始的元素就是N/i了。
*/
int consecutiveNumbersSum(int N) {
    int res = 0;
    for (int i = 1; N > 0; N -= i++){
        cout<<"i: "<<i<<", N: "<<N<<endl;
        res += (N % i == 0);
    }
    return res;
}

/*
根据等差序列的性质:
    s=(a1+an)*n/2
    an=a1+n-1
那么
    2s=(2a1+n-1)*n
可以对2s进行因数分解，分解出来的2个因子 a=n, b=(2a1+a-1)
a的取值范围为1..sqrt(2s)
(b-a+1)/2=a1，也即(b-a+1)/2为整数时，a1有合法的整数解，能找到连续的数列
*/
int consecutiveNumbersSum(int n) {
    n *= 2;
    int len = static_cast<int>(sqrt(n));
    int ans = 0;
    for (int a = 1; a <= len; ++a) {
        if (n % a == 0 && ((n / a - a + 1) & 1) == 0) ans++;
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    consecutiveNumbersSum(15);
    return 0;
}
