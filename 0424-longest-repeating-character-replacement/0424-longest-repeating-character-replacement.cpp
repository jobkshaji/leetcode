class Solution {
public:
    int find(vector<int>&f){
        int maxc=-1;
        for(int i=0;i<256;i++){
            maxc=max(maxc,f[i]);
        }
        return maxc;
    }
    int characterReplacement(string s, int k) {
        int l=0;
        int h=0;
        int n=s.size();
        int res=INT_MIN;
        vector<int>f(256,0);
        for(int h=0;h<n;h++){
            f[s[h]]++;
            int len=h-l+1;
            int maxdif=find(f);
            int dif=len-maxdif;
            while(dif>k){
                f[s[l]]--;
                l++;
                maxdif=find(f);
                len=h-l+1;
                dif=len-maxdif;
            }
            res=max(len,res);
        }
        if(res==INT_MIN) return -1;
        return res;
    }
};