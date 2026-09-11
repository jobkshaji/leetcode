class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int nodel=arr[0];
        int onedel=INT_MIN;
        int ans=arr[0];
        for(int i=1;i<arr.size();i++){
            int prevno=nodel;
            int prevone=onedel;
            nodel=max(nodel+arr[i],arr[i]);
            int v2;
            if(onedel==INT_MIN){
                v2=arr[i];
            }else{
                v2=prevone+arr[i];
            }
            onedel=max(v2,prevno);
            ans=max(ans,max(nodel,onedel));
        }
        return ans;
    }
};