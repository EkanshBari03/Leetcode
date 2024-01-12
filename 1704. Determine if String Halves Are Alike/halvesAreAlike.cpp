class Solution
{
public:
    bool halvesAreAlike(string s)
    {

        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] == 'a' || s[i] == 'A')
                cnt++;
            else if (s[i] == 'e' || s[i] == 'E')
                cnt++;
            else if (s[i] == 'i' || s[i] == 'I')
                cnt++;
            else if (s[i] == 'o' || s[i] == 'O')
                cnt++;
            else if (s[i] == 'u' || s[i] == 'U')
                cnt++;
        }
        for (int i = n / 2; i < n; i++)
        {
            if (s[i] == 'a' || s[i] == 'A')
                cnt--;
            else if (s[i] == 'e' || s[i] == 'E')
                cnt--;
            else if (s[i] == 'i' || s[i] == 'I')
                cnt--;
            else if (s[i] == 'o' || s[i] == 'O')
                cnt--;
            else if (s[i] == 'u' || s[i] == 'U')
                cnt--;
        }

        return cnt == 0 ? true : false;
    }
};