class Solution {
  public:
    int shortestSubarray(vector<int> &nums, int k) {
        // 如果都是正数，那么就可以滑动窗口了
        // 单调队列：本质维护的是候选集合，每个元素未来都可能会被用到
        // 队首是已经被使用的，未来产生更优答案不会用到
        // 队尾是被信新来的各方面超越的废物）
        //
        // 适合做：按顺序扫描，每个位置都要从前面一堆候选选最优，旧候选会因为新候选的到来而部分失效，失效关系有单调性
        //  1你是从左到右扫描数组
        // 2. 每个位置都要从前面一段候选里选最优
        // 3. 候选一旦过期，以后永远不会再用
        // 4. 新候选出现后，会让某些旧候选永久失效
        // 5. 你要的是最值、最短、最长，且可以边扫边删候选
        // 6. 朴素做法是“每次都在前面一堆元素里找最优”

        // k是正数
        int ans = 1e9;
        deque<int> q;
        int n = nums.size();
        vector<long long> pre(n + 3, 0); // 里面的i下标递增,里面的pre[i]也递增
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + nums[i];

        // pre[i]-pre[front] >=k         front尽量大,但是pre[front]尽量小
        for (int i = 0; i <= n; i++) {
            // i比里面的位置后面，但是pre更小，
            while (!q.empty() && pre[q.back()] >= pre[i])
                q.pop_back();
            while (!q.empty() && pre[i] - pre[q.front()] >= k) {
                ans = min(ans, i - q.front());
                q.pop_front(); // 已经配对了后续用不上了
            }

            q.push_back(i);
        }

        return ans == 1e9 ? -1 : ans;
    }
};
