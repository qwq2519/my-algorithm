#include <algorithm>
#include <bits/stdc++.h>
#include <random>
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int N = 17;

// 并行编译
// n只有10，可以直接暴力吗？

//  将dag划分为多个链条吗
//  怎么划分啊，感觉还是直接模拟吧
//  n很小，感觉可以试试暴力模拟，或者随机化
int n, k;
int a[N];
int ans;
vector<int> to[N];
int indegree[N];
vector<int> t;
unordered_map<int, int> m; // node: 顺序

// 暴力思路，把祖先依赖全存起来
unordered_set<int> dependency[N];

void topsort() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!indegree[i])
            q.push(i);
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        t.push_back(x);
        m[x] = t.size();
        for (auto y : to[x]) {
            --indegree[y];

            for (auto it : dependency[x])
                dependency[y].insert(it);
            if (!indegree[y])
                q.push(y);
        }
    }
}
void printdenpendency() {
    for (int i = 1; i <= n; i++) {
        cout << i << "的祖先依赖有: ";
        for (auto it : dependency[i]) {
            cout << it << ' ';
        }
        cout << endl;
    }
}

bool check(vector<int> order) {
    int siz = order.size();
    if (siz == 0)
        return true;
    for (int i = 0; i < siz - 1; i++) {
        for (int j = i + 1; j < siz; j++) {
            int x = order[i];
            int y = order[j];
            // 后面的节点是前面节点的祖宗，死锁
            if (dependency[x].find(y) != dependency[x].end()) {
                return false;
            }
        }
    }
    return true;
}

// 对于任意一个编译顺序，要保证符合拓扑排序
int calc(vector<int> first, vector<int> second) {
    // 只要检查单个线程的就行了，两个线程独立，大不了等待另一个全部完成
    if (!check(first) || !check(second))
        return -1;

    size_t firstLen = first.size();
    size_t secondLen = second.size();
    int F = 0, S = 0; // 双指针，表示各自的进度
    int res = 0;
    int now = 0;                     // 0在1线程上，1在2线程上
    unordered_map<int, int> cost(N); // i -> i_cost
    bool change2 = false;
    int tot = 0;
    // cout << "fucksss";
    while (1) {
        if (F == firstLen && S == secondLen)
            break;
        if ((now == 0 && F == firstLen) || (now == 1 && S == secondLen)) {
            if (change2) {
                return -1;
            }
            now = 1 - now;
            change2 = true;
            continue;
        }

        int cur;
        if (now == 0) {
            // cout << "First!!!" << F << endl;
            cur = first[F];
        } else {
            // cout << "Second!!!" << S << endl;
            cur = second[S];
        }
        bool change = false;
        int mx = 0;
        // cout << "fuckcur" << cur << endl;
        for (auto zuzong : dependency[cur]) {
            if (cost.find(zuzong) == cost.end()) {
                change = true;
                break;
            } else {
                mx = max(mx, cost[zuzong]);
            }
        }

        if (change) {
            if (change2) {
                return -1;
            }
            now = 1 - now;
            change2 = true;
        } else {
            res = max(res, mx + a[cur]);
            cost[cur] = mx + a[cur];
            ++tot;
            if (tot == n) {
                return res;
            }
            if (now == 0) {
                ++F;
                // cout << "ERROR F " << F << endl;
            } else {
                ++S;
                // cout << "ERROR S " << S << endl;
            }
            change2 = false;
        }
        // cout << now << ' ' << cur << ' ' << mx << ' ' << a[cur] <<
        // "\n\n\n\n";
    }
    return res;
}

void print(vector<int> v, vector<int> vv) {
    for (auto i : v) {
        cout << i << ' ';
    }
    cout << endl;
    for (auto i : vv) {
        cout << i << ' ';
    }
    cout << endl << endl;
}
mt19937 rng(time(0));
void randans(vector<int> v, vector<int> vv) {

    for (int i = 1; i <= 10; i++) {
        shuffle(v.begin(), v.end(), rng);
        shuffle(vv.begin(), vv.end(), rng);
        int t = calc(v, vv);
        if (t != -1)
            ans = min(ans, t);
    }
}

void dfs2(int x, vector<int> &sss, vector<vector<int>> &ans) {
    if (x == sss.size()) {
        ans.push_back(sss);
        return;
    }
    for (int i = x + 1; i < sss.size(); i++) {
        swap(sss[x], sss[i]);
        dfs2(x + 1, sss, ans);
        swap(sss[x], sss[i]);
    }
}

void dfs(int x, vector<int> &v, vector<int> &vv) {
    if (x == n + 1) {
        randans(v, vv);

        vector<vector<int>> O, OO;
        dfs2(0, v, O);
        dfs2(0, vv, OO);
        for (auto &i : O)
            for (auto &j : OO) {
                int t = calc(i, j);
                if (t != -1)
                    ans = min(ans, t);
            }
        return;
    }
    v.push_back(x);
    dfs(x + 1, v, vv);
    v.pop_back();
    vv.push_back(x);
    dfs(x + 1, v, vv);
    vv.pop_back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i], ans += a[i];
        dependency[i].insert(i);
    }
    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        to[y].push_back(x);
        indegree[x]++;
    }
    topsort();

    for (int i = 1; i <= n; i++) {
        dependency[i].erase(i);
    }
    // printdenpendency();

    if (t.size() != n) {
        cout << -1;
        return 0;
    }

    // cout << calc({1, 2, 3}, {0}) << endl;
    // cout << "TTTTTTTTTTTTTTTT" << endl;
    // cout << calc({4, 2, 1}, {3}) << endl;
    // return 0;
    // cout << calc({3, 2, 1}, {0}) << endl;
    vector<int> v;
    vector<int> vv;
    dfs(1, v, vv);
    cout << ans << '\n';
    return 0;
}
