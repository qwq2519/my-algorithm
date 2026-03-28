#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 7;
long long ans;
long long t[N], n, b, a, k;

int main() {
    int T;
    cin >> T;
    // 输入的都是正整数
    // 减法没用，除法才有用
    // k是正数，所以一定要用
    // 正数先除再减
    // 负数不用除
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (T--) {
        memset(t, 0, sizeof t);
        ans = 0;
        cin >> n >> a >> b >> k;
        for (int i = 1; i <= n; i++)
            cin >> t[i];
        sort(t + 1, t + n + 1);
        for (int i = n; i >= 1; i--) {
            if (t[i] > 0 && a > 0) {
                t[i] /= 2;
                a--;
            }
            ans += t[i];
        }
        cout << ans - b * k << '\n';
    }
    return 0;
}
