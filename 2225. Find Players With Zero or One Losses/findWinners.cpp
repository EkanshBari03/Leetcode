class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {

        unordered_map<int, int> win, lost;
        for (auto it : matches)
        {
            win[it[0]]++;
            lost[it[1]]++;
        }
        vector<vector<int>> ans;
        vector<int> w, l;
        for (auto it : win)
        {
            if (lost.find(it.first) == lost.end())
            {
                w.push_back(it.first);
            }
        }
        for (auto it : lost)
        {
            if (it.second == 1)
                l.push_back(it.first);
        }
        sort(begin(w), end(w));
        sort(begin(l), end(l));

        ans.push_back(w);
        ans.push_back(l);
        return ans;
    }
};