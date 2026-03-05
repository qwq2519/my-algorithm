#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 1e5 + 7;
int n, m;
int in[N];
vector<int> t, f;
vector<vector<int>> v;
void tuopu() {

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!in[i])
            q.push(i);
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        t.push_back(x);
        for (auto to : v[x]) {
            --in[to];
            if (!in[to])
                q.push(to);
        }
    }
}

int main() {
    cin >> n >> m;
    v = vector<vector<int>>(n + 1, vector<int>());

    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        in[y]++;
    }
    tuopu();

    int ans = 0;
    f = vector<int>(n + 1, 0);

    for (auto x : t) {
        for (auto y : v[x]) {
            f[y] = max(f[y], f[x] + 1);
        }
    }

    for (int i = 1; i <= n; i++)
        ans = max(ans, f[i]);
    cout << ans;
}
