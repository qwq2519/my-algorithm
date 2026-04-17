class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    int l = -1, r = n;
    while (l + 1 != r) {
      int mid = (l + r) >> 1;
      if (matrix[mid][0] <= target)
        l = mid;
      else
        r = mid;
    }

    int t = l;

    if (t == -1) {
      return false;
    }

    l = -1, r = m;
    while (l + 1 != r) {
      int mid = (l + r) >> 1;
      if (matrix[t][mid] <= target)
        l = mid;
      else
        r = mid;
    }

    if (matrix[t][l] == target)
      return true;
    return false;
  }
};
