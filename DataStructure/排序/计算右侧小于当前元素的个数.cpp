/*
给你一个整数数组 nums ，按要求返回一个新数组 counts 。数组 counts 有该性质： 
    counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。
*/

#include<iostream>
#include<vector>
using namespace std;


// 归并排序所用的辅助数组
vector<pair<int, int>> temp;
// 记录每个元素后面比自己小的元素个数
vector<int> count;

// 合并两个有序数组
void merge(vector<pair<int, int>>& arr, int lo, int mid, int hi) {
    for (int i = lo; i <= hi; i++) {
        temp[i] = arr[i];
    }
    // 这里必须j = mid + 1，让 i 可以等于 mid 
    int i = lo, j = mid + 1;
    for (int p = lo; p <= hi; p++) {
        if (i == mid + 1) {
            arr[p] = temp[j++];
        } else if (j == hi + 1) {
            arr[p] = temp[i++];
            /*
            这时候我们应该把temp[i]放到nums[p]上，因为temp[i] < temp[j]。
            但就在这个场景下，我们还可以知道一个信息：5 后面比 5 小的元素个数就是j和
            mid + 1之间的元素个数，即 2 个。
            
            换句话说，在对nuns[lo..hi]合并的过程中，每当执行nums[p] = temp[i]时，
            就可以确定temp[i]这个元素后面比它小的元素个数为j - mid - 1。
                lo     mid+1      hi 
            tmp 1  3  5  2  4  6  7
                        i        j
            arr 1  2  3  4
                            p 

            */ 
            // 更新 count 数组，注意这里是 += 
            count[arr[p].second] += j - mid - 1;
        } else if (temp[i].first > temp[j].first) {
            arr[p] = temp[j++];
        } else {
            arr[p] = temp[i++];
            // 更新 count 数组
            count[arr[p].second] += j - mid - 1;
        }
    }
}

// 归并排序
void sort(vector<pair<int, int>>& arr, int lo, int hi) {
    if (lo == hi) return;
    int mid = lo + (hi - lo) / 2;
    sort(arr, lo, mid);
    sort(arr, mid + 1, hi);
    merge(arr, lo, mid, hi);
}


vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    count.resize(n);
    temp.resize(n);
    vector<pair<int, int>> arr(n);
    // 记录元素原始的索引位置，以便在 count 数组中更新结果
    for (int i = 0; i < n; i++)
        arr[i] = make_pair(nums[i], i);

    // 执行归并排序，本题结果被记录在 count 数组中
    sort(arr, 0, n - 1);

    return count;
}

int main(int argc, char const *argv[])
{
    vector<int>nums = {9,8,3,2,1,0,6,7,5,4};
    nums = countSmaller(nums);
    for(auto&n: nums){
        cout<<n<<", ";
    }
    return 0;
}
