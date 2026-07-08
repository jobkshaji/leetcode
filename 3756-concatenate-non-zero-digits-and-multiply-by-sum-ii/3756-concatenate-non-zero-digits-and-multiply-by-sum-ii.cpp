class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m =queries.size();
        int n=s.size();
        long long mod=1e9+7;
        vector<int>arr(m);
        vector<long long>preSum(n+1,0);
        vector<long long>preCnt(n+1,0);
        vector<long long>preVal(n+1,0);
        vector<long long>power(n+1,1);

        for(int i=1;i<n;i++){
            power[i]=(power[i-1]*10)%mod;
        }
        for(int i=0;i<n;i++){
            int d=s[i]-'0';
            preSum[i+1]=preSum[i]+d;
            preCnt[i+1]=preCnt[i]+(d!=0);
            if(d==0){
                preVal[i+1]=preVal[i];
            }else{
                preVal[i+1]=(preVal[i]*10+d)%mod;
            }
        }
        for(int i=0;i<m;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int len=preCnt[r+1]-preCnt[l];
            long long start=preVal[l];
            long long end=preVal[r+1];
            long long sum=preSum[r+1]-preSum[l];
            long long x=(end-(start*power[len])%mod+mod)%mod;
            arr[i]=(x*sum)%mod;            
        }
        return arr;
    }
};