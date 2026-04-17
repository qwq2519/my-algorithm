class Solution {
  public:
    int firstMissingPositive(vector<int> &nums) {
        int n = nums.size();
        // nums[i] 放i+1
        for (auto &it : nums) {
            if (it <= 0 || it > n)
                it = n + 1;
        }

        // 用负数标记这个数已经出现过了
        // abs的原因是因为取负号便于后面统计，更通用什么的。
        for (int i = 0; i < n; i++) {
            int x = abs(nums[i]);
            if (x >= 1 && x <= n) {
                int idx = x - 1;
                if (nums[idx] > 0)
                    nums[idx] = -nums[idx];
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                return i + 1;
        }
        return n + 1;
    }
};
class Solution {
  public:
    int firstMissingPositive(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] < 1 || nums[i] > n) {
                nums[i] = n + 1;
            }
        }

        for (int i = 0; i < n; ++i) {
            while (nums[i] != n + 1 && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};
