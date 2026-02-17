class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxn=nums[0];
        int minn=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            int v1=nums[i];
            int v2=maxn*nums[i];
            int v3=minn*nums[i];
            maxn=max(v1,max(v2,v3));
            minn=min(v1,min(v2,v3));
            ans=max(ans,max(maxn,minn));
        }
        return ans;
    }
};