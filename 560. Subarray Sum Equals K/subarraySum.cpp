class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {

        unordered_map<int, int> m;
        int preSum = 0, cnt = 0;
        for (auto it : nums)
        {
            preSum += it;
            if (preSum == k)
            {
                cnt++;
            }
            if (m.find(preSum - k) != m.end())
            {
                cnt += m[preSum - k];
            }
            m[preSum]++;
        }
        return cnt;
    }
};