class Solution {
public:
    void dfs(int n,int &i,vector<vector<int>>&adj,int &nodes,int &degreesum,vector<int>&vis){
        vis[i]=1;
        nodes++;
        degreesum+=adj[i].size();
        for(int j=0;j<adj[i].size();j++){
            int neigh=adj[i][j];
            if(!vis[neigh]){
                dfs(n,neigh,adj,nodes,degreesum,vis);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int>vis(n,0);
        int ans=0;;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int nodes=0;
                int degreesum=0;
                dfs(n,i,adj,nodes,degreesum,vis);
                int edgescnt=degreesum/2;
                if(edgescnt==nodes*(nodes-1)/2){
                    ans++;
                }
            }
        }
        return ans;
    }
};