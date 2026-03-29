#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int n;
int a[N], b[N];
string s;
pair<char, int> c[N];

string t;
long long sum = 0;

void dfs(int x) {
    if (x == n) {
        string str = "";
        str.reserve(sum);

        for (int i = 0; i < n; i++) {
            string astr = string(a[i], s[i]);
            str.append(astr);
        }

        if (t == "" || str < t) {
            for (int i = 0; i < n; i++)
                b[i] = a[i];
            t = str;
        }
        return;
    }
    for (int i = x; i < n; i++) {
        swap(a[i], a[x]);
        dfs(x + 1);
        swap(a[i], a[x]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s;
        sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        t = "";
        dfs(0);
        for (int i = 0; i < n; i++)
            cout << b[i] << ' ';
        cout << endl;
    }
    return 0;
}
