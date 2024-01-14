class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {

        vector<int> f1(26), f2(26), w1(26), w2(26);

        for (auto it : word1)
        {
            f1[it - 'a']++, w1[it - 'a'] = 1;
        }
        for (auto it : word2)
        {
            f2[it - 'a']++, w2[it - 'a'] = 1;
        }
        sort(f1.begin(), f1.end());
        sort(f2.begin(), f2.end());

        return f1 == f2 && w1 == w2;
    }
};