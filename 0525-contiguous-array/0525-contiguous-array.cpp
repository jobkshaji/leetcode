class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>f;
        int zeros=0;
        int one=0;
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) zeros++;
            else one++;
            int diff=zeros-one;
            if(diff==0){
                res=max(res,i+1);
            }else{
                if(f.find(diff)==f.end()){
                    f[diff]=i;
                }else{
                    int len=i-f[diff];
                    res=max(res,len);
                }
            }
        }
        return res;
    }
};