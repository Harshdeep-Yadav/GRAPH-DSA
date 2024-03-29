class Solution{
    public:
vector<int>topoSort(int k, vector<int>adj[]) {
        vector<int>indegree(k);
        for(int i=0;i<k;i++) {
            for(auto j: adj[i])
                indegree[j]++;
        }
        queue<int>q;
        for(int i=0;i<k;i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        vector<int>topo;
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            topo.push_back(p);
            for(auto i: adj[p]) {
                indegree[i]--;
                if(indegree[i] == 0)
                    q.push(i);
            }
        }
        return topo;
    }
    string findOrder(string dict[], int n, int k) {
        vector<int>adj[k];
        for(int i=0;i<n-1;i++) {
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.size(),s2.size());
            for(int j=0;j<len;j++) {
                if(s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }
        
        vector<int>topo = topoSort(k,adj);
        string s;
        for(auto i: topo) 
            s += (i + 'a');
            
        return s;
    }
    // public:
    // vector<int>topoSort(int V,vector<int>adj[]){
        
    //  vector<int>indegree(V);
        
    //     for(int i =0;i<V;i++)
    //     {
    //         for(auto it:adj[i])
    //         {
    //             indegree[it]++;
    //         }
    //     }
    //     queue<int>q;
    //     for(int i=0;i<V;i++)
    //     {
    //         if(indegree[i]==0)
    //          q.push(i);
    //     }
        
    //     vector<int>topo;
    //     while(!q.empty())
    //     {
    //         auto node =q.front();
    //         q.pop();
            
    //         topo.push_back(node);
	        
	   //     for(auto it : adj[node])
	   //     {
	   //         indegree[it]--;
	   //         if(indegree[it]==0)
	   //         {
	   //             q.push(it);
	   //         }
	   //     }
	   // }   
	   //    return topo;
    // }
    
    
    // string findOrder(string dict[], int N, int K) {
    //     vector<int>adj[K];
    //     for(int i=0;i<N-1;i++) // till n-1 bcz we have to find the pairs
    //     {
    //         string s1=dict[i];
    //         string s2=dict[i+1];
            
    //         int len=min(s1.size(),s2.size());
            
    //         for(int p=0;p<len;i++)
    //         {
    //             if(s1[p]!=s2[p]){
    //                 adj[s1[p]-'a'].push_back(s2[p]-'a');
    //                 break;
    //             }
    //         }
    //     }
        
    //     vector<int>topo=topoSort(K,adj);
    //     string ans;
    //     for(auto it:topo)
    //     {
    //         ans=ans+char(it+'a');
    //     }
    //     return ans;
    // }
};