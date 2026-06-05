class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;

        long long prod=1;
        int i=0;
        int cnt=0;
        for(int r=0;r<nums.size();r++){
            prod*=nums[r];
            while(prod>=k){
                prod/=nums[i];
                i++;
            }
            cnt+=(r-i+1);
        }
        return cnt;

    }
};