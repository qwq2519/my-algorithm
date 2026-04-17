#include <algorithm>
class Solution {

  // 第一个元素大于所有第二段的元素
  // 最后一个元素小于所有第一段的元素
  int findMid(vector<int> &nums) {
    int l = -1, r = nums.size() - 1;
    int last = nums[r];
    while (l + 1 < r) {
      int mid = (l + r) >> 1;
      if (nums[mid] > last)
        l = mid;
      else
        r = mid;
    }
    return r;
  }

  int find(vector<int> &nums, int l, int r, int target) {
    while (l + 1 < r) {
      int mid = (l + r) >> 1;
      if (nums[mid] <= target)
        l = mid;
      else
        r = mid;
    }
    return l >= 0 && nums[l] == target ? l : -1;
  }

public:
  int search(vector<int> &nums, int target) {
    // 原来是单调
    // 旋转后变成了两个单调拼在一起，中间突然掉下来
    // 二分只能在一段二分区间里找，因此要找target是在哪段
    if (nums.size() == 0) {
      return -1;
    }
    if (nums.size() == 1) {
      return nums[0] == target ? 0 : -1;
    }

    int minIdx = findMid(nums);
    int last = nums.back();
    // 在第二段
    if (target <= last) {
      return find(nums, minIdx - 1, nums.size(), target);
    }
    // 在第一段
    return find(nums, -1, minIdx, target);
  }
};
