class Solution {
public:
    int hIndex(vector<int>& citations) {
       int n=citations.size();
       int l=0;
       int h=n-1; 
       int res=0;
       while(l<=h){
        int m=l+(h-l)/2;
        if(citations[m]>=n-m){
            res=n-m;
            h=m-1;
        }else{
            l=m+1;
        }
       }
       return res;
    }
};