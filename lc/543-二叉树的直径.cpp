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
  int d;
  int dfs(TreeNode *p) {
    int now = 0;
    if (p->left) {
      int llen = dfs(p->left);
      d = max(d, now + llen + 1);
      now = max(now, llen + 1);
    }
    if (p->right) {
      int rlen = dfs(p->right);
      d = max(d, now + rlen + 1);
      now = max(now, rlen + 1);
    }
    return now;
  }

public:
  int diameterOfBinaryTree(TreeNode *root) {
    d = 0;
    dfs(root);
    return d;
  }
};
