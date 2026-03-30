#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 7;
int L;
int n;
int a[N];
int main() {
    cin >> L >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);

    // 核心，相遇时不管，继续走，因为总时间是一样的
    // 经典的蚂蚁爬杆问题,相遇后，不管掉不掉头，所有蚂蚁位置集合还是一样的，因此可以当成穿过去了
    int mi = 0;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        mi = max(mi, min(L - a[i] + 1, a[i]));
        mx = max({mx, L - a[i] + 1, a[i]});
    }
    cout << mi << ' ' << mx << endl;
}
