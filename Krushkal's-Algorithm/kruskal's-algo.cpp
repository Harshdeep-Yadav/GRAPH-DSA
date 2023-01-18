class DisjointSet
{
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        
        vector<pair<int,pair<int,int>>>edges;
        
        for(int i=0;i<V;i++){
            for(auto it : adj[i]){
                int adjNode=it[0];
                int wt=it[1];
                int node=i;
                
                edges.push_back({wt,{node,adjNode}});
            }
            sort(edges.begin(),edges.end());
        }
        DisjointSet ds(V);
        int mstWt=0;
        
        for(auto it: edges)
        {
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            
            
            if(ds.findUPar(u)!=ds.findUPar(v)){
                mstWt+=wt;
                ds.unionByRank(u,v);
            }
        }
        
        return mstWt;
        
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // vector<int>vis(V,0);
        // pq.push({0,0});
        // int sum=0;
        // while(!pq.empty())
        // {
        //     auto it=pq.top();
        //     pq.pop();
        //     int wt=it.first;
        //     int Node=it.second;
        //     if(vis[Node]==1) continue;
        //     vis[Node]=1;
        //     sum+=wt;
        //     for(auto it:adj[Node])
        //     {
        //         int adjNode=it[0];
        //         int edW=it[1];
                
        //         if(!vis[adjNode]){
        //             pq.push({edW,adjNode});
        //         }
        //     }
        // }
        // return sum;
    }
};