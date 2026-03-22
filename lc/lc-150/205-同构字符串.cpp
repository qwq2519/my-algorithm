class Solution {
  public:
    bool isIsomorphic(string s, string t) {

        int m[307];
        bool v[307] = {};
        fill(m, m + 300, -1);
        int n = s.size();
        for (int i(0); i < n; i++) {
            if (m[s[i]] == -1) {
                if (v[t[i]])
                    return false;
                m[s[i]] = t[i];
                v[t[i]] = true;
            } else if (m[s[i]] != t[i])
                return false;
        }
        return true;
    }
};
