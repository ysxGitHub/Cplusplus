/*
给你一个长度为 n 的整数数组 nums ，返回使所有数组元素相等需要的最少移动数。
在一步操作中，你可以使数组中的一个元素加 1 或者减 1 。
*/

int minMoves2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int sum = 0, mid = nums[n/2];
    for(auto&num:nums){
        sum += abs(num-mid);
    }
    return sum;
}

// 方法2: 快速选择
int quickSelect(vector<int>& nums, int left, int right, int index) {
    int q = randomPartition(nums, left, right);
    if (q == index) {
        return nums[q];
    } else {
        return q < index ? quickSelect(nums, q + 1, right, index) : quickSelect(nums, left, q - 1, index);
    }
}

inline int randomPartition(vector<int>& nums, int left, int right) {
    int i = rand() % (right - left + 1) + left;
    swap(nums[i], nums[right]);
    return partition(nums, left, right);
}

inline int partition(vector<int>& nums, int left, int right) {
    int x = nums[right], i = left - 1;
    for (int j = left; j < right; ++j) {
        if (nums[j] <= x) {
            swap(nums[++i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[right]);
    return i + 1;
}

int minMoves2(vector<int>& nums) {
    srand(time(0));
    int n = nums.size(), x = quickSelect(nums, 0, n - 1, n / 2), ret = 0;
    for (int i = 0; i < n; ++i) {
        ret += abs(nums[i] - x);
    }
    return ret;
}

