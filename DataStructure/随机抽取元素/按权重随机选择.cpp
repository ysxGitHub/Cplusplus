/*

给你一个 下标从 0 开始 的正整数数组 w ，其中 w[i] 代表第 i 个下标的权重。

请你实现一个函数 pickIndex ，它可以 随机地 从范围 [0, w.length - 1] 内（含 0 和 w.length - 1）
    选出并返回一个下标。选取下标 i 的 概率 为 w[i] / sum(w) 。

例如，对于 w = [1, 3]，挑选下标 0 的概率为 1 / (1 + 3) = 0.25 （即，25%），
    而选取下标 1 的概率为 3 / (1 + 3) = 0.75（即，75%）。

思路:
    1、根据权重数组 w 生成前缀和数组 preSum。

    2、生成一个取值在 preSum 之内的随机数，用二分搜索算法寻找大于等于这个随机数的最小元素索引。

    3、最后对这个索引减一（因为前缀和数组有一位索引偏移），就可以作为权重数组的索引，即最终答案:
*/

#include<vector>
#include<iostream>
#include<ctime>
using namespace std;

class Solution {
    vector<int>sumarr;
public:
    Solution(vector<int>& w) {

        // srand((unsigned)time(NULL));
        sumarr.resize(w.size());
        sumarr[0] = w[0];
        for(int i=1; i<w.size(); i++){
            sumarr[i] = sumarr[i-1] + w[i];
        }
    }


    int pickIndex() {
        // 为什么不能包括 0 , k不能包括0, 1 <= w[i], 1 <= w.length, 所以前缀和一定大于0
        int k = rand() % sumarr.back() + 1;
        // int k = 7;
        int left = 0, right = sumarr.size()-1;
        while(left <= right){
            int mid = (left + right)/2;
            if(sumarr[mid] >= k){
                right = mid - 1;
            }
            else if(sumarr[mid] < k){
                left = mid + 1;
            }
        }
        return left;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {2,4,5};
    Solution sl(nums);
    cout<<sl.pickIndex();
    return 0;
}
