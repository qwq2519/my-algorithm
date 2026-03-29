#include <bits/stdc++.h>
#include <string>
#define println(x) cout << (x) << endl;
using namespace std;
long long a, b, n;
unordered_map<string, long long> m;
long long f(long long x, long long y) {
    string str = to_string(x) + '#' + to_string(y);
    auto it = m.find(str);
    if (it != m.end()) {
        return it->second;
    }
    long long ans = -1;
    if (x == y)
        ans = x + y;
    if (x - y == 1 || y - x == 1)
        ans = max(x, y);
    if (x == 1 || y == 1)
        ans = 2;
    if (ans != -1) {
        m[str] = ans;
        return ans;
    }
    ans = min(x, y) + __gcd(x, y);
    m[str] = ans;
    return ans;
}

pair<long long, long long> fn(long long x, long long y, long long n) {
    long long ans = f(x, y);
    for (int i = 1; i < n; i++) {
        long long t = f(ans, y);
        if (ans == t)
            return {ans, i + 1};
        else
            ans = t;
    }
    return {ans, n};
}

void test() {
    // for (int i = 1; i <= 10; i++) {
    //     for (int j = 1; j <= 10; j++) {
    //         cout << i << ' ' << j << ' ' << f(i, j) << endl;
    //     }
    // }
    // int g = fn(34, 57, 1);
    // int gg = fn(34, 57, 2);
    // int ggg = fn(34, 57, 4);
    // int gggg = fn(34, 57, 8);
    // int ggggg = fn(34, 57, 16);
    // println(g);
    // println(gg);
    // println(ggg);
    // println(gggg);
    // println(ggggg);
    // for (int i = 1; i <= 20; i++) {
    //     println(fn(273, 425, i));
    // }
    srand(time(0));
    for (int i = 1; i <= 1; i++) {
        int x = rand() % 101237 + 1;
        int y = rand() % 10213127 + 1;
        for (int z = 1; z <= 57; z++)
            cout << x << ' ' << y << "  gcd:" << __gcd(x, y) << ' ' << z << ' '
                 << fn(x, y, z).second << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    test();
    return 0;
    int T;
    cin >> T;
    while (T--) {
        cin >> a >> b >> n;
        cout << fn(a, b, n).first << '\n';
    }
    return 0;
}
