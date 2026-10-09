class Solution {
public:
    int x[4]={-1,1,0,0};
    int y[4]={0,0,-1,1};
    bool valid(int i,int j, int n,int m){
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int t=0;
        queue<pair<int,int>>pq;
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    pq.push({i,j});
                    grid[i][j]=-2;
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        while(!pq.empty() && fresh >0){
            t++;
            int s=pq.size();
            while(s--){
                pair<int,int>p=pq.front();
                pq.pop();
                int row=p.first;
                int col=p.second;
                for(int k=0;k<4;k++){
                    int r=row+x[k];
                    int c=col+y[k];
                    if(valid(r,c,n,m)&& grid[r][c]==1){
                        pq.push({r,c});
                        grid[r][c]=-2;
                        fresh--;
                    }
                }
            }

        }
        if(fresh >0) return -1;
        return t;
    }
};