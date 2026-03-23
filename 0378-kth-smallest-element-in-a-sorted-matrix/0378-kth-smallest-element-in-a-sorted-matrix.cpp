class Solution {
public:
    int fun(vector<vector<int>>&a , int n, int m , int g){
        int r=n-1;
        int c=0;
        int cnt=0;
        while(r>=0 && c<m){
            if(a[r][c]<=g){
                cnt=cnt+r+1;
                c++;
            }else{
                r--;
            }
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& a, int k) {
        int n=a.size();
        int m=a[0].size();
        int l=a[0][0];
        int h=a[n-1][m-1];
        int res=-1;
        while(l<=h){
            int g=(l+h)/2;
            int ans=fun(a,n,m,g);
            if(ans<k){
                l=g+1;
            }else{
                res=g;
                h=g-1;
            }
        }
        return res;  
    }
};