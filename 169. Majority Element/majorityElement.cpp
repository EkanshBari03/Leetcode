class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {

        unordered_map<int, int> m;
        for (auto c : nums)
        {
            m[c]++;
        }
        priority_queue<pair<int, int>> maxh;
        for (auto it : m)
        {
            maxh.push({it.second, it.first});
        }
        int pivot = nums.size() / 2;
        while (maxh.size() > 0)
        {
            if (maxh.top().first > pivot)
                return maxh.top().second;
        }
        return -1;
    }
};