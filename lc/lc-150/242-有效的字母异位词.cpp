class Solution {
  public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        int m[26] = {};
        for (auto c : s) {
            m[c - 'a']++;
        }
        for (auto c : t) {
            m[c - 'a']--;
            if (m[c - 'a'] < 0)
                return false;
        }
        return true;
    }
};
