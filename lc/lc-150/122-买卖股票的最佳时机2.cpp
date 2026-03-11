class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        // 第i天的结果只和i-1天有关系，之前的历史信息都存在i-1天最大利润值了
        vector<int> f1(n), f2(n); // 持有的最大利润/没持有的最大利润

        // 同一天多次买卖?      买了卖，useless， 卖了买，也不比基于前一天更优吧
        // 其实空间可以优化为常数

        f1[0] = 0;
        f2[0] = -prices[0];

        for (int i = 1; i < n; i++) {
            // 昨天没有，今天也没有 / 昨天有，今天卖了
            f1[i] = max(f1[i - 1], f2[i - 1] + prices[i]);
            // 昨天没，今天买，昨天有，今天不动
            f2[i] = max(f1[i - 1] - prices[i], f2[i - 1]);
        }

        return f1[n - 1];
    }
};
