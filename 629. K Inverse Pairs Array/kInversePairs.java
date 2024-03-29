class Solution {
    public int kInversePairs(int n, int k) {

        int dp[][] = new int[n + 1][k + 1];
        int mod = 1000000007;
        // dp[i][j] = total number of arrays size from 1 to i in k inversions

        // if array size is zero then we don't have any inversions
        // if we have array size and inversion 0
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                for (int inv = 0; inv <= Math.min(j, i - 1); inv++) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - inv]) % mod;
                }
            }
        }

        return dp[n][k];
    }
}