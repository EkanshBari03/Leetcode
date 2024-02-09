class Solution {
    public int[] dp;
    public int solve(int n) {
        if (n == 0) return 0;

        if (dp[n] != -1) return dp[n];

        int miniPair = Integer.MAX_VALUE;
        for (int i = 1; i * i <= n; i++) {
            int res = 1 + solve(n - i * i);
            miniPair = Math.min(miniPair, res);
        }

        return dp[n] = miniPair;
    }
    public int numSquares(int n) {
        dp = new int[10001];
        Arrays.fill(dp, -1);
        return solve(n);
    }
}