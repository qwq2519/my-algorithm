#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 7;
long long ans;
long long t[N], n, b, a, k;

char gt() {
    static char buf[1 << 21];
    static char *p1 = buf, *p2 = buf;
    if (p1 == p2) {
        p1 = buf;
        p2 = buf + fread(buf, 1, 1 << 21, stdin);
        if (p1 == p2)
            return EOF;
    }
    return *p1++;
}
template <typename T> void read(T &x) {
    x = 0;
    int w = 0;
    char ch = gt();
    while (!(ch >= '0' && ch <= '9'))
        w |= ch == '-', ch = gt();
    while (ch >= '0' && ch <= '9')
        x = x * 10 + (ch - '0'), ch = gt();
    if (w)
        x = -x;
}

void out(int x, char cc) {
    if (x < 0)
        x = -x, putchar('-');
    int num = 0;
    char ch[20];
    while (x || !num)
        ch[++num] = x % 10 + '0', x /= 10;
    while (num)
        putchar(ch[num--]);
    putchar(cc);
}

int main() {
    int T;
    read(T);
    // 用快读只对10  ，用cin对90  .。。。 最后把memset去掉a了  超时变成99ms
    //  输入的都是正整数
    //  减法没用，除法才有用
    //  k是正数，所以一定要用
    //  正数先除再减
    //  负数不用除
    while (T--) {
        memset(t, 0, sizeof t);
        ans = 0;
        read(n);
        read(a);
        read(b);
        read(k);
        for (int i = 1; i <= n; i++)
            read(t[i]);
        sort(t + 1, t + n + 1);
        for (int i = n; i >= 1; i--) {
            if (t[i] > 0 && a > 0) {
                t[i] /= 2;
                a--;
            }
            ans += t[i];
        }
        out(ans - b * k, '\n');
    }
    return 0;
}
