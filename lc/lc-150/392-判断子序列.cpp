class Solution {

    int find(string &s, int pos, char c) {
        int n = s.size();
        for (int i = pos; i < n; i++) {
            if (s[i] == c) {
                return i;
            }
        }
        return -1;
    }
    // 其实这个时间复杂度和双指针差不多
    bool Brute(string s, string t) {
        int lens = s.size();
        int lent = t.size();

        int pre = 0;
        for (int i = 0; i < lens; i++) {
            int next = find(t, pre, s[i]);
            if (next == -1)
                return false;
            else
                pre = next + 1;
        }
        return true;
    }

    bool twoPointer(string s, string t) {
        int lens = s.size();
        int lent = t.size();

        int i = 0, j = 0;
        while (i < lens && j < lent) {
            if (s[i] == t[j])
                i++;
            j++;
        }
        return i == lens;
    }

  public:
    bool isSubsequence(string s, string t) { return twoPointer(s, t); }
};
