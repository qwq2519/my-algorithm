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
  vector<vector<int>> levelOrder(TreeNode *root) {
    queue<pair<TreeNode *, int>> q;
    vector<vector<int>> ans;
    if (!root) {
      return ans;
    }

    q.push({root, 1});
    while (!q.empty()) {
      auto [node, dep] = q.front();
      q.pop();

      if (ans.size() < dep) {
        ans.push_back({});
      }
      ans[dep - 1].push_back(node->val);

      if (node->left) {
        q.push({node->left, dep + 1});
      }
      if (node->right) {
        q.push({node->right, dep + 1});
      }
    }
    return ans;
  }
};
