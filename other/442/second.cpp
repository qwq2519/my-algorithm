#include <bits/stdc++.h>
using namespace std;
int n;
int x;
string str;

struct aaa {
    int val;
    string name;
    int idx;
};

struct cmp {
    bool operator()(aaa g, aaa t) {
        if (t.val == g.val) {
            return g.idx > t.idx;
        }
        return g.val < t.val;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    vector<aaa> list;
    for (int i = 1; i <= n; i++) {
        aaa t;
        cin >> t.name >> t.val;
        t.idx = i;
        list.emplace_back(t);
    }
    sort(list.begin(), list.end(), cmp{});
    cout << list.back().name << '\n';
    return 0;
}
