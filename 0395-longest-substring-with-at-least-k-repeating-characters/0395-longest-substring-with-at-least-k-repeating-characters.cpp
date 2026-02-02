class Solution {
public:
    int longestSubstring(string s, int k) {
        int n =s.size();
        int ans=0;
        for(int taru=1;taru<=26;taru++){
            int h=0,l=0;
            vector<int>f(26,0);
            int uni=0;
            int atk=0;
            while(h<n){
                if(f[s[h]-'a']==0){
                    uni++;
                }
                f[s[h]-'a']++;
                if(f[s[h]-'a']==k){
                    atk++;
                }
                h++;
                while(uni>taru){
                if(f[s[l]-'a']==k){
                    atk--;
                }
                f[s[l]-'a']--;
                if(f[s[l]-'a']==0){
                    uni--;
                }
                l++;
               }
               if(uni==taru && atk==taru){
                ans=max(ans,h-l);
                }
        }
        }
        return ans;
    }
};