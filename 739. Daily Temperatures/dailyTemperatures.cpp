class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> ans(n, 0);
        stack<pair<int, int>> s;

        for (int i = n - 1; i >= 0; i--)
        {
            if (s.empty())
            {
                s.push({nums[i], i});
                continue;
            }
            while (!s.empty() && s.top().first <= nums[i])
            {
                s.pop();
            }
            if (s.size() > 0)
                ans[i] = s.top().second - i;
            s.push({nums[i], i});
        }

        return ans;
    }
};