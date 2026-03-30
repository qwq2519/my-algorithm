#include <bits/stdc++.h>
using namespace std;
const int N = 3e4 + 7;
const int M = 1e5 + 7;

int c[M + 59];
int lowbit(int x) { return x & (-x); }

void add(int x, int v) {
    for (int i(x); i <= M; i += lowbit(i))
        c[i] += v;
}

int query(int x) {
    int ans = 0;
    for (int i(x); i; i -= lowbit(i))
        ans += c[i];
    return ans;
}

int n;
int a[N];
long long f[4][N]; // f[i][j]表示长度为i，以a[j]结尾的个数
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], f[1][i] = 1;

    for (int i = 2; i <= 3; i++) {
        memset(c, 0, sizeof c);
        for (int j = 1; j <= n; j++) {
            f[i][j] = query(a[j] - 1); // f[i][j] = sum f[i-1][k] k<j&&a[k]<a[j]
            add(a[j], f[i - 1][j]);
        }
    }

    long long ans = 0;
    for (int i = 3; i <= n; i++) {
        ans += f[3][i];
    }
    cout << ans << endl;

    return 0;
}
