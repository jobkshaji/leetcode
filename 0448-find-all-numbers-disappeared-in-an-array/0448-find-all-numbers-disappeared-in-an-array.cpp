class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<bool>seen(n+1);
        vector<int>ans;
        for(auto&i:nums){
            seen[i]=true;
        }
        for(int i=1;i<=n;i++){
            if(!seen[i]) ans.push_back(i);
        }
        return ans;
    }
};