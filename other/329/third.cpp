#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int n;
int a[N], b[N];
string s;
pair<char, int> c[N];

struct cmp {
    bool operator()(pair<char, int> a, pair<char, int> b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            c[i] = {s[i], i};
        }
        sort(a, a + n, greater<int>());
        sort(c, c + n);

        for (int i = 0; i < n; i++) {
            b[c[i].second] = a[i];
        }

        for (int i = 0; i < n - 1; i++)
            cout << b[i] << ' ';
        cout << b[n - 1] << '\n';
    }
    return 0;
}
