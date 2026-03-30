#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int M = 1e7 + 7;
int sum[N * 30], lc[N * 30], rc[N * 30];
int cnt = 0;
int root;

void insert(int &p, int L, int R, int pos, int val) {
    if (!p)
        p = ++cnt;
    if (L == R) {
        sum[p] += val;
        return;
    }
    int mid((L + R) >> 1);
    if (pos <= mid)
        insert(lc[p], L, mid, pos, val);
    else
        insert(rc[p], mid + 1, R, pos, val);
    sum[p] = sum[lc[p]] + sum[rc[p]];
}

int query(int p, int L, int R, int ll, int rr) {
    if (!p)
        return 0;
    if (ll <= L && rr >= R) {
        return sum[p];
    }
    int mid((L + R) >> 1);
    int ans = 0;
    if (ll <= mid)
        ans += query(lc[p], L, mid, ll, rr);
    if (rr > mid)
        ans += query(rc[p], mid + 1, R, ll, rr);
    return ans;
}

int kth(int p, int L, int R, int k) {
    if (L == R) {
        return L;
    }
    int mid((L + R) >> 1);
    if (sum[lc[p]] >= k)
        return kth(lc[p], L, mid, k);
    return kth(rc[p], mid + 1, R, k - sum[lc[p]]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int op, x;
    while (n--) {
        cin >> op >> x;
        if (op == 1) {
            insert(root, -M, M, x, 1);
        } else if (op == 2) {
            insert(root, -M, M, x, -1);
        } else if (op == 3) {
            cout << query(root, -M, M, -M, x - 1) + 1 << '\n';
        } else if (op == 4) {
            cout << kth(root, -M, M, x) << '\n';
        } else if (op == 5) {
            cout << kth(root, -M, M, query(root, -M, M, -M, x - 1)) << '\n';
        } else {
            cout << kth(root, -M, M, query(root, -M, M, -M, x) + 1) << '\n';
        }
    }

    return 0;
}
