/*
// 直接排序法
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> ans;

    unordered_map<string, vector<string>> list;
    for (int i = 0; i < strs.size(); i++) {
      string temp=strs[i];
      sort(temp.begin(), temp.end());
      list[temp].push_back(strs[i]);
    }

    for(auto& it:list){
        ans.push_back(it.second);
    }
    return ans;
  }
};
*/

// 统计字符法
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> mp;
    for (int i = 0; i < strs.size(); ++i) {
      int cnt[26] = {0};
      string str = strs[i];
      for (char c : str)
        cnt[c - 'a']++;

      string key = "";
      for (int j = 0; j < 26; ++j) {
        key += '#' + to_string(cnt[j]);
      }
      mp[key].push_back(str);
    }

    vector<vector<string>> ans;
    for (auto &it : mp) {
      ans.push_back(it.second);
    }
    return ans;
  }
};
