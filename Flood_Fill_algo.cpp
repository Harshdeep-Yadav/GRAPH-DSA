class Solution {
public:
void dfs(int row,int col,vector<vector<int>>& image,vector<vector<int>>& ans,int newColor,int delrow[],int delcol[],int inColor)
{
    ans[row][col]=newColor;
    int n=image.size();
    int m=image[0].size();
    
    for(int i=0;i<4;i++)
    {
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
        if(nrow>=0 &&nrow<n&&ncol>=0&&ncol<m && ans[nrow][ncol]!=newColor&&image[nrow][ncol]==inColor)
        {
            dfs(nrow,ncol,image,ans,newColor,delrow,delcol,inColor);
        }
    }
    
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>>ans =image;
        int inColor=image[sr][sc];
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        dfs(sr,sc,image,ans,newColor,delrow,delcol,inColor);
        return ans;
    }
};