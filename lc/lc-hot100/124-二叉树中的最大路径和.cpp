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
  int ans = INT_MIN;
  int dfs(TreeNode *p) {
    if (!p) {
      return 0;
    }
    int leftDown = max(0, dfs(p->left));
    int rightDown = max(0, dfs(p->right));

    // 以p为拐点
    ans = max(ans, p->val + leftDown + rightDown);
    // 从p向下走最好
    return p->val + max(leftDown, rightDown);
  }

public:
  int maxPathSum(TreeNode *root) {
    dfs(root);
    return ans;
  }
};
