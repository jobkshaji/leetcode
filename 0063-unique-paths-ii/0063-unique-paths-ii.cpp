class Solution {
public:
    int fun(vector<vector<int>>&grid,int i,int j,int n,int m,vector<vector<int>>&dp){
        if(i>=n || j>=m) return 0;
        if(i==n-1 && j==m-1 && grid[i][j]==0){
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(grid[i][j]==1) return 0;
        int c1=fun(grid,i+1,j,n,m,dp);
        int c2=fun(grid,i,j+1,n,m,dp);
        return dp[i][j]=c1+c2;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return fun(grid,0,0,n,m,dp);
    }
};