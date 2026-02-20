class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
      if (a[0] != b[0]) {
        return a[0] < b[0];
      }
      return a[1] < b[1];
    });
    vector<vector<int>> ans;
    for (vector<int> it : intervals) {
      int l = it[0], r = it[1];
      if (ans.empty() || ans.back()[1] < l) {
        ans.push_back(it);
        continue;
      }
      if (l <= ans.back()[1] && r >= ans.back()[1]) {
        ans.back()[1] = r;
      }
    }
    return ans;
  }
};
