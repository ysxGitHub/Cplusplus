/*
什么问题可以运用二分搜索算法技巧？

    首先，你要从题目中抽象出一个自变量 x，一个关于 x 的函数 f(x)，以及一个目标值 target。

    同时，x, f(x), target 还要满足以下条件：

        1、f(x) 必须是在 x 上的单调函数（单调增单调减都可以）。

        2、题目是让你计算满足约束条件 f(x) == target 时的 x 的值。


当目标元素 target 不存在数组 nums 中时，搜索左侧边界的二分搜索的返回值可以做以下几种解读：
    1、返回的这个值是 nums 中大于等于 target 的最小元素索引。
    2、返回的这个值是 target 应该插入在 nums 中的索引位置。
    3、返回的这个值是 nums 中小于 target 的元素个数。

    nums = {1,2,3,4,6} target = 5  find_idx = 4
    nums = {1,2,3,4,5,6} target = 5  find_idx = 4
    nums = {1,2,3,4,5,5,6} target = 5  find_idx = 4

搜索右侧边界的二分搜索的返回值：
    nums = {1,2,3,4,6} target = 5  find_idx = 3
    nums = {1,2,3,4,5,6} target = 5  find_idx = 4
    nums = {1,2,3,4,5,5,6} target = 5  find_idx = 5

*/

#include <iostream>
#include <vector>
using namespace std;

// 标准二分查找一个数  [1, 2)
int binaryFind(vector<int> &array, int target)
{
    int left = 0;
    int right = array.size()-1; // 注意
    int mid;
    while (left <= right) { // 注意

        mid = left + (right - left) / 2;

        if (target < array[mid]){
            right = mid - 1; // 注意
        }
        else if (target > array[mid]){
            left = mid + 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

// 二分查找左边界  [1, 2)  含义：左边有多少比当前小的数
int binaryFindLeft(vector<int> &array, int target)
{
    int left = 0;
    int right = array.size()-1; // 注意
    int mid;
    while (left <= right){ // 注意

        mid = left + (right - left) / 2;

        if (array[mid] < target){
            left = mid + 1;
        }
        else if (array[mid] >= target){
            right = mid - 1; // 注意
        }
        // else{
        //     right = mid - 1; // 注意
        // }
    }
    // 存在左边界时可以直接输出
    // return left; //注意

    /*
    不存在左边界时，target比所有的元素都大
    */
    if (left >= array.size() || array[left] != target)
        return -1;

    return left;
}

// 二分查找右边界 [1, 2)
int binaryFindRight(vector<int> &array, int target)
{
    int left = 0;
    int right = array.size()-1; // 注意
    int mid;
    while (left <= right){ // 注意

        mid = left + (right - left) / 2;

        if (array[mid] <= target){
            left = mid + 1;
        }
        else if (array[mid] > target){
            right = mid - 1; // 注意
        }
        // else{
        //     left = mid + 1; // 注意
        // }
    }
    // 存在右边界时可以直接输出
    // return left-1; // 注意
    /*
    不存在右边界时，target比所有的元素都小
    */
    if (right < 0 || array[right] != target)
        return -1;
    return right;
}

int main(int argc, char const *argv[])
{
    vector<int> array = {1, 6, 8, 9, 10};
    cout << binaryFind(array, 2) << endl;
    cout << binaryFindLeft(array, 7) << endl;
    cout << binaryFindRight(array, 2) << endl;
    return 0;
}
