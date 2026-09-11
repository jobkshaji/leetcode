class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int bmax=0;
        int bmin=0;
        int maxc=INT_MIN;
        int minc=INT_MAX;
        for(int i=0;i<n;i++){
            bmax=max(bmax+nums[i],nums[i]);
            maxc=max(maxc,bmax);

            bmin=min(bmin+nums[i],nums[i]);
            minc=min(minc,bmin);
        }
        if(maxc<0){
            return maxc;
        }else{
            return max(maxc,sum-minc);
        }
    }
};