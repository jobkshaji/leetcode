class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        int n=a.size();
        int l=0;
        int h=n-1;
        while(l<=h){
            int m=(l+h)/2;
            if(a[m]>a[m+1]){
                if(a[m]<a[m-1]){
                    h=m-1;
                }else{
                    return m;
                }
            }else{
                l=m+1;
            }
        }
        return -1;
    }
};