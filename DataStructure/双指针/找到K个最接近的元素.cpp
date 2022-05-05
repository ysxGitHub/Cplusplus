/*
给定一个 排序好 的数组 arr ，两个整数 k 和 x ，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。

整数 a 比整数 b 更接近 x 需要满足：

    |a - x| < |b - x| 或者
    |a - x| == |b - x| 且 a < b
*/
#include <vector>
#include <iostream>
using namespace std;


vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int j=arr.size()-1, i=0;
    while(i<j){
        if(j-i+1==k) break;
        if(abs(arr[i]-x)>abs(arr[j]-x)){
            i++;
        }else{
            j--;
        }
    }
    vector<int>ans;
    for(; i<=j; i++){
        ans.push_back(arr[i]);
    }
    return ans;
}