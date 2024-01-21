class Solution
{
public:
    int dp[101];
    int solve(int ind, vector<int> &nums, int n)
    {

        if (n <= ind)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        int sum = 0;
        int pick = 0, nonPick = 0;

        pick += nums[ind] + solve(ind + 2, nums, n);
        nonPick += solve(ind + 1, nums, n);

        sum += max(pick, nonPick);
        return dp[ind] = sum;
    }
    int rob(vector<int> &nums)
    {

        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, nums, n);

        return ans;
    }
};