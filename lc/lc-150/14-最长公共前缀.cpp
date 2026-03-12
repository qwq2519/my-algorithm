class Solution {
  public:
    string longestCommonPrefix(vector<string> &strs) {
        string str0 = strs[0];
        int len0 = str0.size();
        for (int i = 0; i < len0; ++i) {
            char c = str0[i];
            for (const auto &str : strs) {
                if (i == str.size() || str[i] != c) {
                    return str0.substr(0, i);
                }
            }
        }
        return str0;
    }
};
