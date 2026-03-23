class Solution {
public:
    int fun(int m , int n , int g){
        int cnt=0;
        for(int i=1;i<=m;i++){
            cnt+=min(n,g/i);
        }
        return cnt;
    }
    int findKthNumber(int m, int n, int k) {
        int l=1;
        int h=m*n;
        int res=-1;
        while(l<=h){
            int g=(l+h)/2;
            int ans=fun(m,n,g);
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