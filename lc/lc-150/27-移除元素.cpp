class Solution {
  public:
    int removeElement(vector<int> &nums, int val) {
        // 这个做法不能保证顺序
        int n = nums.size();

        int i = 0;
        int k = n - 1;

        //  k+1 ... n-1 ==val
        // i...k unknown
        //  0...i-1 !=val

        while (i <= k) {
            if (nums[i] == val) {
                swap(nums[i], nums[k--]);
            } else {
                i++;
            }
        }

        return i;
    }

    // 快慢指针，保证相对顺序
    int Solution2(vector<int> &nums, int val) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); ++fast) {
            if (nums[fast] != val) {
                nums[slow++] = fast;
            }
        }
        return slow;
    }
};
