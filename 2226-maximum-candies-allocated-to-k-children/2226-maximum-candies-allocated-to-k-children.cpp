class Solution {
public:
    bool fun(vector<int>&candies,long long m, long long k){
        long long cand=0;
        for(int i=0;i<candies.size();i++){
            cand+=candies[i]/m;
        }
        if(cand>=k) return true;
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int l=1;
        int h=*max_element(candies.begin(),candies.end());
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