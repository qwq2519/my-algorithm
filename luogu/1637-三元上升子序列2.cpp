#include <bits/stdc++.h>
using namespace std;
const int N = 3e4 + 7;
const int M = 1e5 + 7;

int c[M + 59];
int lowbit(int x) { return x & (-x); }

void add(int x) {
    for (int i(x); i <= M; i += lowbit(i))
        c[i] += 1;
}

int query(int x) {
    int ans = 0;
    for (int i(x); i; i -= lowbit(i))
        ans += c[i];
    return ans;
}

int n;
int a[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> pre(n + 3, 0);
    for (int i = 1; i <= n; i++) {
        int l = 1, r = a[i] - 1;
        if (l <= r)
            pre[i] = query(r) - query(l - 1);
        add(a[i]);
    }
    memset(c, 0, sizeof c);

    vector<int> suf(n + 3, 0);
    for (int i = n; i >= 1; i--) {
        int l = a[i] + 1, r = M;
        suf[i] = query(r) - query(l - 1);
        add(a[i]);
    }

    long long ans = 0;
    for (int i = 2; i < n; i++) {
        ans += suf[i] * pre[i];
    }
    cout << ans << endl;
    return 0;
}
