class Solution
{
public:
    unordered_map<string, int> dp;
    bool hasDuplicate(string &s1, string &s2)
    {

        vector<int> freq(26, 0);
        for (auto c : s1)
        {
            if (freq[c - 'a'] > 0)
                return true;
            freq[c - 'a']++;
        }
        for (auto c : s2)
        {
            if (freq[c - 'a'] > 0)
                return true;
        }
        return false;
    }
    int solve(int ind, int n, string temp, vector<string> &nums)
    {
        if (ind >= n)
        {
            return temp.length();
        }
        if (dp.find(temp) != dp.end())
            dp[temp];
        int take = 0;
        int skip = 0;
        if (hasDuplicate(nums[ind], temp))
        {
            skip = solve(ind + 1, n, temp, nums);
        }
        else
        {
            skip = solve(ind + 1, n, temp, nums);

            take = solve(ind + 1, n, temp + nums[ind], nums);
        }

        return dp[temp] = max(take, skip);
    }
    int maxLength(vector<string> &arr)
    {

        int n = arr.size();
        string temp = "";
        return solve(0, n, temp, arr);
    }
};