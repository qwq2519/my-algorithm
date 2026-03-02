class Solution {
  public:
    void sortColors(vector<int> &nums) {
        // 自己写个排序，仅用常数空间
        // 可以用三路快排
        int pivot = 1;
        int i = 0;               // 0...i-1 <pivot
        int j = nums.size() - 1; // j+1...n-1 >pivot
        int k = 0;               //  i..k-1 ==pivot
                                 //  k...j unknouw
        while (k <= j) {
            if (nums[k] < pivot)
                swap(nums[i++], nums[k++]);
            else if (nums[k] > pivot)
                swap(nums[j--], nums[k]);
            else
                k++;
        }
    }
};
