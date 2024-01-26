class Solution
{
public:
    int M, N;
    int dp[51][51][51];
    int mod = 1e9 + 7;
    int solve(int row, int col, int moves)
    {
        if (row < 0 || row >= M || col < 0 || col >= N)
        {
            return 1;
        }
        if (moves <= 0)
            return 0;
        if (dp[row][col][moves] != -1)
            return dp[row][col][moves];
        long result = 0;
        int dRow[] = {1, 0, -1, 0};
        int dCol[] = {0, -1, 0, 1};
        for (int i = 0; i < 4; i++)
        {
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];

            result = (result + solve(nRow, nCol, moves - 1)) % mod;
        }
        return dp[row][col][moves] = result;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        M = m;
        N = n;
        memset(dp, -1, sizeof(dp));
        return solve(startRow, startColumn, maxMove);
    }
};