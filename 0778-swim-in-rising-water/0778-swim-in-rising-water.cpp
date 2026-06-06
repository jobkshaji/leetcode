class Solution {
public:
    bool valid(int n, int m , int i ,int j){
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }
    int swimInWater(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size();
        vector<vector<int>>res(n);
        for(int i=0;i<n;i++){
            vector<int>t(m,INT_MAX);
            res[i]=t;
        }
        priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        pq.push({a[0][0],{0,0}});
        res[0][0]=a[0][0];
        while(!pq.empty()){
            pair<int,pair<int,int>>p=pq.top();
            pq.pop();
            int money=p.first;
            int row=p.second.first;
            int col=p.second.second;
            if(money>res[row][col]) continue;
            int x[4]={-1,1,0,0};
            int y[4]={0,0,-1,1};
            for(int k=0;k<4;k++){
                int r=row+x[k];
                int c=col+y[k];
                if(!valid(n,m,r,c)) continue;
                int newm=max(money,a[r][c]);
                if(newm<res[r][c]){
                    res[r][c]=newm;
                    pq.push({newm,{r,c}});
                }
            }
        }
        return res[n-1][m-1];
    }
};