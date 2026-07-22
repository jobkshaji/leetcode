class Solution {
public:
    bool solve(vector<int>&nums,int i,vector<int>&dp){
        if(i==nums.size()-1) return true;
        if(dp[i]!=-1) return dp[i];
        for(int j=1;j<=nums[i];j++){
            if(i+j<nums.size()){
                if(solve(nums,i+j,dp)){
                    return dp[i]=1;
                }
            }
        }
        return dp[i]=0;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(nums,0,dp);

    }
};