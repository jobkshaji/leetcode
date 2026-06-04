class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            if(i>0 and nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=n-1;
            int sum=(-1)*nums[i];
            while(j<k){
                vector<int>tmp;
                int tar=nums[j]+nums[k];
                if(tar==sum){
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[k]);
                    res.push_back(tmp);
                    j++;
                    k--;
                    while(j<n and nums[j]==nums[j-1]) j++;
                    while(k>=0 and nums[k]==nums[k+1]) k--;
                }
                else if(tar<sum) j++;
                else k--;
            }
        }
        return res;
    }
};