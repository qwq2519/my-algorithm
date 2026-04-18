class Solution {

    vector<int> solution1(vector<vector<int>> &nums) {
        vector<pair<int, int>> merge;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                merge.push_back({nums[i][j], i});
            }
        }
        sort(merge.begin(), merge.end());

        vector<int> ans = {merge[0].first, merge.back().first};
        unordered_map<int, int> m;
        vector<int> count(nums.size());
        int l = 0;
        for (int r = 0; r < merge.size(); r++) {
            ++m[merge[r].second];
            while (m.size() == nums.size()) {
                if (merge[r].first - merge[l].first < ans[1] - ans[0]) {
                    ans[1] = merge[r].first;
                    ans[0] = merge[l].first;
                }
                --m[merge[l].second];
                if (m[merge[l].second] == 0) {
                    m.erase(merge[l].second);
                }
                l++;
            }
        }
        return ans;
    }

  public:
    vector<int> smallestRange(vector<vector<int>> &nums) {
        return solution1(nums);
    }
};
