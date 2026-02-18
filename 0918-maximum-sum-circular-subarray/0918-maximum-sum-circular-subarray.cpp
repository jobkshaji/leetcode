class Solution {
public:
    int sumofarray(vector<int>&nums){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        return sum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int bmax=nums[0];
        int bmin=nums[0];
        int maxe=nums[0];
        int mine=nums[0];
        for(int i=1;i<nums.size();i++){
            bmax=max(nums[i],bmax+nums[i]);
            maxe=max(maxe,bmax);

            bmin=min(nums[i],bmin+nums[i]);
            mine=min(bmin,mine);
        }
        int sum=sumofarray(nums);
        if(maxe<0){
            return maxe;
        }else{
            int maxsum=sum-mine;
            return(max(maxsum,maxe));
        }
    }
};