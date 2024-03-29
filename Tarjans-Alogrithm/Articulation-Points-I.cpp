class Solution {
    private: 
    int timer=0;
    private:
    void dfs(int node ,int parent ,vector<int>&vis,vector<int>adj[],int tin[],int low[],vector<int>&mark){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        int child=0;
        for(auto it: adj[node]){
            if(it==parent) continue;
            
            if(!vis[it]){
                dfs(it,node,vis,adj,tin,low,mark);
                low[node]=min(low[node],low[it]);
                if(low[it]>=tin[node]&& parent!=-1){
                    mark[node]=1;
                }
                child++;
            }
            else{
                low[node]=min(low[node],tin[it]);
            }
        }
        if(child>1 && parent ==-1){
            mark[node]=1;
        }
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int>vis(V,0);
        int tin[V];
        int low[V];
        vector<int>mark(V,0); // marking articulation node
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,-1,vis,adj,tin,low,mark);
            }
        }
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(mark[i]==1){
                ans.push_back(i);
            }
        }
        if(ans.size()==0) return {-1};
        return ans;
    }
};