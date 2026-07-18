class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n=nums.size();
        int mini=nums[0];
        int maxi=nums[0];
        for(int i=1;i<n;i++){
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }
        return gcd(mini,maxi);
    }
};