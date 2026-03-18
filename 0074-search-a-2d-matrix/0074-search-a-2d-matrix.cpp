class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int n=a.size();
        int m=a[0].size();
        int l=0;
        int h=m*n-1;
        while(l<=h){
            int g=(l+h)/2;
            int r=g/m;
            int c=g%m;
            if(a[r][c]==target){
                return true;
            }
            if(a[r][c]<target){
                l=g+1;
            }else{
                h=g-1;
            }
        }
        return false;
    }
};