class Solution {
public:
    int sum(int i,int j, vector<vector<int>>&triangle , vector<vector<int>>&dp){
        if(i==triangle.size()-1) return triangle[i][j];
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int c1=triangle[i][j]+sum(i+1,j,triangle,dp);
        int c2=triangle[i][j]+sum(i+1,j+1,triangle,dp);
        return dp[i][j]=min(c1,c2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows=triangle.size();
        vector<vector<int>>dp;
        for(int i=0;i<rows;i++){
            dp.push_back(vector<int>(triangle[i].size(),INT_MAX));
        }
        return sum(0,0,triangle,dp);
    }
};