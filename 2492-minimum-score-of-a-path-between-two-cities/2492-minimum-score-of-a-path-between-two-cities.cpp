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
        vector<bool>visit(n+1,0);
        queue<int>q;
        q.push(1);
        visit[1]=true;
        int ans=INT_MAX;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int i=0;i<a[node].size();i++){
                int neigh=a[node][i].first;
                int weigh=a[node][i].second;
                ans=min(weigh,ans);
                if(!visit[neigh]){
                    visit[neigh]=true;
                    q.push({neigh});
                }

            }
        }
        return ans;
        
    }
};