class Solution {
  public:
    int minimumDeviation(vector<int> &nums) {
        int n = nums.size();

        // 偶数一直除2，最后变成1，不能在变回去了
        // 奇数*2变偶数，再除2变回去了。
        // 因此每个数的状态数都是可选的。
        // 每个位置的都是一个集合状态，怎么从从每个位置选出最合适的状态
        // 使得极差最小？

        // 先让奇数全变成偶数，最后状态就是单向的好管理了,每个元素都从自己最大值往下缩小
        // max-min       偶数只能变小，让最大值变小就行。
        // 奇数能变大，但是又变成偶数了，没意义。
        int ans = 1e9;
        int mn = 1e9;
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            if (nums[i] & 1)
                nums[i] <<= 1;
            mn = min(mn, nums[i]);
            pq.push(nums[i]);
        }

        // 只动最大值，不然的话会让min缩小，答案更差，这是贪心
        while (1) {
            auto mx = pq.top();
            pq.pop();
            ans = min(ans, mx - mn);

            if (mx & 1)
                break; // 最大值无法再缩小了

            mn = min(mn, mx / 2);
            pq.push(mx / 2);
        }

        return ans;
    }
};
