class Solution {
  public:
  void dfs(int node,vector<int>adj[],int vis[],vector<int>&store)
  {
      vis[node]=1;
      store.push_back(node);
      for(auto it:adj[node])
      {
          if(!vis[it])
          {
              dfs(it,adj,vis,store);
          }
      }
  }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
            int vis[V]={0};
            vector<int>store;
            int start=0;
            dfs(start,adj,vis,store);
            return store;
    }
};