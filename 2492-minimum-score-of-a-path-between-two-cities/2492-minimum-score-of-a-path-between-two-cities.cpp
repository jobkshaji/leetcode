class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>a(n+1);
        for(int i=0;i<roads.size();i++){
            int s=roads[i][0];
            int d=roads[i][1];
            int wt=roads[i][2];
            a[s].push_back({d,wt});
            a[d].push_back({s,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n+1,INT_MAX);
        pq.push({INT_MAX,1});
        dist[1]=INT_MAX;
        while(!pq.empty()){
            pair<int,int>p=pq.top();
            int node=p.second;
            pq.pop();
            if(p.first>dist[p.second]) continue;
            for(int i=0;i<a[node].size();i++){
                int neigh=a[node][i].first;
                int weigh=a[node][i].second;
                int k=min(weigh,dist[neigh]);
                if(k<dist[neigh]){
                    dist[neigh]=k;
                    pq.push({k,neigh});
                }
            }
            
        }
        int mini=*min_element(dist.begin(),dist.end());
        return mini;
    }
};