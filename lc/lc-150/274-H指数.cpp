#include <cinttypes>
class Solution {

    bool check(vector<int> &v, int mid) {
        int count = 0;
        for (const auto &x : v) {
            count += x >= mid;
        }
        return count >= mid;
    }

    int Solution1(vector<int> &citations) {
        int n = citations.size();
        // 经典二分做法
        int l = -1, r = n + 1;
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (check(citations, mid)) {
                l = mid;
            } else
                r = mid;
        }

        return l;
    }

    int Solution2(vector<int> &a) {
        // 可以利用排序后的 位置含义来二分
        // 排序后 a[i]后面有n-i，如果a[i]>=n-i,则说明 n-i也是h指数。
        // i增大，  a[i] 增大,n-i减小，一定有个边界，不等式有单调性
        sort(a.begin(), a.end());
        int n = a.size();
        int l = -1, r = n;
        // while (l + 1 != r) {
        //     int mid = (l + r) >> 1;
        //     if (a[mid] >= n - mid) {
        //         r = mid;
        //     } else
        //         l = mid;
        // }
        //
        for (int i = 0; i < n; i++) {
            if (citations[i] >= n - i) {
                return n - i;
            }
        }
        return n - r;
    }

  public:
    int hIndex(vector<int> &citations) { return Solution2(citations); }
};
