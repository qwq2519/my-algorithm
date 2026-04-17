class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    // 对顶堆，上堆（最小堆）的最小值 > 下堆（最大堆）的最大值
    // 要加入堆就得扫描两个数组，线性了

    // 可以模仿对顶堆的思想，将两个数组的数混在一起，分成两个数量一样的组就行了。
    // 因为数组是有序的，可以用二分来枚举切分点

    // 选择一个切分点i，表示num1左边取i个，nums2 左边取j个。
    //  一组是a前i个+b的前j个

    // 切分后四个边界值：
    // A_left = nums1[i-1]（若 i=0 则当作 -∞）
    // A_right = nums1[i]（若 i=m 则当作 +∞）
    // B_left = nums2[j-1]（若 j=0 则当作 -∞）
    // B_right = nums2[j]（若 j=n 则当作 +∞）

    // 正确切分需要满足：max(A_left,B_left) < min( A_right,B_right)

    // 如果 A_left > B_right：说明 i 取大了，往左二分
    // 如果 B_left > A_right：说明 i 取小了，往右二分
    int n = nums1.size(), m = nums2.size();
    int leftCount = (m + n + 1) / 2;

    // i取值在[0,n],也要保证j在[0,m]  自己用不等式算下，在和[0,n]取交集
    int low = max(0, leftCount - m);
    int high = min(n, leftCount);

    int l = low - 1, r = high + 1;
    while (l + 1 < r) {
      int i = (l + r) / 2;
      int j = leftCount - i;

      int A_left = (i == 0) ? INT_MIN : nums1[i - 1];
      int A_right = (i == n) ? INT_MAX : nums1[i];
      int B_left = (j == 0) ? INT_MIN : nums2[j - 1];
      int B_right = (j == m) ? INT_MAX : nums2[j];

      if (A_left > B_right) {
        r = i;
      } else if (A_right < B_left) {
        l = i;
      } else {
        int leftMax = max(A_left, B_left);
        int rightMin = min(A_right, B_right);
        if ((m + n) & 1)
          return leftMax;
        return (leftMax + rightMin) * 1.0 / 2.0;
      }
    }
    return 0.0;
  }
};
