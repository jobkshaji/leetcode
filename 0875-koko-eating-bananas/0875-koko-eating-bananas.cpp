class Solution {
public:
    long long fun(vector<int>& piles,int n, int m){
        long long h=0;
        for(int i=0;i<n;i++){
            h=h+piles[i]/m;
            if(piles[i]%m!=0){
                h++;
            }
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int tar) {
        sort(piles.begin(),piles.end());
        int n=piles.size();
        int l=1;
        int h=piles[n-1];
        int res=-1;
        while(l<=h){
            int m=(l+h)/2;
            long long hr=fun(piles,n,m);
            if(hr>tar){
                l=m+1;
            }else{
                res=m;
                h=m-1;
            }
        }
        return res;
    }
};