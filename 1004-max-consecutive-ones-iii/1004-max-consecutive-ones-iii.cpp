class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int h=0;
        int cnt=0;
        int zeros=0;
        for(int h=0;h<nums.size();h++){
            if(nums[h]==0) zeros++;
            while(zeros>k){
                if(nums[l]==0){
                    zeros--;
                }
                l++;
            }
            cnt=max(cnt,h-l+1);
        }
        return cnt;
    }
};