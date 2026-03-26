#include <iostream>
using namespace std;
const int N = 507;
int n;
int a[N];
long long f[N][N], sum[N];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], sum[i] = sum[i - 1] + a[i];

    fill(&f[0][0], &f[0][0] + N * N, 1e13);
    for (int i = 1; i <= n; i++)
        f[i][i] = 0;

    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            for (int k = l; k < r; ++k) { // l...k + k+1..r
                f[l][r] =
                    min(f[l][r], f[l][k] + f[k + 1][r] + sum[r] - sum[l - 1]);
            }
        }
    }
    cout << f[1][n];
}
