class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int mid=0;
        int j=n-1;
        while(mid<=j){
            if(nums[mid]==1) mid++;
            else if(nums[mid]==0){
                swap(nums[mid],nums[i]);
                i++;
                mid++;
            }else{
                swap(nums[mid],nums[j]);
                j--;
            }
        }
    }
};