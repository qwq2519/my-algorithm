#include <iomanip>
#include <iostream>
using namespace std;
const int N = 307;
int n;
int a[N];
int t1, t2, t3;

// 不能按照第几个盘子做状态，盘子不重要，每次都是随机的，只和每种盘子还有多少有关。如果拿盘子做状态，那么状态数太多了
// 盘子上的寿司数量0，1，2，3
double f[N][N][N]; // i j k   有i个盘子有1个寿司 有j个盘子有2个寿司。。。
// 题意简化  给定n个[1,3]的数，每次随机减1，直到所有为0

// 记忆化递推 ,复杂状态方便,记忆化递推本质是在dag上做递推，总寿司数一定是下降的
bool vis[N][N][N];
double dfs(int i, int j, int k) {
    if (i == 0 && j == 0 && k == 0)
        return 0;
    if (vis[i][j][k])
        return f[i][j][k];
    int sum = i + j + k;
    f[i][j][k] = 1.0 * n / sum;
    if (i != 0)
        f[i][j][k] += 1.0 * i / sum * dfs(i - 1, j, k);
    if (j != 0)
        f[i][j][k] += 1.0 * j / sum * dfs(i + 1, j - 1, k);
    if (k != 0)
        f[i][j][k] += 1.0 * k / sum * dfs(i, j + 1, k - 1);
    vis[i][j][k] = 1;
    return f[i][j][k];
}

void Solution1() {

    f[0][0][0] = 0;
    // 三个变量的上界不能是t1 t2 t3，因为状态转移过程中
    // 某种盘子会增长，会导致突破上届，wa
    for (int k = 0; k <= n; k++)
        for (int j = 0; j <= n; j++)
            for (int i = 0; i <= n; i++) {
                if (i == 0 && j == 0 && k == 0)
                    continue;
                int sum = i + j + k;
                f[i][j][k] = 1.0 * n / sum;
                if (i != 0)
                    f[i][j][k] += 1.0 * i / sum * f[i - 1][j][k];
                if (j != 0)
                    f[i][j][k] += 1.0 * j / sum * f[i + 1][j - 1][k];
                if (k != 0)
                    f[i][j][k] += 1.0 * k / sum * f[i][j + 1][k - 1];
            }
}

void Solution2() {

    f[0][0][0] = 0;
    // 有一个很自然的分层状态，即总寿司数 S,三种盘子状态转移，本质是总寿司数
    // S-->S-1
    for (int s = 1; s <= n; s++) {
        for (int k = 0; k <= s; k++) {
            for (int j = 0; j + k <= s; j++) {
                int i = s - j - k;
                if (i < 0 || i > n || j > n || k > n)
                    continue;
                double sum = i + j + k;
                f[i][j][k] = 1.0 * n / sum;
                if (i > 0) {
                    f[i][j][k] += 1.0 * i / sum * f[i - 1][j][k];
                }
                if (j > 0) {
                    f[i][j][k] += 1.0 * j / sum * f[i + 1][j - 1][k];
                }
                if (k > 0) {
                    f[i][j][k] += 1.0 * k / sum * f[i][j + 1][k - 1];
                }
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        t1 += a[i] == 1;
        t2 += a[i] == 2;
        t3 += a[i] == 3;
    }

    // 1是本身这个操作要消耗的
    // f[i][j][k] =1+(n-i-j-k)/n*f[i][j][k]
    //              +i/n*f[i-1][j][k]
    //              +j/n*f[i+1][j-1][k]
    //              +k/n*f[i][j+1][k-1]

    //  f[i][j][k]=n/(i+j+k)  //先要命中非空盘，再进入下一阶段的选择是命中
    //  哪种非空盘
    //              +i/(i+j+k)f[i-1][j][k]
    //              +j/(i+j+k)f[i+1][j-1][k]
    //              +k/(i+j+k)f[i][j+1][k-1]
    //
    //              但是不能直接枚举i j k, 要k j i
    //              才符合无后效性,k是有明显单调性的

    // g    f[t1][t2][t3] = dfs(t1, t2, t3);
    Solution2();
    cout << fixed << setprecision(10) << f[t1][t2][t3];
}
