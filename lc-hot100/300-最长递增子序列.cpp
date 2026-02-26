#include <algorithm>
class Solution {
  int Solution1(vector<int> &nums) {
    int n = nums.size();
    vector<int> f(n + 1, 1); // 以i结尾

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
          f[i] = max(f[i], f[j] + 1);
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
      ans = max(ans, f[i]);
    return ans;
  }

  int Solution2(vector<int> &nums) {
    vector<int> tails; // tails[i] 表示长度i+1的最长递增子序列的末尾元素最小值
    // 直觉是希望这个值越小越好，而且这个序列肯定是单调的
    // 类似于单调队列思想，当前数x能作为tali[i]的末尾数并且比末尾数更小，那么这个数x更有潜力
    // 从左往右扫描，不断淘汰相同len下的较大数，换上潜力更大的小数
    // tail数组每次增长，代表我们找到了更大的数x，更长的递增子序列，tails维护的是每个长度的最小尾巴

    for (auto x : nums) {
      auto it = std::lower_bound(tails.begin(), tails.end(), x);
      if (it == tails.end())
        tails.push_back(x); // new len
      else
        *it = x; // update min number
    }
    return tails.size();

    // 记录答案的做法-------------------------------------------------------------
    vector<int> tailsIdx;   // 最小尾巴对应下标
    vector<int> pre(n, -1); // 前驱
    for (int i = 0; i < nums.size(); i++) {
      int x = nums[i];
      int pos = std::lower_bound(tails.begin(), tails.end(), x) - tails.begin();
      if (pos > 0) // pos==0 说明x自己就是很小的值，可以作为长度为1的序列末尾值
        pre[i] = tails[pos - 1]; // 决定将x接在tails[pos-1]元素的后面
      if (pos == tails.size()) {
        tails.push_back(x);
        tailsIdx.push_back(i);
      } else { // updapte
        tails[pos] = x;
        tailsIdex[pos] = i;
      }
    }
    vector<int> seq;
    int cur = tailsIdx.back();
    while (cur != -1) {
      seq.push_back(a[cur]);
      cur = pre[cur];
    }
    reverse(seq.begin(), seq.end());
    return seq;
  }

public:
  int lengthOfLIS(vector<int> &nums) { return Solution1(nums); }
};
