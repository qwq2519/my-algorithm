class Solution {

    vector<string> split(const string &s, char delim) {
        vector<string> result;
        string cur = "";
        for (char ch : s) {
            if (ch == delim) {
                result.push_back(cur);
                cur.clear();
                continue;
            }
            cur += ch;
        }
        result.push_back(cur);
        return result;
    }

  public:
    bool wordPattern(string pattern, string s) {
        vector<string> strs = split(s, ' ');

        map<char, string> m;
        unordered_set<string> exist;

        int n = pattern.size();
        if (strs.size() != n) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            char c = pattern[i];
            string str = strs[i];
            if (m.find(c) == m.end()) {
                if (exist.contains(str)) {
                    return false;
                }
                exist.insert(str);
                m[c] = str;
            } else if (m[c] != str) {
                return false;
            }
        }
        return true;
    }
};
