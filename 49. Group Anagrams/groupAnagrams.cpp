class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {

        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;

        for (auto s : strs)
        {
            string st = s;
            sort(st.begin(), st.end());
            m[st].push_back(s);
        }
        for (auto it : m)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};