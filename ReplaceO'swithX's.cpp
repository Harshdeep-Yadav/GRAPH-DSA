class Solution{
 public:

 
    // void dfs(int row,int col,vector<vector<char>>&mat,vector<vector<int>>&vis,int delrow[],int delcol[])
    // {
    //     vis[row][col]=1;
    //     int n=mat.size();
    //     int m=mat[0].size();
    
    //     for(int i=0;i<4;i++)
    //     {
    //         int nrow=row+delrow[i];
    //         int ncol=col+delcol[i];
    //         if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m && !vis[nrow][ncol] && mat[nrow][ncol]=='O')
    //         {
    //             dfs(nrow,ncol,mat,vis,delrow,delcol);
    //         }
    //     }
    // }
    // vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    // {
    //     vector<vector<int>> vis(n,vector<int>(m,0));
    //       int delrow[]={-1,0,1,0};
    //       int delcol[]={0,1,0-1};
    //     // traversing frist row and last column
    //     for(int j=0;j<m;j++)
    //     {
    //         // first row
    //         if(!vis[0][j]&&mat[0][j]=='O')
    //         {
    //             dfs(0,j,mat,vis,delrow,delcol);
    //         }
    //         // last row
    //         if(!vis[n-1][j]&&mat[n-1][j]=='O')
    //         {
    //             dfs(n-1,j,mat,vis,delrow,delcol);
    //         }
    //     }
        
    //     // for traversing first col and last column
    //     for(int i=0;i<n;i++)
    //     {
    //         // first column
    //         if(!vis[i][0] &&mat[i][0]=='O')
    //         {
    //             dfs(i,0,mat,vis,delrow,delcol);
    //         }
    //         // last column
    //         if(!vis[i][m-1] &&mat[i][m-1]=='O')
    //         {
    //             dfs(i,m-1,mat,vis,delrow,delcol);
    //         }
    //     }
        
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<m;j++)
    //         {
    //             if(!vis[i][j] && mat[i][j]=='O')
    //             {
    //                 mat[i][j]='X';
    //             }
    //         }
    //     }
        // return mat;
         int delrow[4]={-1,0,1,0};
    int delcol[4]={0,-1,0,1};
    void dfs(int r,int c,vector<vector<int>> &vis,int n,int m,vector<vector<char>> &grid){
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int nr=r+delrow[i];
            int nc=c+delcol[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]=='O'){
                dfs(nr,nc,vis,n,m,grid);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> grid)
    {
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(!vis[0][j] && grid[0][j]=='O'){
                dfs(0,j,vis,n,m,grid);
            }
            if(!vis[n-1][j] && grid[n-1][j]=='O'){
                  dfs(n-1,j,vis,n,m,grid);
            }
        }
        for(int i=0;i<n;i++){
             if(!vis[i][0] && grid[i][0]=='O'){
                dfs(i,0,vis,n,m,grid);
            }
            if(!vis[i][m-1] && grid[i][m-1]=='O'){
                dfs(i,m-1,vis,n,m,grid);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='O'){
                    grid[i][j]='X';
                }
            }
        }
        return grid;
    
    }
};
