class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[n + 1];
        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> dis(n + 1, 1e9);
        vector<int> parent(n + 1);
        for (int i = 0; i < n; i++) parent[i] = i;
        dis[1] = 0;
        pq.push({0, 1});
        
        while (!pq.empty())
        {
            auto it = pq.top();
            int wt = it.first;
            int node = it.second;
            pq.pop();
        
            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edgeWt = it.second;
                if (wt + edgeWt < dis[adjNode])
                {
                    dis[adjNode] = wt + edgeWt;
                    pq.push({wt + edgeWt, adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        if (dis[n] == 1e9)
            return {-1};
        
        vector<int> path;
        
        int node = n;
        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        return path;
    }
};