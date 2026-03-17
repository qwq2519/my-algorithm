class Solution {
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        int cur = 0;
        int total = 0; // 多出来的油量，>=0才有解
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int a = gas[i] - cost[i];
            total += a;
            cur += a;
            if (cur < 0) {
                cur = 0;
                ans = i + 1;
                // 0开始走，到不了i+1了，因此贪心的从i+1开始走
                // 设  0<k<i
                // 0到不了i+1，因此0到i这段负收益
                // 0到 i的收益 = 0到k的收益 + k+1到i的收益
                // <0              >0              <0 ,因此不存在这样的k能走到i
            }
        }

        // 假设对a进行前缀和，其实答案也是前缀和中最小的那个的下一个，相当于找到了谷底，之后都会上坡
        // 假设答案是k        那么pre[k]是最小值
        // pre[n]-pre[k]+pre[any](any是k前面的，即k走到终点再从前面走，因为总和>0并且pre【k]是最小值，因此也成立)
        // 前缀和 从曲线最低处下一个开始走
        return total >= 0 ? ans : -1;
    }
};
