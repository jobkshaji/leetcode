class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int total=n*m;
        k%=total;
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int indx=i*m+j;
                int newidx=(indx+k)%total;
                int newr=newidx/m;
                int newc=newidx%m;
                ans[newr][newc]=grid[i][j];
            }
        }
        return ans;
    }
};