#include <bits/stdc++.h>
using namespace std;
// 最多100人

int t[107][131];

int calc() {
    int rnk = 1;
    int tot = 0;

    for (int j = 1; j <= 100; j++)
        tot += t[1][j];

    for (int i = 2; i <= 100; i++) {
        int res = 0;
        for (int j = 1; j <= 100; j++) {
            res += t[i][j];
        }
        if (res > tot)
            ++rnk;
    }
    return rnk;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a, b, c;
    while (n--) {
        cin >> a >> b >> c; // 用户a在b上获得了c分
        t[a][b] = max(t[a][b], c);
        cout << calc() << '\n';
    }
    return 0;
}
