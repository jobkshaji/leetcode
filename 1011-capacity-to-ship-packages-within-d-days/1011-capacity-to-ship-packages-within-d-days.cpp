class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(),weights.end());
        int h=0;
        int n=weights.size();
        for(int i=0;i<weights.size();i++){
            h+=weights[i];
        }
        int res=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            int sum=0;
            int d=1;
            for(int i=0;i<n;i++){
                if(sum+weights[i]<=mid){
                    sum+=weights[i];
                }else{
                    d++;
                    sum=weights[i];
                }
            }
            if(d<=days){
                res=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return res;
    }
};