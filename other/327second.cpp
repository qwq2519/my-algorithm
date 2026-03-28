#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

// 试试树的重心？
//  n=1e5  n log n ？     换根dp感觉不行，
vector<int> to[N], val[N];
int n, x, y, z;
int siz[N];
int dfn[N], cnt;

int heavy = -1;
int mx = -1;

void dfs(int x, int fa) {
    dfn[x] = ++cnt;
    siz[x] = 1;
    for (auto &v : to[x]) {
        if (v == fa)
            continue;
        dfs(v, x);
        siz[x] += siz[v];
    }
    if (siz[x] > n / 2 && n - siz[x] > n / 2) {
        heavy = x;
    }
}

int dep[N];
long long ans = 0;
void dfs2(int x, int fa, int d) {
    siz[x] = 1;
    dep[x] = d;
    for (int i = 0; i < to[x].size(); i++) {
        int v = to[x][i];
        int w = val[x][i];
        if (v == fa)
            continue;
        dfs2(v, x, d + 1);
        ans += 1ll * siz[v] * w;
        siz[x] += siz[v];
    }
}

int main() {
    cin >> n >> x >> y >> z;
    int u, v, w;
    for (int i = 1; i <= n - 1; i++) {
        cin >> u >> v >> w;
        to[u].push_back(v);
        to[v].push_back(u);
        val[u].push_back(w);
        val[v].push_back(v);
    }

    dfs(1, -1);

    cout << "重心" << heavy << endl;
    memset(siz, 0, sizeof siz);
    // 以重心为根，重新再来
    dfs2(heavy, -1, 1);
    if (heavy == x) {
        cout << ans << endl;
        return 0;
    }
}
