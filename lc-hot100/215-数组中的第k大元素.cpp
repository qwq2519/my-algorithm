class Solution {
  int cnt;
  int find(vector<int> &a, int l, int r) {
    if (l >= r)
      return a[l];
    swap(a[l], a[l + rand() % (r - l + 1)]);
    int pivot = a[l];
    int i = l;
    int j = r;
    int k = l + 1;

    while (k <= j) {
      if (a[k] < pivot) {
        swap(a[k++], a[i++]);
      } else if (a[k] > pivot) {
        swap(a[k], a[j--]);
      } else {
        k++;
      }
    }
    int left = (i - 1) - l + 1;
    int mid = j - i + 1;
    if (cnt <= left) {
      return find(a, l, i - 1);
    } else if (cnt > left + mid) {
      cnt = cnt - left - mid;
      return find(a, j + 1, r);
    }
    return pivot;
  }

public:
  int findKthLargest(vector<int> &nums, int k) {
    cnt = nums.size() - k;
    srand(time(0));
    return find(nums, 0, nums.size() - 1);
  }
};
