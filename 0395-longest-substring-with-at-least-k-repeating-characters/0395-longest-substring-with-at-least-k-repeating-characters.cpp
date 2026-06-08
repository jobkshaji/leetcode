class Solution {
public:
    int longestSubstring(string s, int k) {
        int res=0;
        for(int target=1;target<=26;target++){
            int l=0;
            int h=0;
            int n=s.size();
            vector<int>f(26,0);
            int countk=0; //num of unique character having frequency k
            int unique=0; // num of unique charac
            while(h<n){
                if(f[s[h]-'a']==0){
                    unique++;
                }
                f[s[h]-'a']++;
                if(f[s[h]-'a']==k){
                    countk++;
                }
                h++;
                while(unique>target){
                    if(f[s[l]-'a']==k){
                        countk--;
                    }
                    f[s[l]-'a']--;
                    if(f[s[l]-'a']==0){
                        unique--;
                    }
                    l++;    
                }
                if(unique==target && target==countk){
                    res=max(res,h-l);
                }
            }
        }
        return res;
    }
};