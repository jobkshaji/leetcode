class Solution {
public:
    int find(vector<int>&a){
            int maxc=-1;
            for(int i=0;i<256;i++){
                maxc=max(maxc,a[i]);
            }
            return maxc;
        }
    int characterReplacement(string s, int k) {
        int n=s.size();
        int l=0,h=0;
        int res=INT_MIN;
        vector<int>f(256,0);
        for(h=0;h<n;h++){
            f[s[h]]++;
            int len=h-l+1;
            int maxcnt=find(f);
            int diff=len-maxcnt;
            if(diff>k){
                f[s[l]]--;
                l++;
                len=h-l+1;
                maxcnt=find(f);
                diff=len-maxcnt;
            }
            len=h-l+1;
            res=max(len,res);
        }
        if(res==INT_MIN){
            return 0;
        }else{
            return res;
        }
    }
};