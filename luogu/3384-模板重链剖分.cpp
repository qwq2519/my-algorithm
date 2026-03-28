#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int n, m, r;
long long MOD;

vector<int> v[N];
int a[N];

int siz[N], dep[N], fa[N], hson[N];
int dfn[N], rnk[N], cnt, top[N];

void dfs1(int x, int F) {
    fa[x] = F;
    dep[x] = dep[F] + 1;
    siz[x] = 1;
    for (const auto &u : v[x]) {
        if (u == F)
            continue;
        dfs1(u, x);
        siz[x] += siz[u];
        if (siz[u] > siz[hson[x]])
            hson[x] = u;
    }
}

void dfs2(int x, int Ftop) {
    dfn[x] = ++cnt;
    rnk[cnt] = x;
    top[x] = Ftop;
    if (!hson[x])
        return;
    dfs2(hson[x], Ftop);
    for (const auto &u : v[x]) {
        if (dfn[u])
            continue;
        dfs2(u, u);
    }
}

long long sum[N << 2], tag[N << 2];

void build(int p, int L, int R) {
    if (L == R) {
        sum[p] = a[rnk[L]];
        return;
    }
    int mid((L + R) >> 1);
    build(p << 1, L, mid);
    build(p << 1 | 1, mid + 1, R);
    sum[p] = (sum[p << 1] + sum[p << 1 | 1]) % MOD;
}

void pushdown(int p, int L, int R) {
    if (!tag[p])
        return;
    tag[p << 1] = (tag[p << 1] + tag[p]) % MOD;
    tag[p << 1 | 1] = (tag[p << 1 | 1] + tag[p]) % MOD;
    int mid((L + R) >> 1);
    sum[p << 1] = (1ll * sum[p << 1] + 1ll * (mid - L + 1) * tag[p]) % MOD;
    sum[p << 1 | 1] = (1ll * sum[p << 1 | 1] + 1ll * (R - mid) * tag[p]) % MOD;
    tag[p] = 0;
}

void insert(int p, int L, int R, int ll, int rr, int val) {
    if (ll <= L && rr >= R) {
        sum[p] = (1ll * sum[p] + 1ll * (R - L + 1) * val) % MOD;
        tag[p] = (tag[p] + val) % MOD;
        return;
    }
    pushdown(p, L, R);
    int mid((L + R) >> 1);
    if (ll <= mid)
        insert(p << 1, L, mid, ll, rr, val);
    if (rr > mid)
        insert(p << 1 | 1, mid + 1, R, ll, rr, val);
    sum[p] = (sum[p << 1] + sum[p << 1 | 1]) % MOD;
}

long long query(int p, int L, int R, int ll, int rr) {
    if (ll <= L && rr >= R) {
        return sum[p];
    }
    pushdown(p, L, R);
    int mid((L + R) >> 1);
    long long res = 0;
    if (ll <= mid)
        res += query(p << 1, L, mid, ll, rr);
    if (rr > mid)
        res += query(p << 1 | 1, mid + 1, R, ll, rr);
    return res % MOD;
}

long long queryChain(int x, int y) {
    long long res = 0;

    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        res = (res + query(1, 1, n, dfn[top[x]], dfn[x])) % MOD;
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    res = (res + query(1, 1, n, dfn[x], dfn[y])) % MOD;

    return res;
}

void add(int x, int y, int val) {

    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        insert(1, 1, n, dfn[top[x]], dfn[x], val);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    insert(1, 1, n, dfn[x], dfn[y], val);
}

int main() {
    cin >> n >> m >> r >> MOD;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs1(r, 0);
    dfs2(r, r);

    build(1, 1, n);

    while (m--) {
        int op, x, y, z;
        cin >> op;
        if (op == 1) { // 路径上加
            cin >> x >> y >> z;
            add(x, y, z);
        } else if (op == 2) { // 求边和
            cin >> x >> y;
            cout << queryChain(x, y) << '\n';
        } else if (op == 3) { // 加子树
            cin >> x >> z;
            insert(1, 1, n, dfn[x], dfn[x] + siz[x] - 1, z);
        } else { // 求子树
            cin >> x;
            cout << query(1, 1, n, dfn[x], dfn[x] + siz[x] - 1) % MOD << '\n';
        }
    }
}
