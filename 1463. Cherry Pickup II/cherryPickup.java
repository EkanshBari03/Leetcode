class Solution {
    public int[][][] t;
    public int m, n;

    public int solve(int[][] grid, int row, int c1, int c2) {
        if (row >= n) {
            return 0; // Robot reached the last row
        }

        if (t[row][c1][c2] != -1) {
            return t[row][c1][c2];
        }

        int cherry = grid[row][c1]; // If both robots are at the same cell, take one cherry
        if (c1 != c2) {
            cherry += grid[row][c2]; // If robots are at different cells, take both cherries
        }

        int ans = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int nRow = row + 1;
                int nC1 = c1 + i;
                int nC2 = c2 + j;
                if (nC1 >= 0 && nC1 < m && nC2 >= 0 && nC2 < m) {
                    ans = Math.max(ans, solve(grid, nRow, nC1, nC2));
                }
            }
        }

        return t[row][c1][c2] = cherry + ans;
    }

    public int cherryPickup(int[][] grid) {
        n = grid.length;
        m = grid[0].length;
        t = new int[71][71][71];
        for (int i = 0; i < 71; i++) {
            for (int j = 0; j < 71; j++) {
                Arrays.fill(t[i][j], -1);
            }
        }
        return solve(grid, 0, 0, m - 1);
    }
}