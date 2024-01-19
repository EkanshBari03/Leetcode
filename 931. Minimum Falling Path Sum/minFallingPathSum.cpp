
class Solution
{
public:
    int solve(vector<vector<int>> &A, int row, int col, vector<vector<int>> &dp)
    {
        int n = A.size();

        if (dp[row][col] != INT_MAX)
            return dp[row][col];

        if (row == n - 1)
            return dp[row][col] = A[row][col];

        int left = INT_MAX, right = INT_MAX;

        if (col > 0)
            left = solve(A, row + 1, col - 1, dp);

        int straight = solve(A, row + 1, col, dp);

        if (col < n - 1)
            right = solve(A, row + 1, col + 1, dp);

        dp[row][col] = min(left, min(straight, right)) + A[row][col];

        return dp[row][col];
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {

        int n = matrix.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i)
        {
            ans = min(ans, solve(matrix, 0, i, dp));
        }

        return ans;
    }
};
