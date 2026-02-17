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
class Solution {
  int ans;
  void dfs(TreeNode *p, int dep) {
    if (!p) {
      return;
    }
    ans = max(ans, dep);
    dfs(p->left, dep + 1);
    dfs(p->right, dep + 1);
  }

public:
  int maxDepth(TreeNode *root) {
    ans = 0;
    dfs(root, 1);
    return ans;
  }
};
