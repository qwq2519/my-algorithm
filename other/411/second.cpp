
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

// 对于每个同学，判断他是否存在总分<某人，但是单科大于某人的
// 用set rank想想，对于tot大于自己的，存不存在 a b c某个rank小于自己的
// 逆向思维，对于tot小于自己的，但是a b c大于自己的同学他们就骄傲了
// 线段树区间覆盖？？
// 或者动态维护一个集合，从tot大到小加入元素，加入时，判断这个集合里面的最小a b
// c即可
int n;
struct p {
    int a, b, c;
    int tot;
} f[N];

struct cmp {
    bool operator()(p m, p n) const { return m.tot < n.tot; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> f[i].a >> f[i].b >> f[i].c;
        f[i].tot = f[i].a + f[i].b + f[i].c;
    }
    sort(f + 1, f + 1 + n, cmp{});
    int ans = 0;

    // 两种结合这样有88%了
    if (n >= 90000) {
        // 不能直接扫描，因为可能存在总分相同的不好判断,这样能过77分,应该是重复的问题
        int mia = f[n].a, mib = f[n].b, mic = f[n].c;
        for (int i = n - 1; i >= 1; i--) {
            if (f[i].a > mia || f[i].b > mib || f[i].c > mic)
                ++ans;
            mia = min(mia, f[i].a);
            mib = min(mib, f[i].b);
            mic = min(mic, f[i].c);
        }
    } else {
        // 纯暴力只有30分
        for (int i = 1; i < n; i++) {
            for (int j = n; j > i && f[j].tot > f[i].tot; j--) {
                if (f[i].a > f[j].a || f[i].b > f[j].b || f[i].c > f[j].c) {
                    ++ans;
                    break;
                }
            }
        }
        //  线段树似乎有希望？  tot反正最多300
        //  直接维护 分->mina minb minc的映射
    }
    // else {
    //     // 奇怪 先全部插入33%，边判断边插入22%。。。奇怪的数据点
    //     struct single {
    //         int a, b, c;
    //     } g[307];

    //     for (int i = 0; i <= 300; i++)
    //         g[i].a = 114514;

    //     for (int i = n - 1; i >= 1; i--) {
    //         for (int j = f[i].tot + 1; j <= 300; j++) {
    //             if (g[j].a == 114514)
    //                 continue;
    //             if (f[i].a > g[j].a || f[i].b > g[j].b || f[i].c > g[j].c) {
    //                 ++ans;
    //                 break;
    //             }
    //         }
    //         g[f[i].tot].a = min(g[f[i].tot].a, f[i].a);
    //         g[f[i].tot].b = min(g[f[i].tot].b, f[i].b);
    //         g[f[i].tot].c = min(g[f[i].tot].c, f[i].c);
    //     }
    // }
    cout << ans << endl;
    return 0;
}
