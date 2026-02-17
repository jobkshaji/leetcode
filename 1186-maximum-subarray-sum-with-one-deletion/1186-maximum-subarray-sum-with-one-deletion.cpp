class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int nodelete=arr[0];
        int onedelete=INT_MIN;
        int result=arr[0];
        for(int i=1;i<arr.size();i++){
            int prevno=nodelete;
            int prevon=onedelete;
            nodelete=max(prevno+arr[i],arr[i]);
            int v2;
            if(prevon==INT_MIN){
                v2=arr[i];
            }else{
                v2=prevon+arr[i];
            }
            onedelete=max(v2,prevno);
            result=max(result,max(onedelete,nodelete));
        }
        return result;
    }
};