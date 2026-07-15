class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int target) {
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(abs(target)>sum) return 0;
        if((sum+target)%2!=0) return 0;
        int s1=(sum+target)/2;
        vector<vector<int>>dp(n+1,vector<int>(s1+1,-1));
        for(int i=0;i<=s1;i++){
            dp[n][i]=0;
        }
        dp[n][0]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=s1;j++){
                if(arr[i]>j){
                    dp[i][j]=dp[i+1][j];
                }else{
                    dp[i][j]=dp[i+1][j-arr[i]] + dp[i+1][j];
                }
            }
        }
        return dp[0][s1];
    }
};