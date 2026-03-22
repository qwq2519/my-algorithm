class Solution {
  public:
    bool canConstruct(string ransomNote, string magazine) {
        int r[26] = {};
        for (auto c : ransomNote) {
            ++r[c - 'a'];
        }

        int m[26] = {};
        for (auto c : magazine) {
            ++m[c - 'a'];
        }

        for (char c = 'a'; c <= 'z'; ++c) {
            if (m[c - 'a'] < r[c - 'a']) {
                return false;
            }
        }

        return true;
    }
};
