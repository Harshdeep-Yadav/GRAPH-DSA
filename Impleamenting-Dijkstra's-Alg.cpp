class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dis(V);
        for (int i = 0; i < V; i++)
            dis[i] = 1e9;

        dis[S] = 0;      // source node
        pq.push({0, S}); // pushing into pq;

        while (!pq.empty())
        {

            int wt = pq.top().first; //
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node])
            {
                int edgeWt = it[1]; // {1,9} then edgeWt=9
                int adjNode = it[0];

                if (wt + edgeWt < dis[adjNode])
                {
                    dis[adjNode] = wt + edgeWt;
                    pq.push({dis[adjNode], adjNode});
                }
            }
        }
        return dis;
    }
};


