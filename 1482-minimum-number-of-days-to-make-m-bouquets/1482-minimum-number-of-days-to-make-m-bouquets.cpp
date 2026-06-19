class Solution {
public:
    int fun(vector<int>&bloomDay,int m,int k,int n){
        int bouq=0;
        int flower=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=m){
                flower++;
                if(flower==k){
                    bouq++;
                    flower=0;
                }
            }else{
                flower=0;
            }
        }
        return bouq;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int l=*min_element(bloomDay.begin(),bloomDay.end());
        int h=*max_element(bloomDay.begin(),bloomDay.end());
        int res=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            int bouquets=fun(bloomDay,mid,k,n);
            if(bouquets>=m){
                res=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return res;
    }
};