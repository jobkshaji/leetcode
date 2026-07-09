class Solution {
public:
    int fun(vector<int>&nums,int i, int n,int free,vector<vector<int>>&dp){
        if(i==n) return 0;
        if(dp[i][free]!=-1){
            return dp[i][free];
        }
        if(free==0){
            return dp[i][free]=fun(nums,i+1,n,1,dp);
        }
        int c1=nums[i]+fun(nums,i+1,n,0,dp);
        int c2=fun(nums,i+1,n,1,dp);
        return dp[i][free]=max(c1,c2);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp1(n);
        vector<vector<int>>dp2(n);
        for(int i=0;i<n;i++){
            vector<int>t(2,-1);
            dp1[i]=t;
            dp2[i]=t;
        }
        if(n==1){
            return nums[0];
        }
        int c1= fun(nums,0,n-1,1,dp1);
        int c2=fun(nums,1,n,1,dp2);
        return max(c1,c2);
    }
};