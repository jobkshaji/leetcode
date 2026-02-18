class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int bmax=0;
        int bmin=0;
        int maxe=INT_MIN;
        int mine=INT_MAX;
        for(int i=0;i<nums.size();i++){
            bmax=max(nums[i],bmax+nums[i]);
            maxe=max(maxe,bmax);

            bmin=min(nums[i],bmin+nums[i]);
            mine=min(mine,bmin);  
        }
        if(maxe==INT_MIN || mine==INT_MIN){
            return 1;
        }
        return(max(abs(maxe),abs(mine)));
    }
};