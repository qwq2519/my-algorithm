class Solution {
public:
  string minWindow(string s, string t) {
    string ans = "";
    int need[256];
    int count = 0;

    for (char c : t) {
      if (need[c] == 0) {
        ++count;
      }
      ++need[c];
    }

    int ansl = -1, ansr = -1;
    int l = 0;
    for (int r = 0; r < s.size(); r++) {
      char c = s[r];
      need[c]--;
      if (need[c] == 0) {
        --count;
      }

      while (l <= r && count == 0) {
        if (ansl == -1 || r - l < ansr - ansl) {
          ansr = r;
          ansl = l;
        }
        if (need[s[l]] == 0) {
          count++;
        }
        need[s[l]]++;
        l++;
      }
    }

    return ansl == -1 ? "" : s.substr(ansl, ansr - ansl + 1);
  }
};
