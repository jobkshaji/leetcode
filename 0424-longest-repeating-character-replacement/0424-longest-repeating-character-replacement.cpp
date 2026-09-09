class Solution {
public:
    int count(vector<int>&f){
        int cnt=0;
        for(int i=0;i<26;i++){
            cnt=max(cnt,f[i]);
        }
        return cnt;
    }
    int characterReplacement(string s, int k) {
        int l=0;
        int n=s.size();
        vector<int>f(26);
        int lon=INT_MIN;
        for(int h=0;h<n;h++){
            f[s[h]-'A']++;
            int len=h-l+1;
            int maxnt=count(f);
            int diff=len-maxnt;
            while(diff>k){
                f[s[l]-'A']--;
                l++;
                len=h-l+1;
                maxnt=count(f);
                diff=len-maxnt;
            }
            lon=max(lon,len);
        }
        return (lon==INT_MIN)?0:lon;
    }
};