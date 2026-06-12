class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int nodelete=arr[0];
        int onedelete=INT_MIN;
        int ans=arr[0];
        for(int i=1;i<arr.size();i++){
            int prevnumber=nodelete;
            int prevonedel=onedelete;
            nodelete=max(prevnumber+arr[i],arr[i]);
            int v2;
            if(prevonedel==INT_MIN){
                v2=arr[i];
            }else{
                v2=prevonedel+arr[i];
            }
            onedelete=max(v2,prevnumber);
            ans=max(ans,max(onedelete,nodelete));
        }
        return ans;
    }
};