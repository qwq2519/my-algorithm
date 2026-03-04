#include <climits>
#include <iostream>
using namespace std;
const int N = 107;
const int M = 1e9 + 7;
const int V = N * 1e3;
// 空间 >> 价值 , f[i] 表示价值为i的最小重量
long long f[V];
int w[N], v[N];

int n, W;

int main() {

    cin >> n >> W;
    int sumV = 0;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
        sumV += v[i];
    }

    int ans = INT_MIN;
    fill(f, f + V, INT_MAX);
    f[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = sumV; j >= v[i]; j--) {
            f[j] = min(f[j], f[j - v[i]] + w[i]);
        }
    }

    for (int j = 0; j <= sumV; j++)
        if (f[j] <= W)
            ans = j;

    cout << ans;
}
