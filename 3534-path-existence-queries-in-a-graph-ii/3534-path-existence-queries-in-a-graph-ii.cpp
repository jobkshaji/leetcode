class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>>a;
        for(int i=0;i<n;i++){
            a.push_back({nums[i],i});
        }
        sort(a.begin(),a.end());
        vector<int>pos(n);
        for(int i=0;i<n;i++){
            pos[a[i].second]=i;
        }
        int j=0;
        vector<int>next(n);
        for(int i=0;i<n;i++){
            while(j+1<n && a[j+1].first-a[i].first<=maxDiff){
                j++;
            }
            next[i]=j;
        }
        const int LOG=18;
        vector<vector<int>>up(LOG,vector<int>(n));
        for(int i=0;i<n;i++){
            up[0][i]=next[i];
        }
        for(int k=1;k<LOG;k++){
            for(int i=0;i<n;i++){
                up[k][i]=up[k-1][up[k-1][i]];
            }
        }
        vector<int>ans;
        for(auto q:queries){
            int u=pos[q[0]];
            int v=pos[q[1]];
            if(u>v) swap(u,v);
            if(u==v){
                ans.push_back(0);
                continue;
            }
            if(u==v){
                ans.push_back(-1);
            }
            int res=0;
            int curr=u;
            for(int k=LOG-1;k>=0;k--){
                if(up[k][curr]<v){
                    curr=up[k][curr];
                    res+=(1 << k);
                }
            }
            if(next[curr]<v){
                ans.push_back(-1);
            }else{
                ans.push_back(res+1);
            }
        }
        return ans;
    }
};