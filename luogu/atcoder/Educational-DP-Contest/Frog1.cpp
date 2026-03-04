#include <climits>
#include <iostream>
using namespace std;
const int N = 1e5 + 7;
int n;
long long f[N]; // f[i]表示跳到第i阶台阶的最低代价
int h[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> h[i];

    fill(f + 1, f + n + 2, INT_MAX);
    f[1] = 0;

    for (int i = 1; i < n; i++) {
        f[i + 1] = min(f[i + 1], f[i] + abs(h[i] - h[i + 1]));
        f[i + 2] = min(f[i + 2], f[i] + abs(h[i] - h[i + 2]));
    }
    cout << f[n];
}
