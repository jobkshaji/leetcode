class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>>eng;
        for(int i=0;i<speed.size();i++){
            eng.push_back({efficiency[i],speed[i]});
        }
        sort(eng.begin(),eng.end(),[](auto &a,auto &b){
            return a.first>b.first;
        });
        priority_queue<int,vector<int>,greater<int>>pq;
        long long speedsum=0;
        long long ans=0;
        for(auto x:eng){
            int ef=x.first;
            speedsum+=x.second;
            pq.push(x.second);
            if(pq.size()>k){
                speedsum-=pq.top();
                pq.pop();
            }
            long long current = 1LL*ef*speedsum;
            ans=max(current,ans);
        }
        const int MOD = 1e9 + 7;
        return ans % MOD;
    }
};