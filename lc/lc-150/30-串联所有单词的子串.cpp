class Solution {

    // unordered_map<string, int> count;
    //
    // bool check(string &s, int L, int R) {
    //     auto t = count;
    //     for (int i(L); i <= R;) {
    //         int x = t[s.substr(i, len)];
    //         if (x < 1) {
    //             return false;
    //         }
    //         t[s.substr(i, len)]--;
    //
    //         i += len;
    //     }
    //
    //     return true;
    // }
    //
    // vector<int> brute(string s, vector<string> &words) {
    //     len = words[0].size();
    //     for (auto str : words)
    //         count[str]++;
    //
    //     n = words.size() * len;
    //
    //     vector<int> ans;
    //
    //     for (int r = n - 1; r < s.size(); ++r) {
    //         int l = r - n + 1;
    //
    //         if (check(s, l, r)) {
    //             ans.push_back(l);
    //         }
    //     }
    //
    //     return ans;
    // }

    vector<int> ans;
    int n, m, len, count;
    unordered_map<string, int> need;

    void calc(const string &s, int start) {
        int t = s.size();

        auto ned = need;
        int C = count;

        for (int r = 0; r + len - 1 < t; r += len) {
            string str = s.substr(r, len);
            --ned[str];
            if (ned[str] == 0)
                C--;

            int l = r - m;
            if (l >= 0) {
                str = s.substr(l, len);
                if (ned[str] == 0)
                    ++C;
                ++ned[str];
            }
            if (!C)
                ans.push_back(start + l + len);
        }
    }

    vector<int> moveWindows(string s, vector<string> &words) {
        len = words[0].size();
        n = s.size();
        m = len * words.size();
        need.clear();
        ans.clear();
        count = 0;

        if (words.empty() || s.empty() || s.size() < m)
            return {};
        for (auto str : words) {
            if (need[str] == 0) {
                ++count;
            }
            ++need[str];
        }

        int l = 0;
        // 滑动窗口的起点，为什么是0~len-1，因为窗口会不断滑动到s末尾，因此len统计到的信息肯定会是len=0的子集
        for (int start = 0; start < len; ++start) {
            string str = s.substr(start);
            calc(str, start);
        }

        return ans;
    }
    vector<int> bestAns(string s, vector<string> &words) {
        vector<int> ans;
        if (s.empty() || words.empty())
            return ans;
        int len = words[0].size();
        int wordCount = words.size();
        int totalLen = len * wordCount;
        int n = s.size();
        if (n < totalLen)
            return ans;

        unordered_map<string, int> need;
        for (const string &w : words) {
            ++need[w];
        }

        // 枚举每一种对齐方式
        for (int start = 0; start < len; ++start) {
            unordered_map<string, int> window;
            int left = start;
            int used = 0; // 当前窗口里有多少个单词
            for (int right = start; right + len - 1 < n; right += len) {
                string word = s.substr(right, len);
                // 当前单词不在 words 里，整段作废，窗口清空
                if (!need.count(word)) {
                    window.clear();
                    used = 0;
                    left = right + len;
                    continue;
                }
                // 把当前单词放进窗口
                ++window[word];
                ++used;
                // 如果某个单词数量超了，缩左边直到合法
                while (window[word] > need[word]) {
                    string leftWord = s.substr(left, len);
                    --window[leftWord];
                    --used;
                    left += len;
                }
                // 窗口里刚好有 wordCount 个单词，就是一个答案
                if (used == wordCount) {
                    ans.push_back(left);
                    // 继续滑动，移出最左边一个单词
                    string leftWord = s.substr(left, len);
                    --window[leftWord];
                    --used;
                    left += len;
                }
            }
        }
        return ans;
    }

  public:
    vector<int> findSubstring(string s, vector<string> &words) {
        // 目前这个做法常数还有很多可以优化的
        return bestAns(s, words);
    }
};
