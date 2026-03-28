#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int n;
int a[N];
long long ans = 0;
//
// int mx[N << 2];
//
// void build(int p, int L, int R) {
//     if (L == R) {
//         mx[p] = a[L];
//         return;
//     }
//     int mid((L + R) >> 1);
//     build(p << 1, L, mid);
//     build(p << 1 | 1, mid + 1, R);
//     mx[p] = max(mx[p << 1], mx[p << 1 | 1]);
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int l = 1; l < n; l++) {
        int mx = a[l];
        int r = l + 1;
        while (r <= n) {
            mx = max(mx, a[r]);
            if (a[l] + a[r] > mx)
                ++ans;
            ++r;
        }
    }
    cout << ans << endl;
    return 0;
}
