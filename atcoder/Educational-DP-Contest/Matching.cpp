#include <iostream>
using namespace std;
const int N = 21;
const int MOD = 1e9 + 7;
const int MX = (1 << N) + 117;
int n, m;
int a[N][N];
int f[MX];

int popCount(int x) {
    int cnt = 0;
    while (x) {
        ++cnt;
        x = x & (x - 1);
    }
    return cnt;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    m = (1 << n) - 1; // n个1;

    f[0] = 1;

    // 闫式分析法，给暴力做法划分集合，dp计数就能合并暴力做法的重复子状态

    for (int i = 0; i < n;
         i++) { // 正在处理第i名男性,男性作为阶段,男女也可以对调。
        for (int s = 0; s <= m; ++s) { // 集合，哪些女性被选了
            if (popCount(s) != i)
                continue;
            for (int j = 0; j < n; j++) {
                if (((s & (1 << j)) == 0 && a[i][j])) {
                    f[s | (1 << j)] += f[s];
                    if (f[s | (1 << j)] > MOD)
                        f[s | (1 << j)] -= MOD;
                }
            }
        }
    }

    cout << f[m];
}
