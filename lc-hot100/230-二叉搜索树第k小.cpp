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
  int cnt;
  int ans;

private:
  void dfs(TreeNode *p) {
    if (!p || cnt == 0) {
      return;
    }
    dfs(p->left);
    if (--cnt == 0) {
      ans = p->val;
      return;
    }
    dfs(p->right);
  }

public:
  int kthSmallest(TreeNode *root, int k) {
    cnt = k;
    dfs(root);
    return ans;
  }
};
