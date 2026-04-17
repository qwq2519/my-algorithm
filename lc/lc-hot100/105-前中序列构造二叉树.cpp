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
  // 前序 根 左 右
  // 中序 左 根 右
  int preIdx = 0;
  TreeNode *build(vector<int> &preorder, vector<int> &inorder, int il, int ir) {
    if (il >= ir) {
      return nullptr;
    }
    int rtval = preorder[preIdx++];
    int i;
    // 题目保证了值的唯一，可以用一个hash表来优化
    for (i = il; i < ir; ++i) {
      if (inorder[i] == rtval) {
        break;
      }
    }
    auto left = build(preorder, inorder, il, i);
    auto right = build(preorder, inorder, i + 1, ir);
    return new TreeNode(rtval, left, right);
  }

public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return build(preorder, inorder, 0, inorder.size());
  }
};
