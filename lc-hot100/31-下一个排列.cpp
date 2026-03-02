class Solution {
  public:
    void nextPermutation(vector<int> &nums) {
        // 找恰好大一个的排列
        int n = nums.size();
        int i = n - 2;

        // 最小排列 1 2 3 4 5
        // 最大排列 5 4 3 2 1

        // 从右往左第一个上升
        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;
        // i+1 .. n-1 是非递增的
        // 0...i固定 i+1...n-1以及是最大排列了.的修改0..i前缀了
        // 只能修改第i个，稍大点，从后缀i+1..里找

        if (i >= 0) {
            int j = n - 1;
            while (j >= 0 && nums[j] <= nums[i])
                j--;
            swap(nums[i], nums[j]);
        }

        reverse(nums.begin() + i + 1, nums.end());
    }
};
