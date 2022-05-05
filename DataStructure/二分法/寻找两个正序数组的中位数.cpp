/*
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

算法的时间复杂度应该为 O(log (m+n)) 

*/

#include<vector>
#include<iostream>

using namespace std;


double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
    int len1 = nums1.size(), len2 = nums2.size();
    int idx = 0, idx1 = 0, idx2 = 0;
    int first = 0, second = 0;
    bool isqi = (len1 + len2)%2;
    int half = isqi ? (len1 + len2 - 1)/2 : (len1 + len2)/2;
    while(idx1<len1||idx2<len2){
        if(idx1<len1&&idx2<len2&&nums1[idx1]<nums2[idx2]){
            second = first;
            first = nums1[idx1];
            idx1++;
        }
        else if(idx1<len1&&idx2<len2&&nums1[idx1]>nums2[idx2]){
            second = first;
            first = nums2[idx2];                
            idx2++;
        }
        else if(idx1<len1){
            second = first;
            first = nums1[idx1];
            idx1++;                
        }
        else{
            second = first;
            first = nums2[idx2];                
            idx2++;                
        }
        idx++;
        if(idx>half){
            break;
        }
    }
    return isqi ? first : (first + second)/2.0 ;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // 使a数组数量少些
    if(nums1.size() > nums2.size()){
        nums1.swap(nums2);
    }
    int m = nums1.size();
    int n = nums2.size();
    
    // a，b两个数组左边界的元素个数之和
    int totalLeft = (m + n + 1) / 2;
    
    int left = 0;
    int right = m;

    while(left < right){
        // a数组的右边界， 加一防止死循环
        int i = (left + right + 1) / 2;
        // b数组的右边界
        int j = totalLeft - i;
        // 如果a数组的左边界大于b数组的右边界
        if(nums1[i - 1] > nums2[j]){
            right = i - 1;
        }else{
        // 如果a数组的左边界小于等于b数组的右边界
            left = i;
        }
    }
    int i = left;
    int j = totalLeft - i;
    // 注意判断边界
    int nums1LeftMax = i == 0 ? INT32_MIN : nums1[i - 1];
    int nums1RightMin = i == m ? INT32_MAX : nums1[i];

    int nums2LeftMax = j == 0 ? INT32_MIN : nums2[j - 1];
    int nums2RightMin = j == n ? INT32_MAX : nums2[j];    
    // cout<<nums1LeftMax<<","<<nums1RightMin<<","<<nums2LeftMax<<","<<nums2RightMin<<endl;

    if((m + n)%2){
        return max(nums1LeftMax, nums2LeftMax);
    }else{
        return (max(nums1LeftMax, nums2LeftMax) + min(nums1RightMin, nums2RightMin))/2.0;
    }
    
}


int main(int argc, char const *argv[])
{
    vector<int> nums1={1,2,3};
    vector<int> nums2={2};
    cout<<findMedianSortedArrays(nums1, nums2);
    return 0;
}
