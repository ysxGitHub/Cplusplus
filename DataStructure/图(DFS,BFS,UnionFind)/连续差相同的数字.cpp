/*
返回所有长度为 n 且满足其每两个连续位上的数字之间的差的绝对值为 k 的 非负整数 。

请注意，除了 数字 0 本身之外，答案中的每个数字都 不能 有前导零。例如，01 有一个前导零，所以是无效的；
    但 0 是有效的。

你可以按 任何顺序 返回答案。
*/
#include<vector>
#include<unordered_set>
#include<iostream>

using namespace std;

/*
一个 N 位的数字可以看作 N-1 位数字加上最后一个数字。如果 N-1 位数字以数字 d 结尾，
    则 N 位数字将以 d-K 或 d+K 结尾（前提是这些数字在 [0,9] 范围内）。
    我们将这些数字存储在 Set 中，以避免重复。
另外，我们应该注意前导 0 -- 只有 1 位数字以 0 开头。
*/
vector<int> numsSameConsecDiff(int n, int k) {
    unordered_set<int>dp = {1,2,3,4,5,6,7,8,9};
    for(int i=1; i<n; i++){
        unordered_set<int>pre_dp = dp;
        dp.clear();
        for(auto&num: pre_dp){
            if(num==0) continue;

            int last = num%10;
            if(last>=k) {
                dp.insert(num*10+last-k);
            }
            if(last+k<=9){
                dp.insert(num*10+last+k);
            }
        }
    }
    return {dp.begin(), dp.end()};
}

int main(int argc, char const *argv[])
{

    return 0;
}

