class Solution {
    public int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {

        int dp[][][] = new int[m][n][maxMove + 1];
        int mod = 1000000000 + 7;

        for (int k = 1; k <= maxMove; k++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {

                    int delrow[] = { 1, 0, -1, 0 };
                    int delcol[] = { 0, -1, 0, 1 };
                    for (int d = 0; d < 4; d++) {
                        int x = i + delrow[d];
                        int y = j + delcol[d];

                        if (x < 0 || x >= m || y < 0 || y >= n)
                            dp[i][j][k] = (dp[i][j][k] + 1) % mod;
                        else
                            dp[i][j][k] = (dp[i][j][k] + dp[x][y][k - 1]) % mod;
                    }
                }
            }
        }
        return dp[startRow][startColumn][maxMove];
    }
}