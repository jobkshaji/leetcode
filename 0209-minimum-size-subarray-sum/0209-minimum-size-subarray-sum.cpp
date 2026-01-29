class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0;
        int h=0;
        int res=INT_MAX;
        int n=nums.size();
        int sum=0;
        while(h<n){
            sum=sum+nums[h];
            while(sum>=target){
                int len=h-l+1;
                res=min(len,res);
                sum=sum-nums[l];
                l++;
            }
            h++;
        }
        if(res==INT_MAX){
            return 0;
        } else {
            return res;
        }
    }
};