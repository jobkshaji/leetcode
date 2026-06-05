class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ressum=0;
        int maxdif=INT_MAX;
        for(int i=0;i<n-2;i++){
            if(i>0 and nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                int diff=abs(target-sum);
                if(maxdif>diff){
                    maxdif=diff;
                    ressum=sum;
                }
                if(sum==target) return sum;
                else if(sum<target) j++;
                else k--;
            }
        }
        return ressum;
    }
};