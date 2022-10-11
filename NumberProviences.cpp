class Solution {
  public:
  void dfs(int node,vector<int> lis[],int vis[])
  {
      vis[node]=1;
      for(auto it:lis[node])
      {
          if(!vis[it])
          {
              dfs(it,lis,vis);
          }
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int>lis[V];
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adj[i][j]==1&&i!=j)
                {
                    lis[i].push_back(j);
                    lis[j].push_back(i);
                }
            }
        }
        int vis[V]={0};
        int count=0;
        for(int i=0;i<V;i++)
        { 
            if(vis[i]==0)
            {
               count++; 
               dfs(i,lis,vis);
            }
        }
        return count;
    }
};