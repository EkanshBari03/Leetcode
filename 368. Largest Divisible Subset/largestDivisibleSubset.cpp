class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<int> t(n, 1);

        vector<int> prev_ind(n, -1);

        int lastIndex = 0;
        int maxL = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0)
                {
                    if (t[i] < t[j] + 1)
                    {
                        t[i] = t[j] + 1;
                        prev_ind[i] = j;
                    }
                    if (t[i] > maxL)
                    {
                        maxL = t[i];
                        lastIndex = i;
                    }
                }
            }
        }

        vector<int> ans;
        while (lastIndex != -1)
        {
            ans.push_back(nums[lastIndex]);
            lastIndex = prev_ind[lastIndex];
        }
        return ans;
    }
};