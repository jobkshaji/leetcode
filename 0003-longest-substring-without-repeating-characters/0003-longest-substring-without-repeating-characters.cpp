class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int h=0;
        int n=s.size();
        int res=INT_MIN;
        unordered_map<char,int>f;
        for(int h=0;h<n;h++){
            f[s[h]]++;
            int len=h-l+1;
            while(f.size()<len){
                f[s[l]]--;
                if(f[s[l]]==0) f.erase(s[l]);
                l++;
                len=h-l+1;
            }
            /*int k=h-l+1;*/
            res=max(res,len);
        }
        if(res==INT_MIN) return 0;
        return res;
    }
};