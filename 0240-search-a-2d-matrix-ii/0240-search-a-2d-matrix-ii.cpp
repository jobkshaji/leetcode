class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int n=a.size();
        int m=a[0].size();
        int r=n-1;
        int c=0;
        while(r>=0 && c<m){
            if(a[r][c]==target){
                return true;
            }
            if(a[r][c]>target){
                r--;
            }else{
                c++;
            }
        }
        return false;
    }
};