class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int n=s.size();
        int lon=INT_MIN;
        unordered_map<char,int>mp;
        for(int h=0;h<n;h++){
            mp[s[h]]++;
            int len=h-l+1;
            while(len>mp.size()){
                mp[s[l]]--;
                if(mp[s[l]]==0){
                    mp.erase(s[l]);
                }
                l++;
                len=h-l+1;
            }
            lon=max(lon,len);
        }
        return (lon==INT_MIN)?0:lon;
    }
};