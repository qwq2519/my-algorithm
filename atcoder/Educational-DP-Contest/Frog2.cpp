
#include <climits>
#include <iostream>
using namespace std;
const int N = 1e5 + 7;
int n, k;
long long f[N]; // f[i]表示跳到第i阶台阶的最低代价
int h[N];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> h[i];

    fill(f + 1, f + n + 2, INT_MAX);
    f[1] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i + j > n)
                continue;
            f[i + j] = min(f[i + j], f[i] + abs(h[i] - h[i + j]));
        }
    }
    cout << f[n];
}
