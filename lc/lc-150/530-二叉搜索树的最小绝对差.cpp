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

    int ans = INT_MAX;

    void errdfs(TreeNode *p, int *faVal) {
        // 父子节点差最小，肯定的，兄弟节点之间还隔着公共父节点呢。
        if (!p)
            return;
        if (faVal) {
            ans = min(ans, abs(p->val - *faVal));
        }
        // dfs(p->left, &(p->val));
        // dfs(p->right, &(p->val));
    }

    TreeNode *pre = nullptr;
    void inorder(TreeNode *p) {
        if (!p)
            return;
        inorder(p->left);
        if (pre) {
            ans = min(ans, abs(p->val - pre->val));
        }
        pre = p;
        inorder(p->right);
    }

  public:
    int getMinimumDifference(TreeNode *root) {
        // 最大差值：最左子节点和最右子节点，中序遍历得到的递增序列
        // 最小差值：中序序列相邻节点即可
        inorder(root);
        return ans;
    }
};
