class Solution {

    // 如果只有两个数组，那么求结果就很容易了，类似一个二维矩阵，然后做合并k个升序链表
    // 那么这题合并n个，可以两两合并来做。

    vector<int> merge(vector<int> &a, vector<int> &b, int k) {
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        vector<int> res;
        //(i,j) (i+1,j) (i+n,j) n条链做合并
        for (int i = 0; i < min((int)a.size(), k); i++) {
            pq.push({a[i] + b[0], i, 0});
        }
        // 不能直接写k--，因为k是全局的多个数组合并的结果
        // 而这里只有两个数组，因此堆中结果数可能小于k。
        // 堆的状态数是a.size()*b.size(),而k上限是多个数组的长度和
        while (res.size() < k && !pq.empty()) {
            auto [sum, i, j] = pq.top();
            pq.pop();
            res.push_back(sum);
            if (j + 1 < b.size()) {
                pq.push({a[i] + b[j + 1], i, j + 1});
            }
        }

        return res;
    }

  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        auto cur = mat[0];
        if (cur.size() > k)
            cur.resize(k);
        for (int i = 1; i < mat.size(); i++) {
            cur = merge(cur, mat[i], k);
        }
        return cur[k - 1];
        // 错误做法，这只是最小增量，但不是全局最小
        // 状态上只是维护一条链，而不是全局的最优
        //  using T = tuple<int, int, int>;
        //  priority_queue<T, vector<T>, greater<T>> q;
        //
        //  int sum = 0;
        //  for (int i = 0; i < n; i++) {
        //      sum += mat[i][0];
        //      q.push({mat[i][1], i, 1});
        //  }
        //  k--;
        //  while (k--) {
        //      auto [val, i, j] = q.top();
        //      q.pop();
        //      if (j + 1 < m) {
        //          q.push({mat[i][j + 1], i, j + 1});
        //      }
        //      sum = sum - mat[i][j - 1] + mat[i][j];
        //  }
    }
};
