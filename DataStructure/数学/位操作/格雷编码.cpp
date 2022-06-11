/*
n 位格雷码序列 是一个由 2n 个整数组成的序列，其中：
    每个整数都在范围 [0, 2n - 1] 内（含 0 和 2n - 1）
    第一个整数是 0
    一个整数在序列中出现 不超过一次
    每对 相邻 整数的二进制表示 恰好一位不同 ，且
    第一个 和 最后一个 整数的二进制表示 恰好一位不同
给你一个整数 n ，返回任一有效的 n 位格雷码序列 。
*/
#include <vector>
#include <iostream>
using namespace std;


/*
n=0 n=1 n=2  n=3
0    0  00   000
     1  01   001
        11   011
        10   010
             110
             111
             101
             100
*/
vector<int> grayCode(int n) {
    vector<int>ret;
    ret.reserve(1<<n);
    ret.push_back(0);
    for(int i=1; i<=n; i++){
        int m = ret.size();
        for(int j=m-1; j>=0; j--){
            // 镜像翻转
            ret.push_back(ret[j]|(1<<(i-1)));
        }
    }
    return ret;
}

int main(int argc, char const *argv[])
{

    return 0;
}
