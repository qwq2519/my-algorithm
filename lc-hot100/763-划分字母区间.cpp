class Solution {
public:
  vector<int> partitionLabels(string s) { return Solution2(s); }

  vector<int> Solution1(string s) {
    vector<pair<int, int>> interval;
    for (char c = 'a'; c <= 'z'; c++) {
      int first = s.find(c);
      int second = s.rfind(c);
      if (first != string::npos) {
        interval.push_back({first, second});
      }
    }

    struct cmp {
      bool operator()(pair<int, int> &a, pair<int, int> &b) {
        if (a.first == b.first)
          return a.second > b.second;
        return a.first < b.first;
      }
    };

    sort(interval.begin(), interval.end(), cmp{});
    vector<int> ans;

    auto [L, R] = interval[0];

    for (int i = 1; i < interval.size(); i++) {
      auto [l, r] = interval[i];
      if (l <= R) {
        R = max(r, R);
      } else {
        ans.push_back(R - L + 1);
        L = l;
        R = r;
      }
    }
    ans.push_back(R - L + 1);
    return ans;
  }

  vector<int> Solution2(string s) {
    vector<int> last(26, -1);
    for (int i = 0; i < s.size(); i++) {
      last[s[i] - 'a'] = i;
    }

    vector<int> ans;
    int l = 0, r = 0;
    for (int i = 0; i < s.size(); i++) {
      r = max(r, last[s[i] - 'a']);
      if (i == r) {
        ans.push_back(r - l + 1);
        s = i + 1;
      }
    }
    return ans;
  }
};
