class Solution {
  public:
    int rangeSum(vector<int> &nums, int n, int left, int right) {
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i, i});
        }

        vector<int> sum;
        sum.reserve(right);

        while (sum.size() < right) {
            auto [val, l, r] = pq.top();
            pq.pop();
            sum.push_back(val);
            if (r + 1 < n) {
                pq.push({val + nums[r + 1], l, r + 1});
            }
        }

        int ans = 0;
        for (int i = left - 1; i < right; i++) {
            ans += sum[i];
            if (ans > 1e9 + 7) {
                ans -= 1e9 + 7;
            }
        }
        return ans;
    }
};
