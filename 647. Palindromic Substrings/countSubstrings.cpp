class Solution
{
public:
    int solve(string s, int l, int h)
    {
        int res = 0;
        while (l >= 0 && h < s.size() && s[l--] == s[h++])
            res++;

        return res;
    }
    int countSubstrings(string s)
    {

        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {

            // for odd length palindrom
            ans += solve(s, i, i);
            // for even length palindrom
            ans += solve(s, i, i + 1);
        }
        return ans;
    }
};