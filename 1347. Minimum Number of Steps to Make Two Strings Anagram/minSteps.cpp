class Solution
{
public:
    int minSteps(string s, string t)
    {

        map<char, int> m;
        for (auto it : s)
        {
            m[it]++;
        }
        int cnt = 0;
        for (auto it : t)
        {
            if (m.find(it) != m.end())
            {
                m[it]--;
                if (m[it] < 0)
                    cnt++;
            }
            else
            {
                cnt++;
            }
        }
        return cnt;
    }
};