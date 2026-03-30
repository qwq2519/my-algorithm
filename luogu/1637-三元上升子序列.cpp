#include <bits/stdc++.h>
using namespace std;
const int N = 3e4 + 7;
const int M = 1e5 + 7;

int sum[M << 2];
void insert(int p, int L, int R, int pos) {
    if (L == R) {
        sum[p]++;
        return;
    }
    int mid((L + R) >> 1);
    if (pos <= mid)
        insert(p << 1, L, mid, pos);
    else
        insert(p << 1 | 1, mid + 1, R, pos);
    sum[p] = sum[p << 1 | 1] + sum[p << 1];
}

int query(int p, int L, int R, int ll, int rr) {
    if (ll <= L && rr >= R) {
        return sum[p];
    }
    int mid((L + R) >> 1);
    int ans = 0;
    if (ll <= mid)
        ans += query(p << 1, L, mid, ll, rr);
    if (rr > mid)
        ans += query(p << 1 | 1, mid + 1, R, ll, rr);
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
            pre[i] = query(1, 1, M, l, r);
        insert(1, 1, M, a[i]);
    }
    memset(sum, 0, sizeof sum);

    vector<int> suf(n + 3, 0);
    for (int i = n; i >= 1; i--) {
        int l = a[i] + 1, r = M;
        suf[i] = query(1, 1, M, l, r);
        insert(1, 1, M, a[i]);
    }

    long long ans = 0;
    for (int i = 2; i < n; i++) {
        ans += suf[i] * pre[i];
    }
    cout << ans << endl;
    return 0;
}
