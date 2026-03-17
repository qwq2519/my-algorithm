class Solution {

    int len;
    int n;

    string pusu(string s, int n) {
        vector<string> mp(n, "");
        int dir = 1;
        int p = 0;
        for (int i = 0; i < len; i++) {
            mp[p].push_back(s[i]);
            if (p == 0)
                dir = 1;
            else if (p == n - 1)
                dir = -1;
            p += dir;
        }
        string ans = "";
        for (int i = 0; i < n; i++) {
            ans += mp[i];
        }

        return ans;
    }

  public:
    string convert(string s, int numRows) {

        if (numRows == 1)
            return s;
        len = s.size();
        n = numRows;
        return pusu(s, numRows);
    }
};
