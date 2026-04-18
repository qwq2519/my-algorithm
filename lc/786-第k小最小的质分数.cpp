class Solution {

    vector<int> solution1(vector<int> &a, int k) {
        // 多路归并
        //(i,j) i路，j不断--
        using T = tuple<double, int, int>;
        priority_queue<T, vector<T>, greater<T>> q;
        for (int i = 0; i < a.size(); i++) {
            q.push({1.0 * a[i] / a[a.size() - 1], i, a.size() - 1});
        }

        k--;
        while (k--) {
            auto [val, i, j] = q.top();
            q.pop();
            j--;
            if (i < j)
                q.push({1.0 * a[i] / a[j], i, j});
        }
        return {a[get<1>(q.top())], a[get<2>(q.top())]};
    }

    int A, B;
    int check(double mid, vector<int> &a) {
        int l = 0;
        int ans = 0;
        for (int r = 0; r < a.size(); ++r) {
            while (l < r && 1.0 * a[l] / a[r] <= mid)
                l++;
            ans += l;
            if (l > 0)
                if (fabs(1.0 * a[l - 1] / a[r] - mid) < 1e-9) {
                    A = a[l - 1];
                    B = a[r];
                }
        }
        return ans;
    }

    vector<int> solution2(vector<int> &a, int k) {
        // 题意 a递增 (i,j) i<j,那么这个分数取值是在(0,1)
        // 可以二分答案

        double l = 0, r = 1;
        for (int i = 1; i <= 30; i++) {
            double mid((l + r) / 2.0);
            if (check(mid, a) >= k)
                r = mid;
            else
                l = mid;
        }
        return {A, B};
    }

  public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k) {
        return solution2(arr, k);
    }
};
