class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n);
        int mx=nums[0];
        for(int i=0;i<n;i++){
            mx=max(nums[i],mx);
            prefix[i]=gcd(nums[i],mx);
        }
        sort(prefix.begin(),prefix.end());
        int l=0;
        int h=n-1;
        long long sum=0;
        while(l<h){
            sum=sum+gcd(prefix[l],prefix[h]);
            l++;
            h--;
        }
        return sum;
    }
};