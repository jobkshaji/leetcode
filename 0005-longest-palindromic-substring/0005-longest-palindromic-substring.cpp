class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(n==0) return " ";
        int start=0;
        int maxlen=1;
        for(int i=0;i<n;i++){
            int l=i;
            int r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                int len=r-l+1;
                if(len>maxlen){
                    maxlen=len;
                    start=l;
                }
                l--;
                r++;
            }
            l=i;
            r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                int len=r-l+1;
                if(len>maxlen){
                    maxlen=len;
                    start=l;
                }
                l--;
                r++;
                
            }
        }
        return s.substr(start,maxlen);
    }
};