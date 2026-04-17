#include <ios>
class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    // return Solution1(nums, k);
    return Solution2(nums, k);
  }

  vector<int> Solution1(vector<int> &a, int k) {
    unordered_map<int, int> m;
    for (auto it : a) {
      m[it]++;
    }

    struct cmp {
      bool operator()(pair<int, int> &p1, pair<int, int> &p2) const {
        return p1.first > p2.first;
      }
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>
        q; // count:number;

    for (auto [number, count] : m) {
      q.push({count, number});
      if (q.size() > k) {
        q.pop();
      }
    }

    vector<int> ans;
    while (!q.empty()) {
      auto [count, number] = q.top();
      q.pop();
      ans.push_back(number);
    }
    return ans;
  }

  vector<int> Solution2(vector<int> &nums, int k) {
    unordered_map<int, int> m;
    for (auto it : nums) {
      m[it]++;
    }
    vector<pair<int, int>> a;
    for (auto &it : m) {
      a.push_back(it);
    }
    srand(time(0));
    sort(a, 0, a.size() - 1, k);

    vector<int> ans;
    int n = a.size();
    for (int i = n - 1; i >= n - k; i--) {
      ans.push_back(a[i].first);
    }
    return ans;
  }

  void sort(vector<pair<int, int>> &a, int l, int r, int cnt) {
    // first number second count
    if (l >= r)
      return;
    swap(a[l], a[l + rand() % (r - l + 1)]);
    auto pivot = a[l];
    int i = l, j = r;
    int k = l + 1;
    while (k <= j) {
      if (a[k].second < pivot.second) {
        swap(a[k++], a[i++]);
      } else if (a[k].second > pivot.second) {
        swap(a[k], a[j--]);
      } else {
        k++;
      }
    }
    int rightcnt = r - j;
    int mid = j - i + 1;
    if (cnt <= rightcnt) {
      sort(a, j + 1, r, cnt);
    } else if (cnt <= rightcnt + mid) {
      return;
    } else {
      sort(a, l, i - 1, cnt - mid - rightcnt);
    }
  }
};
