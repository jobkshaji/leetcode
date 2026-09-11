class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int left=0;
        for(int i=0;i<n;i++){
            int right=sum-nums[i]-left;
            if(right==left) return i;
            left+=nums[i];
        }
        return -1;
    }
};