#include <fstream>
class Solution {

    int find(vector<int> &a, int v, int l, int r) {
        int L = l;
        int R = r;
        while (L + 1 < R) {
            int mid((L + R) >> 1);
            if (a[mid] < v)
                L = mid;
            else
                R = mid;
        }
        if (r == R || a[R] != v)
            return -1;
        return R;
    }

    vector<int> binarySearch(vector<int> &a, int target) {
        int n = a.size();
        for (int i = 1; i < n; i++) {
            int x = a[i];
            int p = find(a, target - a[i], -1, i);
            if (p == -1)
                continue;
            return {p + 1, i + 1};
        }
        return {};
    }

    vector<int> twoPointer(vector<int> &a, int target) {
        int l = 0, r = a.size() - 1;
        // 为什么这样移动不会漏掉答案
        while (l < r) {
            if (a[l] + a[r] <
                target) { // 任何 a[l]+a[0...r] 都 <target，所以这个 l可以淘汰了
                l++;
            } else if (a[l] + a[r] > target) { // 任何a[r] + a[ l ,l+1,l+2]
                                               // 都不符合，因此可以淘汰这个r了
                r--;
            } else {
                return {l + 1, r + 1};
            }
        }
        // 利用有序性排除一类答案
        // 双指针每次移动不仅是尝试新答案，更是在排除一大类错误答案
        // a[l]+a[r] < target
        // ,r是当前能搭配的最大右端了，比r小没用，比r大就会大于答案了，所以这个l废了
        // 每次都是搜索空间的裁剪 a = [1, 2, 4, 6, 10]  target = 8
        // a[l]=1,a[r]=10  1+10=11>target，因此r太大了可以淘汰了
        // 可以画个二维图像来表示，更直观 f(i,j) i<j
        // 是个上三角，一开始f(0,n-1)是在左上角 如果f(i,j) <target
        // ，那么f(i,k<j)均不可以了，i没用了，left++
        return {};
    }

  public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        return twoPointer(numbers, target);
    }
};
