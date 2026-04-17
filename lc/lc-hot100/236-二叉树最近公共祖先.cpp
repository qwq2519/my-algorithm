/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  unordered_map<TreeNode *, int> dep;
  unordered_map<TreeNode *, TreeNode *> fa;
  void dfs(TreeNode *p, TreeNode *F, int D) {
    if (!p) {
      return;
    }
    fa[p] = F;
    dep[p] = D;
    dfs(p->left, p, D + 1);
    dfs(p->right, p, D + 1);
  }

public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    dfs(root, nullptr, 1);
    if (dep[p] < dep[q]) {
      swap(p, q);
    }

    while (dep[p] > dep[q]) {
      p = fa[p];
    }

    while (p != q) {
      p = fa[p];
      q = fa[q];
    }
    return p;
  }
};
