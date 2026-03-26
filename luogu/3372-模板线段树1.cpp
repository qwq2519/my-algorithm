#include <bits/stdc++.h>
using namespace std;

char gt() {
    static char buf[1 << 21];
    static char *p1 = buf, *p2 = buf;
    if (p1 == p2) {
        p1 = buf;
        p2 = buf + fread(buf, 1, 1 << 21, stdin);
        if (p1 == p2)
            return EOF;
    }
    return *p1++;
}

template <typename T> void read(T &x) {
    char ch = gt();
    x = 0;
    int w(0);
    while (!(ch >= '0' && ch <= '9'))
        w |= ch == '-', ch = gt();
    while (ch >= '0' && ch <= '9')
        x = x * 10 + (ch - '0'), ch = gt();
    if (w)
        x = -x;
}
template <typename T> void out(T x, char cc) {
    if (x < 0)
        x = -x, putchar('-');
    char ch[20];
    int num = 0;
    while (x || !num)
        ch[++num] = x % 10 + '0', x /= 10;
    while (num)
        putchar(ch[num--]);
    putchar(cc);
}

const int N = 1e5 + 7;
int cnt = 0, root = 0;
int lc[N << 2], rc[N << 2];
long long sum[N << 2], tag[N << 2];

void apply(int &p, int l, int r, long long v) {
    if (!p)
        p = ++cnt;
    sum[p] += (r - l + 1) * v;
    tag[p] += v;
}

void pushdown(int p, int l, int r) {
    if (!tag[p])
        return;

    int mid = (l + r) >> 1;
    apply(lc[p], l, mid, tag[p]);
    apply(rc[p], mid + 1, r, tag[p]);
    tag[p] = 0;
}

void insert(int &p, int L, int R, int ll, int rr, long long val) {
    if (!p)
        p = ++cnt;
    if (ll <= L && rr >= R) {
        apply(p, L, R, val);
        return;
    }
    pushdown(p, L, R);
    int mid = (L + R) >> 1;
    if (ll <= mid)
        insert(lc[p], L, mid, ll, rr, val);
    if (rr > mid)
        insert(rc[p], mid + 1, R, ll, rr, val);
    sum[p] = sum[lc[p]] + sum[rc[p]];
}

long long query(int p, int L, int R, int ll, int rr) {
    if (!p)
        return 0;

    if (ll <= L && rr >= R) {
        return sum[p];
    }

    pushdown(p, L, R);
    int mid((L + R) >> 1);
    long long ans = 0;
    if (ll <= mid)
        ans += query(lc[p], L, mid, ll, rr);
    if (rr > mid)
        ans += query(rc[p], mid + 1, R, ll, rr);
    return ans;
}

int n, m;

int main() {
    read(n);
    read(m);

    long long a;
    for (int i = 1; i <= n; i++) {
        read(a);
        insert(root, 1, n, i, i, a);
    }

    int op, x, y;
    long long k;
    while (m--) {
        read(op);
        read(x);
        read(y);
        if (op == 1) {
            read(k);
            insert(root, 1, n, x, y, k);
        } else {
            out(query(root, 1, n, x, y), '\n');
        }
    }
    return 0;
}
