/*
给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，
    分别表示 nums1 和 nums2 中的元素数目。

请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。

注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。
    为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，
    后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。
*/
#include<vector>
#include<iostream>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    for(int k=0; k<n; k++){
        nums1.pop_back();
    }

    if(n==0){
        nums1;
    }
    else if(m==0){
        nums1.assign(nums2.begin(), nums2.end()); 
    }else if(n==0&&m==0){
        nums1;
    }
    else{
        vector<int>tmp;
        int i=0;
        int j=0;
        int len1 = nums1.size();

        while (1)
        {
            if(nums1[i]<=nums2[j]){
                tmp.push_back(nums1[i]);
                i++;
                if(i>=len1){
                    break;
                }
            }else{
                tmp.push_back(nums2[j]);
                j++;
                if(j>=n){
                    break;
                }
            }
        }

        while(j<n){
            tmp.push_back(nums2[j]);
            j++;
        }

        while (i<len1){
            tmp.push_back(nums1[i]);
            i++;
        }
        
        nums1.assign(tmp.begin(), tmp.end());            
    }

    for(auto n1: nums1){
        cout<<n1<<"  ";
    }
    
}

void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p1 = m-1;
    int p2 = n-1;
    int tail = p1 + p2 + 1; 

    int cur=0;
    while(p1>=0||p2>=0){
        if(p1==-1){
            cur = nums2[p2--];
        }
        else if(p2==-1){
            cur = nums1[p1--];
        } 
        else if(nums1[p1]>nums2[p2]){
            cur = nums1[p1--];
        }
        else{
            cur = nums2[p2--];
        }
        nums1[tail--] = cur;
    }
    // return nums1;
}

int main(int argc, char const *argv[])
{

    vector<int>nums1={1,2,3,0,0,0};
    vector<int>nums2={2,3,6};
    merge1(nums1, 3, nums2, 3);
    return 0;
}
