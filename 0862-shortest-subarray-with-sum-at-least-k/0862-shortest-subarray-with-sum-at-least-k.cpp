class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<long long,int>>q;
        int res=INT_MAX;
        long long cursum=0;
        for(int i=0;i<nums.size();i++){
            cursum+=nums[i];
            if(cursum>=k){
                res=min(res,i+1);
            }
            while(!q.empty() and cursum-q.front().first>=k){
                pair<long long,int>p=q.front();
                q.pop_front();
                int idx=p.second;
                res=min(res,i-idx);
            }
            while(!q.empty() && q.back().first>cursum){
                q.pop_back();
            }
            q.push_back({cursum,i});
        }
        if (res==INT_MAX) return -1;
        return res;
    }
};