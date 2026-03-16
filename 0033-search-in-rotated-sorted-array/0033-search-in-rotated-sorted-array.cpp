class Solution {
public:
    int search(vector<int>& a, int target) {
        int n=a.size();
        int l=0;
        int h=n-1;
        while(l<=h){
            int m=(l+h)/2;
            if(a[m]==target){
                return m;
            }
            if(a[m]>a[n-1]){
                if(a[m]>target){
                    if(a[0]>target){
                        l=m+1;
                    }else{
                        h=m-1;
                    }
                }else{
                    l=m+1;
                }
            }else{
                if(a[m]<target){
                    if(a[n-1]<target){
                        h=m-1;
                    }else{
                        l=m+1;
                    }
                }else{
                    h=m-1;
                }
            }
        }
        return -1;
    }
};