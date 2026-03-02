class Solution {
  public:
    int findDuplicate(vector<int> &nums) {
        // n+1个数，值为[1,n],  可以构成环
        int slow = 0, fast = 0;
        while (1) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                int head = 0;
                while (head != slow) {
                    head = nums[head];
                    slow = nums[slow];
                }
                return head;
            }
        }
        return slow;
    }
};
