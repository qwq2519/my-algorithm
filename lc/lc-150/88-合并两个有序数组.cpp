class Solution {
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        // 逆向双指针 num1尾部有空余n个空间，相当于逆序进行归并排序
        // 但是正常情况下归并排序还是要复制的，这个预留了空间取了个巧
        int i = m - 1, j = n - 1, k = n + m - 1;
        for (; i >= 0 && j >= 0;) {
            if (nums1[i] >= nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        for (; i >= 0;)
            nums1[k--] = nums1[i--];
        for (; j >= 0;)
            nums1[k--] = nums2[j--];
    }
};
