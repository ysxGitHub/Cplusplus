/*
给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

必须在不使用库的sort函数的情况下解决这个问题。

进阶：
    你可以不使用代码库中的排序函数来解决这道题吗？
    你能想出一个仅使用常数空间的一趟扫描算法吗？
*/
#include<vector>
#include<iostream>
using namespace std;

void sortColors(vector<int>& nums) {
    int i = 0, j=nums.size()-1;
    for(int k=0; k<=j; k++){
        if(nums[k]==0){
            swap(nums[k], nums[i]);
            i++;
        }
        if(nums[k]==2){
            swap(nums[k], nums[j]);
            j--;
            //-- k 是回到当前 k 的位置，需判断一边置换来的是否为0.
            if(nums[k]!=1){
                k--;
            }
        }
    }
}

// 三路快排的 partition
void sortColors(vector<int>& nums) {
    // [0, i),   [i, j),  [unprocess), [k, nums.size())
    // [<pivot], [=pivot],             [>pivot]
    // partion 3-ways
    int i = 0, j = 0, k = nums.size();
    int pivot = 1;
    while (j != k) {
        if (nums[j] < pivot) {
            swap(nums[i], nums[j]);
            ++j;
            ++i;
        } else if (nums[j] > pivot) {
            swap(nums[j], nums[k-1]);
            --k;
        } else {
            ++j;
        }
    }
}

int main(int argc, char const *argv[])
{
    string s = "abc cbs c";
    cout<<s.substr(s.find(" ")+1)<<endl;
    return 0;
}
