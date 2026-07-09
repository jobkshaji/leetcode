class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>group(n);
        int id=0;
        group[0]=0;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]>maxDiff){
                id++;
            }
            group[i]=id;
        }

        vector<bool>ans;
        for(auto i:queries){
            ans.push_back(group[i[0]]==group[i[1]]);
        }
        return ans;
    }
};