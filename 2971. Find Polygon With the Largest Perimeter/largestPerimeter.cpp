class Solution
{
public:
    long long largestPerimeter(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());
        long long sum = 0;
        int ans = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (sum > nums[i])
            {
                ans = nums[i] + sum;
            }
            sum += nums[i];
        }

        return ans;
    }
};