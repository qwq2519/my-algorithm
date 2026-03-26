#include <iostream>
#include <vector>

using namespace std;
const int N = 107;
const int K = 1e5 + 7;
const int MOD = 1e9 + 7;
int n, k;
int a[N];

void Solution1() {

    // f[i][j] 第i个分 x (0--a[i])，那么前j个就要分j-x个 ，即 sum{ f[i-1][j-x] }
    //
    // int f[N][K]; // i j 前i个孩子分了j个
    // f[0][0] = 1;
    // // f[0][正数]=0
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j <= k; j++) {
    //         for (int x = 0; x <= min(j, a[i]); x++) { // 枚举第i个分多少
    //             f[i][j] += f[i - 1][j - x];
    //         }
    //     }
    // }
}

void Solution2() {
    vector<int> f(K);
    vector<int> pre(K);
    f[0] = 1;

    for (int i = 1; i <= n; i++) {
        pre[0] = f[0];
        for (int j = 1; j <= k; j++)
            pre[j] = (pre[j - 1] + f[j]) % MOD;

        for (int j = 0; j <= k; j++) {
            int l = j - a[i] - 1;
            if (l < 0) {
                f[j] = pre[j];
            } else {
                f[j] = (pre[j] - pre[l] + MOD) % MOD;
            }
        }
    }
    cout << f[k];
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    Solution2();
}
