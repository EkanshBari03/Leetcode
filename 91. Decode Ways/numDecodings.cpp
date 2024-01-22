class Solution
{
public:
    int dp[101];
    int solve(int ind, string &s, int &n)
    {
        if (n == ind)
            return dp[ind] = 1;
        if (s[ind] == '0')
            return dp[ind] = 0;
        if (dp[ind] != -1)
            return dp[ind];
        int oneChar = solve(ind + 1, s, n);
        int twoChar = 0;
        if (ind + 1 < n)
        {
            if (s[ind] == '1' || (s[ind] == '2' && s[ind + 1] <= '6'))
                twoChar = solve(ind + 2, s, n);
        }

        return dp[ind] = oneChar + twoChar;
    }
    int numDecodings(string s)
    {

        memset(dp, -1, sizeof(dp));
        int n = s.size();
        return solve(0, s, n);
    }
};