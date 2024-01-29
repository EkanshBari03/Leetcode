class Solution
{
public:
    int maximumLength(vector<int> &nums)
    {

        int ans = 0;
        map<int, int> m; // keeping frequencie sorted
        for (auto it : nums)
            m[it]++;

        for (auto it : m)
        {
            long long val = it.first;
            int count = 0;
            while (m.find(val) != m.end() && m[val])
            {
                if (val == 1)
                    count += m[val];
                else if (m[val] >= 2)
                    count += 2;
                else if (m[val] == 1)
                {
                    count += 1;
                    break;
                }
                m[val] = 0;
                if (val > 1e6)
                    break;
                val = val * val; // find next pattern value
            }
            ans = max(ans, count - (count % 2 == 0));
        }
        return ans;
    }
};