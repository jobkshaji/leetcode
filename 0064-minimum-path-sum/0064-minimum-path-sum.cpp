class Solution {
public:
    int sum1(vector<vector<int>>&grid,int i,int j,int n,int m,vector<vector<int>>&dp){
        if(i==n-1 && j==m-1) return grid[i][j];
        if(i>=n || j>=m) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        int c1=sum1(grid,i,j+1,n,m,dp);
        int c2=sum1(grid,i+1,j,n,m,dp);
        return dp[i][j]=grid[i][j]+ min(c1,c2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return sum1(grid,0,0,n,m,dp);
    }
};