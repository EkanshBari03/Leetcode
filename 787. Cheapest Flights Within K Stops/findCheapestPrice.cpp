class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<int>> adj[n];
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        queue<pair<int, pair<int, int>>> q;
        vector<int> dis(n, 1e9);
        q.push({0, {src, 0}});
        dis[src] = 0;
        while (q.size() > 0)
        {
            auto it = q.front();
            q.pop();
            int step = it.first;
            int node = it.second.first;
            int dist = it.second.second;
            for (auto ele : adj[node])
            {
                int adjNode = ele[0];
                int edgeW = ele[1];
                if (dist + edgeW < dis[adjNode] && step <= k)
                {
                    dis[adjNode] = dist + edgeW;
                    q.push({step + 1, {adjNode, dist + edgeW}});
                }
            }
        }

        return dis[dst] == 1e9 ? -1 : dis[dst];
    }
};