/*
在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。
*/
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ans = 0, bit = 0;
    for(int i=31; i>=0; i--){
        for(auto&num: nums){
            bit += num>>i&1;
        }
        // *2 表示二进制进位，%3 表示3个相同的数字的对应位之和 %3 = 0
        ans = ans * 2 + bit % 3;
        bit = 0;
    }
    return ans;
}

// 有限状态自动机
int singleNumber(vector<int>& nums) {
    int ones = 0, twos = 0;
    for(int num : nums){
        ones = ones ^ num & ~twos;
        twos = twos ^ num & ~ones;
    }
    return ones;
}