class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {

        vector<int> ans;
        string s = "123456789";
        int n = s.size();
        for (int len = 2; len <= n; len++)
        {
            for (int startInd = 0; startInd <= n - len; startInd++)
            {
                string temp = s.substr(startInd, len);
                int val = stoi(temp);

                if (val >= low && val <= high)
                    ans.push_back(val);
            }
        }
        return ans;
    }
};