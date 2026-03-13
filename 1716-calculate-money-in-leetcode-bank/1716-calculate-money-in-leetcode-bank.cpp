class Solution {
public:
    int totalMoney(int n) {
        int mon=1;
        int sum=mon;
        int res=mon+1;
        int cnt=1;
        for(int i=1;i<n;i++){
            if(cnt==7){
                mon++;
                res=0;
                res=mon+1;
                sum+=mon;
                cnt=1;
            }else{
                sum+=res;
                res++;
                cnt++;
            }
        }
        return sum;
    }
};