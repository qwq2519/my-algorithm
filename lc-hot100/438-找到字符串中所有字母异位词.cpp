class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> ans;

    if (p.size() > s.size()) {
      return ans;
    }

    int need[256] = {0};
    int count = 0;

    for (char c : p) {
      if (need[c] == 0) {
        ++count;
      }
      need[c]++;
    }

    int l = 0;
    for (int r = 0; r < s.size(); ++r) {
      char ch = s[r];
      --need[ch];
      if (need[ch] == 0) {
        --count;
      }

      if (r - l + 1 > p.size()) {
        if (need[s[l]] == 0) {
          ++count;
        }
        ++need[s[l]];
        ++l;
      }

      if (count == 0) {
        ans.push_back(l);
      }
    }
    return ans;
  }
};
