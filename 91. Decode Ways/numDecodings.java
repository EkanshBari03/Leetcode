class Solution {
    int[] dp;

    public int solve(int ind, String s, int n) {
        if (n == ind) {
            return dp[ind] = 1;
        }
        if (s.charAt(ind) == '0') {
            return dp[ind] = 0;
        }
        if (dp[ind] != -1) {
            return dp[ind];
        }
        int oneChar = solve(ind + 1, s, n);
        int twoChar = 0;
        if (ind + 1 < n) {
            if (s.charAt(ind) == '1' || (s.charAt(ind) == '2' && s.charAt(ind + 1) <= '6')) {
                twoChar = solve(ind + 2, s, n);
            }
        }

        return dp[ind] = oneChar + twoChar;
    }

    public int numDecodings(String s) {
        dp = new int[101];
        Arrays.fill(dp, -1);
        int n = s.length();
        return solve(0, s, n);

    }
}