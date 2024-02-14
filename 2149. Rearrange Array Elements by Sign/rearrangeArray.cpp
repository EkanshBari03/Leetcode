class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {

        queue<int> pos;
        queue<int> neg;
        for (auto it : nums)
        {
            if (it < 0)
            {
                neg.push(it);
            }
            else
                pos.push(it);
        }

        vector<int> ans;
        while (pos.size() > 0)
        {
            ans.push_back(pos.front());
            ans.push_back(neg.front());
            pos.pop();
            neg.pop();
        }

        return ans;
    }
};