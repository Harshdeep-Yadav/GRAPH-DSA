class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>vis(V,0);
        pq.push({0,0});
        int sum=0;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int wt=it.first;
            int Node=it.second;
            if(vis[Node]==1) continue;
            vis[Node]=1;
            sum+=wt;
            for(auto it:adj[Node])
            {
                int adjNode=it[0];
                int edW=it[1];
                
                if(!vis[adjNode]){
                    pq.push({edW,adjNode});
                }
            }
        }
        return sum;
    }
};