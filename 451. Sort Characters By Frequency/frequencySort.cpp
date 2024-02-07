class Solution
{
public:
    string frequencySort(string s)
    {

        priority_queue<pair<int, string>> maxh;
        unordered_map<int, string> m;
        for (auto c : s)
        {
            m[c - 'a'].push_back(c);
        }

        for (auto it : m)
        {
            maxh.push({it.second.size(), it.second});
        }

        string ans = "";

        while (maxh.size() > 0)
        {
            ans += maxh.top().second;
            maxh.pop();
        }
        return ans;
    }
};