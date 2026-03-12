class Solution {
public:
    int first(vector<int>& a ,int target){
        int n=a.size();
        int res=-1;
        int l=0;
        int h=n-1;
        while(l<=h){
            int m=(l+h)/2;
            if(a[m]>target){
                h=m-1;
            }else if(a[m]<target){
                l=m+1;
            }else{
                res=m;
                h=m-1;
            }
        }
        return res;
    }
    int last(vector<int>& a , int target){
        int n=a.size();
        int res=-1;
        int l=0;
        int h=n-1;
        while(l<=h){
            int m=(l+h)/2;
            if(a[m]>target){
                h=m-1;
            }else if(a[m]<target){
                l=m+1;
            }else{
                res=m;
                l=m+1;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& a, int target) {
        vector<int>res;
        int fir=first(a,target);
        int las=last(a,target);
        res.push_back(fir);
        res.push_back(las);
        return res;
    }
};