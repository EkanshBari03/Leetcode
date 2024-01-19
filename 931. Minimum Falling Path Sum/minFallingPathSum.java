class Solution {
    public int solve(int[][] A, int row, int col, int[][] dp) {
        int n = A.length;

        if (dp[row][col] != Integer.MAX_VALUE)
            return dp[row][col];

        if (row == n - 1) {
            return dp[row][col] = A[row][col];
        }

        int left = Integer.MAX_VALUE, right = Integer.MAX_VALUE;

        if (col > 0) {
            left = solve(A, row + 1, col - 1, dp);
        }

        int straight = solve(A, row + 1, col, dp);

        if (col < n - 1) {
            right = solve(A, row + 1, col + 1, dp);
        }

        dp[row][col] = Math.min(left, Math.min(straight, right)) + A[row][col];

        return dp[row][col];
    }

    public int minFallingPathSum(int[][] matrix) {
        int n = matrix.length;
        int[][] dp = new int[n + 1][n + 1];
        for (int[] row : dp) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }

        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < n; ++i) {
            ans = Math.min(ans, solve(matrix, 0, i, dp));
        }

        return ans;
    }
}