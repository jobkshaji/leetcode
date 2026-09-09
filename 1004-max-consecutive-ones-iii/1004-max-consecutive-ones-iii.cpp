class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros=0;
        int l=0;
        int cnt=INT_MIN;
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
        return(cnt==INT_MIN)?0:cnt;
    }
};