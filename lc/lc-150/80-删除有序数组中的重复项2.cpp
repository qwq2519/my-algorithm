class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        // 为什么是-2，因为nums有序，0...k-1也必然有序，只比较这个就行了。
        // in_place_tt
        int n = nums.size();
        int k = 0;
        for (int i = 0; i < n; ++i) {
            if (k < 2 || nums[k - 2] != nums[i])
                nums[k++] = nums[i];
        }
        return k;
    }
};
