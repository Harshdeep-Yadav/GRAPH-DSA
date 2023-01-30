
class Solution {
    private:
    int timer=1;
    private:
    void dfs(int node,int parent,vector<int>&vis,vector<vector<int>>&bridges,vector<int>adj[],
             int tin[],int low[]){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        for(auto it : adj[node]){
            if(it==parent){
                continue;
            }
            if(vis[it]==0){ // not visited
                dfs(it,node,vis,bridges,adj,tin,low);
                low[node]=min(low[it],low[node]);//taking the low value from its adjcent                                                                                       node
                if(low[it]>tin[node]){ // agar jada hai to kam wala le lange
                    bridges.push_back({it,node});
                }
            }else{ //  visited
                low[node]=min(low[node],low[it]);
                
            }
            
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(auto it: connections){ // graph is created
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);  
        }
        vector<int>vis(n,0);
        int tin[n];
        int low[n];
        vector<vector<int>>bridges;
        dfs(0,-1,vis,bridges,adj,tin,low);
        return bridges;
    }
};