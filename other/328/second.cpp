#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
long long ans;
long long a[N], n;
long long f[N][2]; // f[i][0]以i为结尾为负数的  f[i][1] 以i为结尾为正数的
const long long MMM = -2147483667797;
int main() {
    int T;
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        // 要求保持相对顺序，不能排序
        f[1][0] = MMM;
        f[1][1] = a[1];
        f[2][1] = a[2];
        f[2][0] = a[1] - a[2];

        ans = max({ans, f[1][1], f[1][0], f[2][1], f[2][0]});
        ans = max(ans, f[1][1]);
        for (int i = 3; i <= n; i++) {
            f[i][1] = f[i - 1][0] + a[i];
            f[i][0] = f[i - 1][1] - a[i];
            ans = max(ans, f[i][1]);
            ans = max(ans, f[i][0]);
            ans = max(ans, a[i]);
        }

        cout << ans << '\n';
    }
    return 0;
}
