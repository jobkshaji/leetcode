class Solution {
public:
    unordered_map<int,int>dp;
    int climb(int i,int n){
        if(i==n) return 1;
        if(i>n) return 0;
        if(dp.find(i)!=dp.end()){
            return dp[i];
        }
        int ans=climb(i+1,n)+climb(i+2,n);
        dp[i]=ans;
        return ans;
    }
    int climbStairs(int n) {
        return climb(0,n);
    }
};