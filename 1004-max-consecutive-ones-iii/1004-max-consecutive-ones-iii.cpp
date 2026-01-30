class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int h=0,l=0;
        int n=nums.size();
        int maxcnt=0;
        int zeroes=0;
        for(int h=0;h<n;h++){
            if(nums[h]==0) zeroes++;
            while(zeroes>k){
                if(nums[l]==0)zeroes--;
                l++;
            }
            maxcnt=max(maxcnt,h-l+1);
        }
        return maxcnt;
    }
};