class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>best(n,vector<int>(m,-1));
        queue<tuple<int,int,int>>pq;
        int starthealth=health-grid[0][0];
        if(starthealth<=0){
            return false;
        }
        pq.push({starthealth,0,0});
        best[0][0]=starthealth;
        vector<int>dx={1,-1,0,0};
        vector<int>dy={0,0,-1,1};
        while(!pq.empty()){
            auto[h,row,col]=pq.front();
            pq.pop();
            if(row==n-1 && col==m-1){
                return true;
            }
            for(int k=0;k<4;k++){
                int r=row+dx[k];
                int c=col+dy[k];
                if(r>=0 && c>=0 && r<n && c<m){
                    int newheal=h-grid[r][c];
                    if(newheal<=0) continue;
                    if(newheal>best[r][c]){
                        best[r][c]=newheal;
                        pq.push({newheal,r,c});
                    }
                }
            }

        }
        return false;
    }
};