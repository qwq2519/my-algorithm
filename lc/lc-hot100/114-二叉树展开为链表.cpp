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
public:
  void flatten(TreeNode *root) { flatten1(root); }

  // 先序遍历的相反顺序，然后头插法
  TreeNode *head = nullptr;
  void flatten1(TreeNode *p) {
    if (!p) {
      return;
    }
    flatten1(p->right);
    flatten1(p->left);
    p->right = head;
    p->left = nullptr;
    head = p;
  }
};
