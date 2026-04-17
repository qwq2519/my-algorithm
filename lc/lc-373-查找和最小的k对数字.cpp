class Solution {
  public:
    vector<vector<int>> kSmallestPairs2(vector<int> &nums1, vector<int> &nums2,
                                        int k) {
        // 贪心，(i,j)是最优解，那么(i+1,j)/(i,j+1)就是次优解，将这些放入堆中即可
        // 但是如果(i+1,j)和(i,j+1)分别是次优和次次优，那么(i+1,j+1)会被放入堆两次
        // 可以加个哈希表去重，但是也可以人为规定
        //(i,j)出堆，只入堆(i,j+1)  实现单维递增
        // 但堆的初始值就是(0,0....n-1)将这些放入堆中即可

        // 也可以将(a[i],b[j])看出二维矩阵，值就是和，那么每一行都是递增的
        // 相当于合并n个升序链表，选出前k小，多路归并

        int n = nums1.size();
        int m = nums2.size();

        priority_queue<tuple<int, int, int>> pq;

        // n<k，那肯定全选，n>k，那直接第一个和另外的全部配对就行了,后续的会慢慢入堆补齐
        for (int i = 0; i < min(n, k); i++) {
            // 变最小堆
            pq.push({-nums1[i] - nums2[0], i, 0});
        }

        vector<vector<int>> ans;
        while (k--) {
            auto [_, i, j] = pq.top();
            pq.pop();
            ans.push_back({nums1[i], nums2[j]});
            if (++j < m) {
                pq.push({-nums1[i] - nums2[j], i, j});
            }
        }
        return ans;
    }
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                       int k) {
        int n = nums1.size();
        int m = nums2.size();

        const int MOD = 133331;
        priority_queue<tuple<int, int, int>> pq;
        unordered_set<int> mp;
        pq.push({-nums1[0] - nums2[0], 0, 0});
        mp.insert(0);

        vector<vector<int>> ans;
        while (k--) {
            auto [_, i, j] = pq.top();
            pq.pop();
            ans.push_back({nums1[i], nums2[j]});
            if (i + 1 < n && mp.find((i + 1) * MOD + j) == mp.end()) {
                mp.insert((i + 1) * MOD + j);
                pq.push({-nums1[i + 1] - nums2[j], i + 1, j});
            }
            if (j + 1 < m && mp.find(i * MOD + j + 1) == mp.end()) {
                mp.insert(i * MOD + j + 1);
                pq.push({-nums1[i] - nums2[j + 1], i, j + 1});
            }
        }
        return ans;
    }
};
