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

    vector<vector<int>> bfs(TreeNode *root) {
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

    void dfs(TreeNode *p, int dep, vector<vector<int>> &ans) {
        if (!p) {
            return;
        }
        if (ans.size() == dep) {
            ans.push_back({});
        }
        ans[dep].push_back(p->val);
        dfs(p->left, dep + 1, ans);
        dfs(p->right, dep + 1, ans);
    }

    vector<vector<int>> dfs(TreeNode *p) {
        vector<vector<int>> ans;
        dfs(p, 0, ans);
        return ans;
    }

  public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        // return bfs(root);
        return dfs(root);
    }
};
