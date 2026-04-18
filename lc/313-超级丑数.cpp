#include <climits>
class Solution {
    int solution1(int n, vector<int> &primes) {
        vector<int> ans(n, {1});

        // value,primes[x],idx
        using T = tuple<long long, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        for (int i = 0; i < primes.size(); i++) {
            pq.push({primes[i], primes[i], 0});
        }

        for (int i = 1; i < n; i++) {
            ans[i] = get<0>(pq.top());
            // 相同答案的统一推进，相当于去重
            while (!pq.empty() && get<0>(pq.top()) == ans[i]) {
                auto [value, prime, idx] = pq.top();
                pq.pop();
                ++idx;
                pq.push({1ll * ans[idx] * prime, prime, idx});
            }
        }

        return ans[n - 1];
    }

    int solution2(int n, vector<int> &primes) {
        int m = primes.size();
        vector<int> ans(n);
        vector<int> idx(m, 0);
        ans[0] = 1;
        for (int i = 1; i < n; i++) {
            long long minn = LONG_LONG_MAX;
            for (int j = 0; j < m; j++)
                minn = min(minn, 1LL * ans[idx[j]] * primes[j]);
            ans[i] = minn;
            for (int j = 0; j < m; j++)
                if (minn == 1ll * ans[idx[j]] * primes[j]) {
                    ++idx[j];
                }
        }
        return ans[n - 1];
    }

  public:
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        return solution1(n, primes);
    }
};
