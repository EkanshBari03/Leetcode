class Solution
{
public:
    int n;
    int dp[501];
    int solve(int ind, vector<int> &nums, int k)
    {
        if (ind >= n)
            return 0;

        if (dp[ind] != -1)
            return dp[ind];

        int ans = 0;
        int maxi = -1;

        for (int j = ind; j < n && j - ind + 1 <= k; j++)
        {

            maxi = max(maxi, nums[j]);

            ans = max(ans, ((j - ind + 1) * maxi) + solve(j + 1, nums, k));
        }

        return dp[ind] = ans;
    }
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        n = arr.size();
        memset(dp, -1, sizeof(dp));

        return solve(0, arr, k);
    }
};