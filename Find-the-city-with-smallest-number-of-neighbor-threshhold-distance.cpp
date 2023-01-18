class Solution {  // floyd algo
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dis(n,vector<int>(n,1e9));
        
        for(auto it :edges) // amking matrix
        {
            dis[it[0]][it[1]]=it[2];
            dis[it[1]][it[0]]=it[2];
        }
        
        for(int i=0;i<n;i++) 
            dis[i][i]=0;
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dis[i][k]==1e9 || dis[k][j]==1e9)
                    {
                        continue;   
                    }
                    dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
                }
            }
        }
        int countCity=n;
        int cityNo=-1;
        for(int i=0;i< n;i++) // counting cities
        {
            int count=0;
            for(int adjCity=0;adjCity<n;adjCity++){
                if(dis[i][adjCity]<=distanceThreshold)  
                {
                    count++;
                }
            }
            if(count<=countCity)
            {
                countCity=count;
                cityNo=i;
            }
        }
        return cityNo;
    }
};