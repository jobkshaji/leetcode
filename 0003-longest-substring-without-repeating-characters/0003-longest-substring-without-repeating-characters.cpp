class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0,h=0;
        int res=INT_MIN;
        unordered_map<int,int>f;
        for(h=0;h<n;h++){
            f[s[h]]++;
            int k =h-l+1;
            while(f.size()<k){
                f[s[l]]--;
                if(f[s[l]]==0){
                    f.erase(s[l]);
                }
                l++;
                k=h-l+1;
            }
            int len=h-l+1;
            res=max(len,res);
        }
        if(res==INT_MIN){
            return 0;
        }else{
            return res;
        }
    }
};