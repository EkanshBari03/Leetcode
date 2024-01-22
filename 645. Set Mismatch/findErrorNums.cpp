class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {

        vector<int> ans = {-1, -1};

        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        for (auto it : m)
        {
            if (it.second > 1)
            {
                ans[0] = it.first;
                break;
            }
        }
        int n = nums.size();
        for (int i = 1; i <= n; i++)
        {
            if (m.find(i) == m.end())
            {
                ans[1] = i;
                break;
            }
        }

        return ans;
    }
};