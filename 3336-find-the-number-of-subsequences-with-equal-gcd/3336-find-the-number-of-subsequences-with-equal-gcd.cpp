class Solution {
public:
    long long mod=1e9+7;
    int dfs(vector<int>&nums,int n,int i,int g1, int g2,vector<vector<vector<int>>>&dp){
        if(i==n){
            if(g1==g2 && g1!=0) return 1;
            return 0;
        }
        if(dp[i][g1][g2]!=-1){
            return dp[i][g1][g2];
        }
        long long ans=0;
        int x=nums[i];
        ans+=dfs(nums,n,i+1,g1,g2,dp);
        ans+=dfs(nums,n,i+1,gcd(g1,x),g2,dp);
        ans+=dfs(nums,n,i+1,g1,gcd(g2,x),dp);
        return dp[i][g1][g2]=ans%mod;
        

    }
    int subsequencePairCount(vector<int>& nums) {
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(mx+1,vector<int>(mx+1,-1)));
        return dfs(nums,n,0,0,0,dp);
    }
};