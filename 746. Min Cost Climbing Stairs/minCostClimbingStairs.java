class Solution {
    public int minCostClimbingStairs(int[] cost) {

        int n = cost.length;
        int dp[] = new int[n + 1];
        for (int i = 0; i < n + 1; i++)
            dp[i] = 0;
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; i++) {
            dp[i] = cost[i] + Math.min(dp[i - 1], dp[i - 2]);
        }
        return dp[n] = Math.min(dp[n - 2], dp[n - 1]);
    }
}