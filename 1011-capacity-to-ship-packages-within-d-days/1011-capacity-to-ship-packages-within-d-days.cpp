class Solution {
public:
    bool fun(vector<int>&weights,int m,int days){
        int sum=0;
        int d=1;
        for(int i=0;i<weights.size();i++){
            if(sum+weights[i]<=m){
                sum+=weights[i];
            }else{
                d++;
                sum=weights[i];
            }
        }
        if(d<=days) return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(),weights.end());
        int n=weights.size();
        int h=0;
        for(int i=0;i<n;i++){
            h+=weights[i];
        }
        int res=0;
        while(l<=h){
            int m=(l+h)/2;
            if(fun(weights,m,days)){
                res=m;
                h=m-1;
            }else{
                l=m+1;
            }
        }
        return res;
    }
};