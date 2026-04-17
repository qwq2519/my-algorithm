class Solution {

public:
  int jump(vector<int> &nums) {
    // 最小跳数到达终点，和bfs有点像，但是这题可以理解为将状态压缩在数组上
    int n = nums.size();
    int step = 0;   // 当前已经用了多少跳
    int end = 0;    // step跳能到达的
    int maxPos = 0; // step+1跳能到达的

    for (int i = 0; i < n - 1; i++) {
      maxPos = max(maxPos, nums[i] + i);
      if (i == end) {
        end = maxPos;
        step++;
      }
    }
    return step;
  }
  // 双指针dp
  int jump2(vector<int> &nums) {
    int n = nums.size();
    vector<int> f(n);
    for (int i = 1, j = 0; i < n; i++) {
      while (j + nums[j] < i)
        j++; // 显然f是单调递增的，贪心的找最早一个点转移过来
      f[i] = f[j] + 1;
    }
    return f[n - 1];
  }
};
