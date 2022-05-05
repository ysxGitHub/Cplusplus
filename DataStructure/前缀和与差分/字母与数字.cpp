/*
给定一个放有字母和数字的数组，找到最长的子数组，且包含的字母和数字的个数相同。

返回该子数组，若存在多个最长子数组，返回左端点下标值最小的子数组。若不存在这样的数组，返回一个空数组。
*/
#include<vector>
#include<unordered_map>
using namespace std;

vector<string> findLongestSubarray(vector<string>& array) {
    int n = array.size();
    int left = -1, right = -1;
    unordered_map<int, int> preSum;
    preSum[0] = -1;
    int sum = 0;
    for(int i=0; i<n; i++){
        string s = array[i];
        // 是字母就减一
        if(s[0]>='A'&&s[0]<='z'){
            sum--;
        }else{ //否则加一
            sum++;
        }
        // 如果当前前缀和，已存在
        if(preSum.count(sum)){
            // 并且 i~j 的距离 大于 之前的记录
            if(i-preSum[sum]>right-left) {
                right = i;
                left = preSum[sum];
            }
        }else { // 否则 记录当前的前缀和
            preSum[sum] = i;
        }
    }
    // 返回
    return {array.begin()+left+1, array.begin()+right+1};
}