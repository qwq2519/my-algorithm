#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<short>> ans;
vector<char> v;
vector<short> num;
void dfs(int x) {
    if (x == n + 1) {
        ans.push_back(num);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (x != 1 && (abs(i - num[x - 1]) == 1 || v[i] == 1))
            continue;
        v[i] = 1;
        num[x] = i;
        dfs(x + 1);
        num[x] = 0;
        v[i] = 0;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    num = vector<short>(n + 1);
    v = vector<char>(n + 1);

    dfs(1);

    sort(ans.begin(), ans.end());
    for (auto &it : ans) {
        for (int i = 1; i <= n; i++) {
            cout << it[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
