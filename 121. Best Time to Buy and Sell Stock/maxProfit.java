class Solution {
    public int maxProfit(int[] prices) {

        int n = prices.length;
        int profit = 0;
        int buy = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            buy = Math.min(buy, prices[i]);

            profit = Math.max(profit, prices[i] - buy);

        }
        return profit;
    }
}