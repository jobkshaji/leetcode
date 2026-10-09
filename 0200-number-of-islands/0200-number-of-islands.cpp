class Solution {
public:
    int x[4]={-1,1,0,0};
    int y[4]={0,0,-1,1};
    bool valid(int row,int col,int n, int m){
        if(row<0 || row>=n || col <0|| col>=m) return false;
        return true;
    }
    void dfs(vector<vector<char>>&grid, int n,int m , int i, int j , vector<vector<int>>&vis){
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int row=i+x[k];
            int col=j+y[k];
            if(valid(row,col,n,m) && vis[row][col]==0 && grid[row][col]=='1'){
                dfs(grid,n,m,row,col,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    dfs(grid,n,m,i,j,vis);
                    res++;
                }
            }
        }
        return res;
    }
};