class Solution {
public:
    bool check(int n,vector<vector<pair<int,int>>>&a,int limit,vector<bool>&online,long long k){
        vector<long long>dist(n,LLONG_MAX);
        priority_queue<pair<long long ,int>,vector<pair<long long ,int>>,greater<pair<long long,int>>>pq;
        dist[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            pair<long long ,int>p=pq.top();
            pq.pop();
            long long d=p.first;
            int node=p.second;
            if(d>dist[node]) continue;
            for(int j=0;j<a[node].size();j++){
                int nx=a[node][j].first;
                long long wt=a[node][j].second;
                if(wt<limit) continue;
                if(nx!=0 && nx!=n-1 && !online[nx]) continue;
                if(d+wt<dist[nx]){
                    dist[nx]=d+wt;
                    pq.push({d+wt,nx});
                }
            }   
        }
        return dist[n-1]<=k;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
        int low=INT_MAX;
        int high=0;
        vector<vector<pair<int,int>>>a(n);
        for(int i=0;i<edges.size();i++){
            int s=edges[i][0];
            int d=edges[i][1];
            int w=edges[i][2];
            a[s].push_back({d,w});
            low=min(low,w);
            high=max(high,w);
        }
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(n,a,mid,online,k)){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
        
    }
};