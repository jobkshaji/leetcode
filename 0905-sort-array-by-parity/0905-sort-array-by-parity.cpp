class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n);
        int l=0;
        int r=n-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                res[l++]=nums[i];
            }else{
                res[r--]=nums[i];
            }
        }
        return res;
    }
};