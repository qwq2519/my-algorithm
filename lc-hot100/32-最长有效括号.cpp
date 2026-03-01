class Solution {

    int Solution1(string s) {
        // 匹配的字符串必定是连续的，一段一段的。
        int ans = 0;
        stack<int> st; // 存上一个断点
        st.push(-1);

        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) { // 多出来的)不匹配,弹出断点了
                    st.push(i);
                } else {
                    ans = max(ans, i - st.top());
                }
            }
        }
        return ans;
    }

    int Solution2(string s) {
        // 最长连续子串，是连续的局部的，状态设置为以i为结尾的最长值，s[i]必须为)
        int n = s.size();
        vector<int> f(n, 0);
        int ans = 0;

        for (int i = 1; i < n; i++) {
            if (s[i] == '(')
                continue;
            if (s[i - 1] == '(')
                f[i] = 2 + (i >= 2 ? f[i - 2] : 0);
            else {
                int len = f[i - 1];
                int j = i - len - 1; // 寻找与s[i]相匹配的'('
                if (j >= 0 && s[j] == '(')
                    f[i] = len + 2 + (j >= 1 ? f[j - 1] : 0);
            }
            ans = max(ans, f[i]);
        }

        return ans;
    }

    int Solution3(string s) {
        int ans = 0;
        int l = 0;
        int r = 0;

        for (char c : s) {
            l += c == '(';
            r += c == ')';
            if (r > l)
                r = l = 0; // )太多了，前缀没用了
            if (l == r)
                ans = max(ans, l * 2);
        }

        l = r = 0;
        // 上面从左往右可能会漏掉(()

        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];
            l += c == '(';
            r += c == ')';
            if (l > r)
                r = l = 0; // )太多了，前缀没用了
            if (l == r)
                ans = max(ans, l * 2);
        }

        return ans;
    }

  public:
    int longestValidParentheses(string s) { return Solution2(s); }
};
