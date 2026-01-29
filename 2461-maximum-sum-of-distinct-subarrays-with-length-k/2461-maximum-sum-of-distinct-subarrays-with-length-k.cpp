class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int l=0,h=k-1;
        int n=nums.size();
        long long cur=0,maxs=0;
        for(int i=0;i<=h;i++){
            cur+=nums[i];
            mp[nums[i]]++;
        }
        if(mp.size()==k){
            maxs=cur;
        }
        for(int h=k;h<n;h++){
            cur-=nums[l];
            mp[nums[l]]--;
            if(mp[nums[l]]== 0){
                mp.erase(nums[l]);
            }
            l++;
            cur+=nums[h];
            mp[nums[h]]++;
            if(mp.size()==k){
                maxs=max(maxs,cur);
            }
        }
        return maxs;
    }
};