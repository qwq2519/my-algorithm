#include <bits/stdc++.h>
using namespace std;

long long calc(long long n) {
    int ans = 0;
    for (long long i = 1; i * i < n; i++) {
        if (n % i == 0 && n % (i + 1) == 0) {
            ++ans;
        }
    }
    return ans;
}

int main() {
    int T;
    long long n;
    cin >> T;
    while (T--) {
        cin >> n;
        cout << calc(n) << endl;
    }

    return 0;
    // cin >> T;
    // for (int i = 1; i <= 10000; i++) {
    //     int x = calc(i);
    //     if (x == 4)
    //         cout << i << ":" << calc(i) << endl;
    // }
}
// 64 位输出请用 printf("%lld")
