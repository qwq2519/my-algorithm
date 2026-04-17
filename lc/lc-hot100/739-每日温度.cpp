class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    return dailyTemperatures2(temperatures);
  }
  vector<int> dailyTemperatures1(vector<int> &temperatures) {
    int n = temperatures.size();
    stack<int> s; // 当前元素能当多久最大值
    vector<int> ans(n, 0);
    for (int i = 0; i < n; ++i) {
      while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
        ans[s.top()] = i - s.top();
        s.pop();
      }
      s.push(i);
    }
    return ans;
  }

  vector<int> dailyTemperatures2(vector<int> &temperatures) {
    int n = temperatures.size();
    stack<int> s;
    vector<int> ans(n, 0);
    for (int i = n - 1; i >= 0; i--) {
      while (!s.empty() && temperatures[s.top()] <= temperatures[i])
        s.pop();
      if (!s.empty())
        ans[i] = s.top() - i;
      s.push(i);
    }
    return ans;
  }
};
