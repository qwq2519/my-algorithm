#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;
int n;
vector<int> v[N];
long long f[N][2]; // 0 白色 1黑色

void dfs(int p, int fa) {
    f[p][0] = f[p][1] = 1;
    for (auto son : v[p]) {
        if (son == fa)
            continue;
        dfs(son, p);
        f[p][0] = f[p][0] * (f[son][0] + f[son][1]) % MOD;
        f[p][1] = f[p][1] * f[son][0] % MOD;
    }
}

int main() {
    cin >> n;
    int x, y;
    for (int i = 1; i <= n - 1; i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, -1);
    cout << (f[1][0] + f[1][1]) % MOD;
}
