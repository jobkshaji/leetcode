class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>safe(n,vector<int>(n,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    safe[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        vector<int>dx={1,-1,0,0};
        vector<int>dy={0,0,-1,1};
        while(!q.empty()){
            pair<int,int>p=q.front();
            q.pop();
            int x=p.first;
            int y=p.second;
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0 && ny>=0 && nx<n && ny<n && safe[nx][ny]==INT_MAX){
                    safe[nx][ny]=safe[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
        vector<vector<int>>best(n,vector<int>(n,-1));
        priority_queue<vector<int>>pq;
        pq.push({safe[0][0],0,0});
        best[0][0]=safe[0][0];
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int score=curr[0];
            int row=curr[1];
            int col=curr[2];
            if(row==n-1 && col==n-1){
                return score;
            }
            if(score<best[row][col]) continue;
            for(int k=0;k<4;k++){
                int r=row+dx[k];
                int c=col+dy[k];
                if(r<0 || c<0 || r>=n|| c>=n) continue;
                int newscore=min(score,safe[r][c]);
                if(newscore>best[r][c]){
                    best[r][c]=newscore;
                    pq.push({best[r][c],r,c});
                }
            }
        }
        return 0;
    }
};