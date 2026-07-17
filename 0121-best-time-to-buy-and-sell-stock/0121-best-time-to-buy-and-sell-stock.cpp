class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int k=2;
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        for(int i=0;i<=k;i++){
            dp[n][i]=0;
        }
        for(int i=0;i<n;i++){
            dp[i][0]=0;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=k;j++){
                if(j==2){
                    int c1=dp[i+1][j-1]-prices[i];
                    int c2=dp[i+1][j];
                    dp[i][j]=max(c1,c2);
                }else if(j==1){
                    int c1=dp[i+1][j-1]+prices[i];
                    int c2=dp[i+1][j];
                    dp[i][j]=max(c1,c2);
                }
            }
        }
        return dp[0][k];
    }
};