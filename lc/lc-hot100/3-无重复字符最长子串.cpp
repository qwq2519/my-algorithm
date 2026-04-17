class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int n = s.size();
    if (s.empty()) {
      return 0;
    }
    int ans = 1;

    array<int, 256> last;
    last.fill(-1);

    int l = 0;
    for (int r = 0; r < n; ++r) {
      unsigned char c = s[r];
      if (last[c] >= l)
        l = last[c] + 1;
      last[c] = r;
      ans = max(ans, r - l + 1);
    }

    return ans;
  }
};
