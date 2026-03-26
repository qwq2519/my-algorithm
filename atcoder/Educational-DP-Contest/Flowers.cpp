#include <iostream>
using namespace std;
const int N = 2e5 + 7;
long long f[N];
int n;
int a[N], h[N];

int cnt = 0;
int lc[N << 2], rc[N << 2];
long long mx[N << 2];
int root;

void pushup(int p) {
    long long k(0);
    if (lc[p])
        k = max(k, mx[lc[p]]);
    if (rc[p])
        k = max(k, mx[rc[p]]);
    mx[p] = k;
}

void update(int &p, int l, int r, int pos, long long val) {
    if (!p)
        p = ++cnt;
    if (l == r) {
        mx[p] = max(mx[p], val);
        return;
    }
    int mid((l + r) >> 1);
    if (pos <= mid)
        update(lc[p], l, mid, pos, val);
    else
        update(rc[p], mid + 1, r, pos, val);
    pushup(p);
}

long long query(int p, int L, int R, int ll, int rr) {
    if (!p)
        return 0;
    if (ll <= L && R <= rr) {
        return mx[p];
    }
    int mid(L + R >> 1);
    long long mx = 0;
    if (ll <= mid)
        mx = max(mx, query(lc[p], L, mid, ll, rr));
    if (rr > mid)
        mx = max(mx, query(rc[p], mid + 1, R, ll, rr));
    return mx;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // h[i]是比较小的，<=N，如果很大

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        long long best = 0;
        if (h[i] > 1)
            best = max(best, query(root, 1, N, 1, h[i] - 1));
        f[i] = best + a[i];
        ans = max(ans, f[i]);
        update(root, 1, N, h[i], f[i]);
    }
    cout << ans;
}
void Solution1() {
    long long ans = 0;
    // f[i], 以h[i]元素为结尾的最长上升子序列的最大值
    for (int i = 1; i <= n; i++) {
        f[i] = a[i];
        for (int j = 1; j < i; j++) {
            if (h[j] < h[i]) {
                f[i] = max(f[i], f[j] + a[i]);
            }
        }
        ans = max(ans, f[i]);
    }
    cout << ans;
}
