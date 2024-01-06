class Solution
{
public:
    int n;

    int getNextIndex(vector<vector<int>> &nums, int s, int curJobEnd)
    {

        int e = n - 1;
        int result = n + 1;
        while (s <= e)
        {

            int mid = e + (s - e) / 2;

            if (nums[mid][0] >= curJobEnd)
            {
                result = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return result;
    }
    int solve(int ind, vector<vector<int>> &nums, vector<int> &dp)
    {

        if (ind >= nums.size())
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        int nextInd = getNextIndex(nums, ind + 1, nums[ind][1]);

        int taken = nums[ind][2] + solve(nextInd, nums, dp);

        int skip = solve(ind + 1, nums, dp);

        return dp[ind] = max(skip, taken);
    }
    int jobScheduling(vector<int> &startTime, vector<int> &endTime,
                      vector<int> &profit)
    {

        n = startTime.size();
        vector<vector<int>> nums;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp = {startTime[i], endTime[i], profit[i]};
            nums.push_back(temp);
        }
        sort(nums.begin(), nums.end());
        vector<int> dp(n + 1, -1);
        return solve(0, nums, dp);
    }
};