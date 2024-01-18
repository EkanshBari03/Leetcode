class Solution
{
public:
    int solve(vector<int> &nums, int start, vector<int> &dp)
    {
        if (start >= nums.size())
            return 0;
        if (dp[start] != -1)
            return dp[start];
        int sum = nums[start];
        int left = solve(nums, start + 1, dp);
        int right = solve(nums, start + 2, dp);
        sum += min(left, right);
        return dp[start] = sum;
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        vector<int> dp(cost.size() + 1, -1);
        int l = solve(cost, 0, dp);
        int h = solve(cost, 1, dp);

        return min(l, h);
    }
};