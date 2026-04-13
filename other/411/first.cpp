

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param node TreeNode类 二叉树的顶点
     * @return TreeNode类
     */
    vector<TreeNode *> ans;
    set<TreeNode *> vis;

    // void dfs(TreeNode *p) {
    //     if (!p)
    //         return;
    //     ans.push_back(p);
    //     dfs(p->left);
    //     dfs(p->right);
    // }

    TreeNode *treeToLinkedList(TreeNode *node) {

        static stack<TreeNode *> s;
        s.push(node);
        while (!s.empty()) {
            auto p = s.top();
            // cout<<p->val<<endl;
            s.pop();
            // 第一次到该节点
            if (vis.find(p) == vis.end()) {
                ans.push_back(p);
                vis.insert(p);
                if (p->left) {
                    s.push(p);
                    s.push(p->left);
                } else {
                    if (p->right)
                        s.push(p->right);
                }

            } else { // 先走了左子树了，
                if (p->right)
                    s.push(p->right);
            }
        }
        // dfs(node);
        // 这样做有90%能过，剩下10%显示段错误
        // 但是我把下面这个循环注释掉就没段错误了
        // int n = ans.size();
        // for (int i = 0; i < n - 1; i++) {
        // ans[i]->left = nullptr;
        // ans[i]->right = ans[i + 1];
        // }

        // 还是段错误
        auto it = ans.begin();
        for (auto it = ans.begin(); it != ans.end(); it++) {
            if (it == prev(ans.end()))
                break;
            *it->left = nullptr;
            *it->right = *next(it);
        }
        // for (int i = 0; i < ans.size() - 1; i++) {
        //     ans[i]->left = nullptr;
        //     ans[i]->right = ans[i + 1];
        // }
        return node;
    }
};
