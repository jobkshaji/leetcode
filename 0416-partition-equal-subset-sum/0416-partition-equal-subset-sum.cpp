class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        int s1=sum/2;
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(s1+1,-1));
        for(int i=0;i<=s1;i++){
            dp[n][i]=0;
        }
        dp[n][0]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=s1;j++){
                if(nums[i]>j){
                    dp[i][j]=dp[i+1][j];
                }else{
                    dp[i][j]=dp[i+1][j-nums[i]] || dp[i+1][j];
                }
            }
        }
        return dp[0][s1];
    }
};