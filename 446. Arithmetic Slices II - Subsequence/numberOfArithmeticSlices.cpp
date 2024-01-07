class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();

        int result = 0;

        unordered_map<long, int> m[n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                long diff = (long)nums[i] - nums[j];

                auto it = m[j].find(diff);

                int count_at_j = it == end(m[j]) ? 0 : it->second;
                ;

                m[i][diff] += count_at_j + 1;

                result += count_at_j;
            }
        }

        return result;
    }
};