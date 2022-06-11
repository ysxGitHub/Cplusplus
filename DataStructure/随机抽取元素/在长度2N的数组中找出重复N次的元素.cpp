/*
给你一个整数数组 nums ，该数组具有以下属性：

nums.length == 2 * n.
nums 包含 n + 1 个 不同的 元素
nums 中恰有一个元素重复 n 次
找出并返回重复了 n 次的那个元素。
*/

int repeatedNTimes(vector<int>& nums) {
    int n = nums.size();
    mt19937 gen{random_device{}()};
    uniform_int_distribution<int> dis(0, n - 1);
    while (true) {
        int x = dis(gen), y = dis(gen);
        if (x != y && nums[x] == nums[y]) {
            return nums[x];
        }
    }
}