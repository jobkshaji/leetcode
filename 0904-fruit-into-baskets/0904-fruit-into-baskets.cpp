class Solution {
public:
    int totalFruit(vector<int>& f) {
        int n=f.size();
        int l=0,h=0;
        int res=INT_MIN;
        unordered_map<int,int>mp;
        for(h=0;h<n;h++){
            mp[f[h]]++;
            while(mp.size()>2){
                mp[f[l]]--;
                if(mp[f[l]]==0){
                    mp.erase(f[l]);
                }
                l++;
            }
            if(mp.size()==2 || mp.size()<2){
                int len=h-l+1;
                res=max(len,res);
            }
        }
        return res;
    }
};