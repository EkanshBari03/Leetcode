class Solution
{
public:
    int m, n;
    int t[71][71][71];
    int solve(vector<vector<int>> &grid, int row, int c1, int c2)
    {
        if (row >= n)
            return 0; // robot reached the last row;
        if (t[row][c1][c2] != -1)
            return t[row][c1][c2];
        int cherry = 0;
        cherry += grid[row][c1]; // if both are at the same cell take one
        if (c1 != c2)
        {
            cherry += grid[row][c2]; // cells are diff then take both;
        }

        int ans = 0;
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                int nRow = row + 1;
                int nC1 = c1 + i;
                int nC2 = c2 + j;
                if (nC1 >= 0 && nC1 < m && nC2 >= 0 && nC2 < m)
                {
                    ans = max(ans, solve(grid, nRow, nC1, nC2));
                }
            }
        }

        return t[row][c1][c2] = cherry + ans;
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        memset(t, -1, sizeof(t));
        return solve(grid, 0, 0, m - 1);
    }
};