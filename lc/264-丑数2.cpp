class Solution {
#define int long long
    int heap(int n) {
        priority_queue<int, vector<int>, greater<int>> q;
        unordered_set<long long> m;
        m.insert(1);
        q.push(1);
        int x = 1;
        for (int i = 1; i <= n; i++) {
            x = q.top();
            q.pop();
            if (m.find(x * 2) == m.end()) {
                q.push(x * 2);
                m.insert(x * 2);
            }
            if (m.find(x * 3) == m.end()) {
                q.push(x * 3);
                m.insert(x * 3);
            }
            if (m.find(x * 5) == m.end()) {
                q.push(x * 5);
                m.insert(x * 5);
            }
        }
        return x;
    }
    int solution2(int n) {
        // 新的丑数都是旧的丑数扩展来的，pi可以代表旧丑数哪个有机会和i相乘
        //  相当于维护多个递增的数组，然后进行多路归并
        vector<int> v(1, 1);
        for (int cnt = 1, p2 = 0, p3 = 0, p5 = 0; cnt < n; ++cnt) {
            int a = v[p2] * 2;
            int b = v[p3] * 3;
            int c = v[p5] * 5;
            int mn = min({a, b, c});
            v.push_back(mn);
            if (mn == a)
                ++p2;
            if (mn == b)
                ++p3;
            if (mn == c)
                ++p5;
        }
        return v.back();
    }
#undef int
  public:
    int nthUglyNumber(int n) { return solution2(n); }
};
