class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int>free;
        for(int i=0;i<k;i++){
            free.insert(i);
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>busy;
        vector<int>cnt(k,0);
        for(int i=0;i<arrival.size();i++){
            while(!busy.empty() && busy.top().first<=arrival[i]){
                free.insert(busy.top().second);
                busy.pop();
            }
            int start=i%k;
            if(free.empty()) continue;
            auto it=free.lower_bound(start);
            if(it==free.end()){
                it=free.begin();
            }
            int server=*it;
            free.erase(it);
            busy.push({(long long)arrival[i]+load[i],server});
            cnt[server]++;
        }
        int mx=*max_element(cnt.begin(),cnt.end());
        vector<int>ans;
        for(int i=0;i<cnt.size();i++){
            if(cnt[i]==mx){
                ans.push_back(i);
            }
        }
        return ans;
    }
};