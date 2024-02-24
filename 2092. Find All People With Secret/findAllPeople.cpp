class Solution
{
public:
    typedef pair<int, int> P;
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
    {

        // meke adj list
        unordered_map<int, vector<P>> adj;

        for (auto it : meetings)
        {
            int p1 = it[0];
            int p2 = it[1];
            int t = it[2];

            adj[p1].push_back({p2, t});
            adj[p2].push_back({p1, t});
        }

        queue<P> que;
        que.push({0, 0});
        que.push({firstPerson, 0});

        vector<int> timeOfSecrete(n, INT_MAX);

        timeOfSecrete[0] = 0;
        timeOfSecrete[firstPerson] = 0;

        while (!que.empty())
        {
            int person = que.front().first;
            int time = que.front().second;
            que.pop();

            for (auto ngbr : adj[person])
            {
                int nextPerson = ngbr.first;
                int meetTime = ngbr.second;

                if (meetTime >= time && timeOfSecrete[nextPerson] > meetTime)
                {
                    timeOfSecrete[nextPerson] = meetTime;
                    que.push({nextPerson, meetTime});
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (timeOfSecrete[i] != INT_MAX)
                ans.push_back(i);
        }

        return ans;
    }
};