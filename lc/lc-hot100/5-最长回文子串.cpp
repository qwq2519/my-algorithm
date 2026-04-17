class Solution {

    void check(string &s, int l, int r, int &mLen, string &ansStr) {
        int n = s.size();
        while (l >= 0 && r < n && s[l] == s[r]) {
            l--;
            r++;
        }
        int curlen = (r - 1) - (l + 1) + 1;
        if (curlen > mLen) {
            mLen = curlen;
            ansStr = s.substr(l + 1, mLen);
        }
    }

    string Solution1(string s) {
        int n = s.size();
        int len = 0;
        string str = "";
        for (int i = 0; i < n; i++) {
            check(s, i, i, len, str);
            check(s, i, i + 1, len, str);
        }
        return str;
    }

    string Solution2(string s) {
        int n = s.size();
        vector<vector<char>> f(
            n, vector<char>(n, 0)); // f[i][j] 表示i...j是否为回文

        int mLen = 0;
        string str = "";

        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && (len <= 2 || f[i + 1][j - 1])) {
                    f[i][j] = 1;
                    if (mLen < len) {
                        mLen = len;
                        str = s.substr(i, len);
                    }
                }
            }
        }
        return str;
    }

  public:
    string longestPalindrome(string s) { return Solution2(s); }
};
