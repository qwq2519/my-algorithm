class Solution {

    int twoPoiner(int target, vector<int> &nums) {
        int ans = 1e9;
        int n = nums.size();
        int l = 0;
        int sum = 0;
        for (int r = 0; r < n; r++) {
            sum += nums[r];
            while (sum >= target) {
                ans = min(ans, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }
        return ans == 1e9 ? 0 : ans;
    }

    int binarySearch(int target, vector<int> &nums) {
        // 题目还要求一种n log
        // n的，并且元素都是正数，可以考虑前缀和二分。如果不能确保是正数，就是lc862
        // 单调队列
        int ans = 1e9;
        int n = nums.size();
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + nums[i];

        // 假设子数组以i结尾，向前找个j，使得pre[i]-pre[j]>=target,
        // pre[i]-target >= pre[j]  ,让j尽量大即可
        for (int i = 1; i <= n; i++) {
            int need = pre[i] - target;
            int l = -1, r = i;
            while (l + 1 < r) {
                int mid((l + r) >> 1);
                if (pre[mid] <= need)
                    l = mid;
                else
                    r = mid;
            }
            if (l != -1) {
                ans = min(ans, i - l);
            }
        }
        //  for (int i = 0; i < n; i++) {
        //     int need = pre[i] + target;
        //     int j = lower_bound(pre.begin() + i + 1, pre.end(), need) -
        //     pre.begin(); if (j <= n) {
        //         ans = min(ans, j - i);
        //     }
        // }
        // return ans == 1e9 ? 0 : ans;
    }

  public:
    int minSubArrayLen(int target, vector<int> &nums) {
        return binarySearch(target, nums);
    }
};
