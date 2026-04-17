class Solution {
  vector<string> ans;
  vector<string> number;
  int n;

  unordered_map<char, string> m = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                   {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                   {'8', "tuv"}, {'9', "wxyz"}};

  void dfs(int pos, string &str, string path) {
    if (pos == n) {
      ans.push_back(path);
      return;
    }
    char ch = str[pos];
    string zimu = m[ch];
    for (char x : zimu) {
      dfs(pos + 1, str, path + x);
    }
  }

public:
  vector<string> letterCombinations(string digits) {
    n = digits.size();
    ans.clear();
    dfs(0, digits, "");
    return ans;
  }
};
