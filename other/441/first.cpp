#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7;

int n, m;
char c[N][N];
int ans[N][N];
// L R U D
short d[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
int vis[N][N], ver;

int getDir(char x) {
    if (x == 'L')
        return 0;
    if (x == 'R')
        return 1;
    if (x == 'U')
        return 2;
    return 3;
}

int changedir(int x, char c) {
    if (c == '/') {
        if (x == 0)
            return 3;
        if (x == 1)
            return 2;
        if (x == 2)
            return 1;
        return 0;
    } else {
        if (x == 0)
            return 2;
        if (x == 1)
            return 3;
        if (x == 2)
            return 0;
        return 1;
    }
}
void dfs(int x, int y, int direction) {
    if (x < 1 || x > n || y < 1 || y > m || c[x][y] == '#')
        return;
    if (c[x][y] == 'L' || c[x][y] == 'R' || c[x][y] == 'U' || c[x][y] == 'D')
        return;
    if (vis[x][y] == ver)
        return;
    vis[x][y] = ver;
    if (c[x][y] == '.')
        ++ans[x][y];

    if (c[x][y] == '\\' || c[x][y] == '/') {
        direction = changedir(direction, c[x][y]);
    }

    dfs(x + d[direction][0], y + d[direction][1], direction);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // n*m <=1e4
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> c[i][j];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (c[i][j] == '#' || c[i][j] == '/' || c[i][j] == '\\') {
                ans[i][j] = -1;
                continue;
            }
            if (c[i][j] == '.')
                continue;
            ans[i][j] = -1;
            ++ver;
            // memset(vis, 0, sizeof vis);
            dfs(i, j, getDir(c[i][j]));
            vis[i][j] = ver;
            dfs(i + d[getDir(c[i][j])][0], j + d[getDir(c[i][j])][1],
                getDir(c[i][j]));
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << ans[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
