class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ma=nums[0];
        int mi=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            int v1=nums[i];
            int v2=ma*nums[i];
            int v3=mi*nums[i];
            ma=max(v1,max(v2,v3));
            mi=min(v1,min(v2,v3));
            ans=max(ans,max(ma,mi));
        }
        return ans;
    }
};