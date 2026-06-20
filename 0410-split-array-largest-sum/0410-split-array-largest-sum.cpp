class Solution {
public:
    bool valid(vector<int>&nums,int mid,int k,int n){
        int j=1;
        int sum=0;
        for(int i=0;i<n;i++){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }else{
                j++;
                sum=nums[i];
            }
        }
        if(j>k) return false;
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        int h=0;
        for(int i=0;i<n;i++){
            h+=nums[i];
        }
        int res=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(valid(nums,mid,k,n)){
                res=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return res;
    }
};