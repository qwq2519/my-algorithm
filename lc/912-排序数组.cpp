#include <algorithm>
class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    srand(time(0));
    // Quicksort(nums, 0, nums.size() - 1);
    vector<int> tmp(nums.size(), 0);
    mergeSort(nums, tmp, 0, nums.size() - 1);
    return nums;
  }

  void Quicksort(vector<int> &a, int l, int r) {
    if (l >= r)
      return;
    swap(a[l], a[l + rand() % (r - l + 1)]);
    int pivot = a[l];

    // l...i-1  <pivot
    // i...k-1 =pivot
    // k...j unknown
    // j+1...r >pivot

    int i = l;     // <pivot
    int k = l + 1; // cur scanning
    int j = r;     // >pivot

    while (k <= j) {
      if (a[k] < pivot) {
        swap(a[k++], a[i++]);
      } else if (a[k] > pivot) {
        swap(a[k], a[j--]);
        // 换过来的a[j]仍为检查，所以不能k++;
      } else {
        k++;
      }
    }
    Quicksort(a, l, i - 1);
    Quicksort(a, j + 1, r);
  }

  void mergeSort(vector<int> &a, vector<int> &tmp, int l, int r) {
    if (l >= r)
      return;
    int m = (l + r) / 2;
    mergeSort(a, tmp, l, m);
    mergeSort(a, tmp, m + 1, r);
    int i = l, j = m + 1;
    int k = l;
    while (i <= m && j <= r)
      tmp[k++] = (a[i] < a[j] ? a[i++] : a[j++]);
    while (i <= m)
      tmp[k++] = a[i++];
    while (j <= r)
      tmp[k++] = a[j++];
    for (int t = l; t <= r; t++)
      a[t] = tmp[t];
  }
};
