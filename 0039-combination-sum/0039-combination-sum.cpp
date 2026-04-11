class Solution {
public:
    void backtrack(int idx,vector<int>&candidates,int target , vector<int>&curr,vector<vector<int>>&result){
        if(target==0){
            result.push_back(curr);
            return;
        }
        if(idx>=candidates.size() || target < 0) return;
        curr.push_back(candidates[idx]);
        backtrack(idx,candidates,target-candidates[idx],curr,result);
        curr.pop_back();
        backtrack(idx+1,candidates,target,curr,result);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>curr;
        vector<vector<int>>result;
        backtrack(0,candidates,target,curr,result);
        return result;
    }
};