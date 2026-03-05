#include <iostream>
#include <string>
using namespace std;
const int N = 1007;
const int MOD = 1e9 + 7;

int n, h;
string m[N];
int f[N][N];

int main() {
    cin >> n >> h;
    for (int i = 1; i <= n; i++) {
        cin >> m[i];
        m[i] = ' ' + m[i];
    }

    f[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= h; j++) {
            if (m[i][j] == '#')
                continue;
            if (m[i - 1][j] == '.')
                f[i][j] = (f[i][j] + f[i - 1][j]) % MOD;
            if (m[i][j - 1] == '.')
                f[i][j] = (f[i][j] + f[i][j - 1]) % MOD;
        }
    }

    cout << f[n][h];
}
