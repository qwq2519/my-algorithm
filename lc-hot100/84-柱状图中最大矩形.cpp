class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();
    vector<int> left(n, -1); // 左边第一个小于
    vector<int> right(n, n); // 右边第一个小于
    stack<int> st;

    for (int i = 0; i < n; ++i) {
      while (!st.empty() && heights[i] <= heights[st.top()])
        st.pop();
      if (!st.empty())
        left[i] = st.top();
      st.push(i);
    }

    st = stack<int>();

    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() && heights[i] <= heights[st.top()])
        st.pop();
      if (!st.empty())
        right[i] = st.top();
      st.push(i);
    }

    // 左端：left[i] + 1
    // 右端：right[i] - 1
    // 宽度 = (right[i] - 1) - (left[i + 1]) + 1 = right[i] - left[i] - 1
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, heights[i] * (right[i] - left[i] - 1));
    }
    return ans;
  }
};
