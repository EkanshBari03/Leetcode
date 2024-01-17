class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {

        priority_queue<int> maxh;
        unordered_map<int, int> m;
        for (auto it : arr)
        {
            m[it]++;
        }
        for (auto it : m)
        {
            maxh.push(it.second);
        }
        int prev = -1;
        while (maxh.size() > 0)
        {
            if (prev == maxh.top())
                return false;
            prev = maxh.top();
            maxh.pop();
        }
        return true;
    }
};