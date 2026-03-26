#include <iostream>
using namespace std;
const int N = 107;
const int M = 1e5 + 7;
long long f[M];
int w[N], v[N];

int n, W;

int main() {

    cin >> n >> W;
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];

    for (int i = 1; i <= n; i++) {
        for (int j = W; j >= w[i]; j--) {
            f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
    }

    cout << f[W];
}
