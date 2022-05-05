/*
给你一个整数数组 arr ，请使用 煎饼翻转 完成对数组的排序。

一次煎饼翻转的执行过程如下：
    选择一个整数 k ，1 <= k <= arr.length
    反转子数组 arr[0...k-1]（下标从 0 开始）
    
例如，arr = [3,2,1,4] ，选择 k = 3 进行一次煎饼翻转，反转子数组 [3,2,1] ，
    得到 arr = [1,2,3,4] 。

以数组形式返回能使 arr 有序的煎饼翻转操作所对应的 k 值序列。
    任何将数组排序且翻转次数在 10 * arr.length 范围内的有效答案都将被判断为正确。
*/
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;


vector<int> pancakeSort(vector<int>& arr) {
    int maxidx;
    vector<int>ans;
    // 最大的放在后面
    for(int i=arr.size()-1; i>0; i--){
        // 寻找 [0,i] 最大值的 id
        maxidx = max_element(arr.begin(), (arr.begin()+i)) - arr.begin();
        if(maxidx!=i){
            // 如果 [0,i] 的最大值 不等于 0
            if(maxidx!=0){
                // 先将 [0, maxidx] 反转到前面
                reverse(arr.begin(), arr.begin()+maxidx+1);
                ans.emplace_back(maxidx+1);
            
            }
            // 再将 [0, i] 反转 
            reverse(arr.begin(), arr.begin()+i+1);
            ans.emplace_back(i+1);
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int>arr={3,2,4,1};
    vector<int> ans = pancakeSort(arr);
    for(auto&n: ans){
        cout<<n<<"  ";
    }
    return 0;
}
