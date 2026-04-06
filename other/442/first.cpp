#include <bits/stdc++.h>
using namespace std;

void calc(long long x) {
    int ans = 0;
    for (long long i = 1; i * i <= x; i++) {
        if (x % i == 0 && x % (i + 1) == 0) {
            ++ans;
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        calc(n);
    }
    return 0;
}
