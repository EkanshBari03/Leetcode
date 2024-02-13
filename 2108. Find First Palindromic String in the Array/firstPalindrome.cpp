class Solution
{
public:
    string firstPalindrome(vector<string> &words)
    {

        string ans;

        for (auto ch : words)
        {
            bool flag = true;
            for (int i = 0, j = ch.size() - 1; i < j; i++, j--)
            {
                if (ch[i] != ch[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                ans += ch;
                break;
            }
        }
        return ans;
    }
};