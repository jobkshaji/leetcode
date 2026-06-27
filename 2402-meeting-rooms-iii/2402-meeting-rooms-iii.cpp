class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int>res(n,0);
        priority_queue<int,vector<int>,greater<int>>free;
        for(int i=0;i<n;i++){
            free.push(i);
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>busy;
        sort(meetings.begin(),meetings.end());
        for(auto x:meetings){
            long long currentstart=x[0];
            long long end=x[1];
            while(!busy.empty() && busy.top().first<=currentstart){
                free.push(busy.top().second);
                busy.pop();
            }
            if(!free.empty()){
                busy.push({end,free.top()});
                res[free.top()]++;
                free.pop();
            }else{
                pair<long long,int>p=busy.top();
                busy.pop();
                int dura=end-currentstart;
                long long newend=p.first+dura;
                busy.push({newend,p.second});
                res[p.second]++;
            }
        }
        int ans=0;
        for(int i=1;i<res.size();i++){
            if(res[i]>res[ans]){
                ans=i;
            }
        }
        return ans;
    }
};