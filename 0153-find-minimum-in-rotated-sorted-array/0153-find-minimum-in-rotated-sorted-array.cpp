class Solution {
public:
    int findMin(vector<int>& a) {
        int n=a.size();
        int l=0;
        int h=n-1;
        int res=-1;
        while(l<=h){
            int m=(l+h)/2;
            if(a[m]<=a[n-1]){
                res=m;
                h=m-1;
            }else{
                l=m+1;
            }
        }
        return a[res];
    }
};