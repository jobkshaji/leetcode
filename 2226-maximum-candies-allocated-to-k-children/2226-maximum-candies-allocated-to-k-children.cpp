class Solution {
public:
    bool fun(vector<int>&candies , long long m , long long k){
        int n=candies.size();
        long long cnt=0;
        for(int i=0;i<n;i++){
            cnt+=candies[i]/m;
            if(cnt>=k) return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        int mx=0;
        for(int i=0;i<n;i++){
            mx=max(mx,candies[i]);
        }
        long long l=1;
        long long h=mx;
        long long res=0;
        while(l<=h){
            long long m=(l+h)/2;
            if(fun(candies,m,k)){
                res=m;
                l=m+1;
            }else{
                h=m-1;
            }
        }
        return res;
    }
};