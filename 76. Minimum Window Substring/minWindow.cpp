class Solution
{
public:
    string minWindow(string s, string t)
    {

        if (s.length() < t.length())
            return "";
        unordered_map<char, int> mp;
        for (int i = 0; i < t.size(); i++)
        {
            mp[t[i]]++;
        }
        int count = t.size();
        int minWindowSize = INT_MAX;
        int start_ind = 0;
        int i = 0, j = 0;
        string ans;
        while (j < s.size())
        {
            char c = s[j];

            if (mp[c] > 0)
            {
                count--;
            }
            mp[c]--;

            while (count == 0)
            {

                int curWindowSize = j - i + 1;
                if (curWindowSize < minWindowSize)
                {
                    minWindowSize = curWindowSize;
                    start_ind = i;
                }
                mp[s[i]]++;
                if (mp[s[i]] > 0)
                {
                    count++;
                }
                i++;
            }
            j++;
        }
        return minWindowSize == INT_MAX ? "" : s.substr(start_ind, minWindowSize);
    }
};