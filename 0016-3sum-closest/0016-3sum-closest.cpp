class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int resum=0;
        int maxdiff=INT_MAX;
        for(int i=0;i<n;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                int diff=abs(sum-target);
                if(maxdiff>diff){
                    maxdiff=diff;
                    resum=sum;
                }
                if(sum==target) return sum;
                else if(sum<target) j++;
                else k--;
            }
        }
        return resum;
    }
};