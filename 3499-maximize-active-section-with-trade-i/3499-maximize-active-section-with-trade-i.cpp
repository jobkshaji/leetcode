class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int>count;
        int n=s.size();
        int maxsum=0;
        int cnt=0;
        int posi=0;
        for(int i=0;i<n;i++){
            if(i!=0 && s[i]!=s[i-1]){
                count.push_back(cnt);
                cnt=0;
            }
            if(s[i]=='0'){
                cnt--;
            }else{
                cnt++;
            }
        }
        count.push_back(cnt);
        for(int i:count){
            if(i>0){
                posi+=i;
            }
        }
        maxsum=posi;
        for(int i=0;i<count.size()-1;i++){
            if(i>0 && count[i-1]<0 && count[i+1]<0 && count[i]>0){
                maxsum=max(maxsum,(posi+abs(count[i-1]+count[i+1])));
            }
        }
        return maxsum;
    }
};