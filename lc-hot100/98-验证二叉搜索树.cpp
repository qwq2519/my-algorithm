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
  bool check(TreeNode *p, int *mx, int *mi) {
    if (!p) {
      return true;
    }
    bool result = true;
    if (mx) {
      result &= p->val < *mx;
    }
    if (mi) {
      result &= p->val > *mi;
    }
    return result && check(p->left, &(p->val), mi) &&
           check(p->right, mx, &(p->val));
  }

public:
  bool isValidBST(TreeNode *root) { return check(root, nullptr, nullptr); }
};
