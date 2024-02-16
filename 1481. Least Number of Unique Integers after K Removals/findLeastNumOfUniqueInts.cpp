class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;
        unordered_map<int, int> m;
        for (auto it : arr)
        {
            m[it]++;
        }

        for (auto it : m)
        {
            minh.push({it.second, it.first});
        }

        while (minh.size() > 0)
        {
            if (minh.top().first <= k)
            {
                k -= minh.top().first;
                minh.pop();
            }
            else if (minh.top().first > k)
            {
                break;
            }
        }

        return minh.size();
    }
};