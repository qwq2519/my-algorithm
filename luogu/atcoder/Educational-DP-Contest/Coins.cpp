#include <iomanip>
#include <iostream>
using namespace std;
const int N = 3e3 + 7;
int n;
double p[N];
double f[N][N]; // 一共有2^n集合，  f_i_j表示前i个，j个朝上
double dp[N];

// 空间优化
void Solution2() {
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= 1; j--) {
            dp[j] = dp[j] * (1 - p[i]) + dp[j - 1] * p[i];
        }
        dp[0] = dp[0] * (1 - p[i]);
    }

    double ans = 0;
    for (int i = n / 2 + 1; i <= n; i++)
        ans += dp[i];

    // 默认6位，精度不够
    cout << fixed << setprecision(9) << ans;
}

int main() {

    // 正面朝上》反面朝上的概率

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    Solution2();
    return 0;

    f[0][0] = 1; // 0个硬币，0个正面
    for (int j = 1; j <= n; j++)
        f[0][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            f[i][j] += f[i - 1][j] * (1 - p[i]);
            if (j > 0)
                f[i][j] += f[i - 1][j - 1] * p[i];
        }
    }

    double ans = 0;
    for (int i = n / 2 + 1; i <= n; i++)
        ans += f[n][i];

    // 默认6位，精度不够
    cout << fixed << setprecision(9) << ans;
}
