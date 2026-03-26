#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();

    s = ' ' + s;
    t = ' ' + t;

    vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = max({f[i - 1][j], f[i][j - 1]});
            if (s[i] == t[j]) {
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            }
        }
    }

    string ans = "";
    int i = n, j = m;

    while (i > 0 && j > 0) {
        if (s[i] == t[j]) {
            ans = ans + s[i];
            i--;
            j--;
        } else {
            if (f[i][j] == f[i - 1][j]) {
                i--;
            } else {
                j--;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}
