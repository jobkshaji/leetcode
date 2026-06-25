class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        int i=0;
        int ans=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        sort(events.begin(),events.end());
        int minday=events[0][0];
        int maxday=events[0][1];
        for(int i=0;i<n;i++) maxday=max(maxday,events[i][1]);
        for(int day=minday;day<=maxday;day++){
            while(!pq.empty() && pq.top()< day){
                pq.pop();
            }
            while(i<n && events[i][0]==day){
                pq.push(events[i][1]);
                i++;
            }
            if(!pq.empty()){
                pq.pop();
                ans++;
            }
        }
        return ans;
    }
};