#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
long long ans;
long long a[N], n;
long long f[N][2]; // f[i][0]以i为结尾为负数的  f[i][1] 以i为结尾为正数的
const long long MMM = -2147483667797;

void dfs(int x, long long sum, bool flag) {
    ans = max(ans, sum);
    if (x == n + 1)
        return;

    if (flag) {
        dfs(x + 1, sum + a[x], !flag);
        dfs(x + 1, sum, flag);
    } else {
        dfs(x + 1, sum - a[x], !flag);
        dfs(x + 1, sum, flag);
    }
}

void dfs2(int x, vector<int> &c) {
    if (x == n + 1) {
        bool flag = true;
        long long sum = 0;
        cout << "---";
        for (const auto &t : c) {
            cout << t << ' ';
            if (t)
                sum += t;
            else
                sum -= t;
            flag = !flag;
        }
        cout << endl;
        ans = max(ans, sum);
        return;
    }
    dfs2(x + 1, c);
    c.push_back(a[x]);
    dfs2(x + 1, c);
    c.pop_back();
}

int main() {
    int T;
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i], ans = max(ans, a[i]);
        vector<int> a;
        dfs2(1, a);
        cout << ans << '\n';
        continue;

        // 要求保持相对顺序，不能排序
        f[1][0] = MMM;
        f[1][1] = a[1];
        f[2][0] = a[1] - a[2];
        f[2][1] = a[2];

        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                f[i][1] = f[j][0] + a[i];
                f[i][0] = f[j][1] - a[i];
            }
            ans = max(ans, f[i][1]);
            ans = max(ans, f[i][0]);
        }

        cout << ans << '\n';
    }
    return 0;
}
