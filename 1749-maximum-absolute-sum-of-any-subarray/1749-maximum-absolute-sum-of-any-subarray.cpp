class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int bmax=0;
        int bmin=0;
        int maxc=INT_MIN;
        int minc=INT_MAX;
        for(int i=0;i<nums.size();i++){
            bmax=max(nums[i],bmax+nums[i]);
            maxc=max(maxc,bmax);

            bmin=min(nums[i],bmin+nums[i]);
            minc=min(minc,bmin);
        }
        if(maxc==INT_MIN || minc==INT_MAX){
            return 1;
        }
        return max(abs(maxc),abs(minc));
    }
};