class Solution {
public:
    int fun(string &a,string &b , int i,int j,int n,int m, vector<vector<int>>&dp){
        if(i==n) return m-j;
        if(j==m) return n-i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(a[i]==b[j]){
            return dp[i][j]=fun(a,b,i+1,j+1,n,m,dp);
        }
        int insert=fun(a,b,i,j+1,n,m,dp);
        int delete1=fun(a,b,i+1,j,n,m,dp);
        int replace=fun(a,b,i+1,j+1,n,m,dp);
        return dp[i][j]=1+min({insert,delete1,replace});
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return fun(word1,word2,0,0,n,m,dp);
    }
};