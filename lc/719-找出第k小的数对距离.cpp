class Solution {
    int n;

    int check(int dist, vector<int> &a) {
        int l = 0;
        int cnt = 0;
        // 以r结尾，满足情况的所有l计数
        for (int r = 0; r < n; ++r) {
            while (l < r && a[r] - a[l] > dist) {
                l++;
            }
            cnt += r - l;
        }
        return cnt;
    }

    // 会T一部分
    int solution2(vector<int> nums, int k) {
        // 用堆+多路归并，适合需要输出前k小的
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        for (int i = 1; i < n; i++) {
            pq.push({nums[i] - nums[i - 1], i - 1, i});
        }
        k--;
        while (k--) {
            auto [dist, i, j] = pq.top();
            pq.pop();
            i--;
            if (i >= 0)
                pq.push({nums[j] - nums[i], i, j});
        }
        return get<0>(pq.top());
    }

  public:
    int smallestDistancePair(vector<int> &nums, int k) {
        n = nums.size();
        // 求第k小的数对距离
        // 第k小的,可以用二分答案
        //
        // k最大是n^方，可以多路归并，大概是k logn。
        // 用堆（多路归并）是在枚举答案，而用二分答案是在判断答案，不关心前k小是多少
        // 这题排序后可以很方便的计数，便于二分

        // 数组可以排序，为什么呢，因为i<j起到的是去重作用罢了，让(i,j)==（j,i），你不要把这两一起算就行了
        //
        sort(nums.begin(), nums.end());
        if (k < 2e6)
            return solution2(nums, k);

        int l = -1, r = 1e6 + 7;
        while (l + 1 != r) {
            int mid((l + r) >> 1);
            if (check(mid, nums) >= k)
                r = mid;
            else
                l = mid;
        }
        return r;
    }
};
