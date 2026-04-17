/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
// 题目要求，路径是单向的，只能是从父节点到子节点,不需要拐点
// 类似和为k的子数组吧，变成了树上问题，还是前缀和+哈希表
//  curprefixsum - 祖先prefixsum = 某个路径的sum == targetSum
class Solution {

  unordered_map<long long, int> cnt; // sum : count
  int ans = 0;
  int sum;
  void dfs(TreeNode *p, long long presum) {
    if (!p) {
      return;
    }
    presum += p->val;
    // 先统计，当前前缀和不是祖先前缀和
    ans += cnt[presum - sum];
    cnt[presum]++;
    dfs(p->left, presum);
    dfs(p->right, presum);
    cnt[presum]--;
  }

public:
  int pathSum(TreeNode *root, int targetSum) {
    cnt[0] = 1;
    sum = targetSum;
    dfs(root, 0);
    return ans;
  }
};
