class Solution {
public:
    void fun(vector<int>&a,int n,int idx,int target,int sum,vector<int>& diary,vector<vector<int>>&res){
        if(idx==n){
            if(target==sum){
                res.push_back(diary);
            }
            return;
        }
        if(a[idx]+sum<=target){
            diary.push_back(a[idx]);
            sum+=a[idx];
            fun(a,n,idx,target,sum,diary,res);
            diary.pop_back();
            sum-=a[idx];
        }
        fun(a,n,idx+1,target,sum,diary,res);
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& a, int target) {
        int n=a.size();
        int idx=0;
        int sum=0;
        vector<int>diary;
        vector<vector<int>>res;
        fun(a,n,idx,target,sum,diary,res);
        return res;
    }
};