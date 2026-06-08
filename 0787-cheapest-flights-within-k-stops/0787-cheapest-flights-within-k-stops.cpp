class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& edges, int src, int dst, int k) {
        vector<int>res(n,INT_MAX);
        res[src]=0;
        for(int i=0;i<=k;i++){
            vector<int>t=res;
            for(int j=0;j<edges.size();j++){
                int s=edges[j][0];
                int d=edges[j][1];
                int wt=edges[j][2];
                if(res[s]!=INT_MAX and t[d]>res[s]+wt){
                    t[d]=res[s]+wt;
                }
            }
            res=t;
        }
        if(res[dst]==INT_MAX) return -1;
        return res[dst];
    }
};