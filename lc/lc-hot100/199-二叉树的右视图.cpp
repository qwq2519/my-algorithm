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
  void dfs(TreeNode *p, vector<int> &x, int dep) {
    if (!p) {
      return;
    }
    if (dep > x.size()) {
      x.push_back(p->val);
    }
    dfs(p->right, x, dep + 1);
    dfs(p->left, x, dep + 1);
  }

public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> ans;
    dfs(root, ans, 1);
    return ans;
  }
};
