class Solution {
public:
    int mod=1e9+7;
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>score(n,vector<int>(m,-1));
        vector<vector<int>>ways(n,vector<int>(m,0));
        score[n-1][m-1]=0;
        ways[n-1][m-1]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(board[i][j]=='X' || board[i][j]=='S') continue;
                int best=-1;
                if(i+1<n){
                    best=max(best,score[i+1][j]);
                }
                if(j+1<m){
                    best=max(best,score[i][j+1]);
                }
                if(i+1<n && j+1<m){
                    best=max(best,score[i+1][j+1]);
                }
                if(best==-1){
                    continue;
                }
                long long cnt=0;
                if(i+1<n && score[i+1][j]==best){
                    cnt+=ways[i+1][j];
                }
                if(j+1<m && score[i][j+1]==best){
                    cnt+=ways[i][j+1];
                }
                if(i+1<n && j+1<m && score[i+1][j+1]==best){
                    cnt+=ways[i+1][j+1];
                }
                ways[i][j]=cnt%mod;
                if(board[i][j]=='E'){
                    score[i][j]=best;
                }else{
                    score[i][j]=best+(board[i][j]-'0');
                }
            }
        }
        if(ways[0][0]==0) return {0,0};
        return{score[0][0],ways[0][0]};
    }
};