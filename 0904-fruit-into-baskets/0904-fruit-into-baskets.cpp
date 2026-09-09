class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0;
        int n=fruits.size();
        unordered_map<int,int>mp;
        int len=INT_MIN;
        for(int h=0;h<n;h++){
            mp[fruits[h]]++;
            while(mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0){
                    mp.erase(fruits[l]);
                }
                l++;
            }
            if(mp.size()==2 || mp.size()<2){
                len=max(len,h-l+1);
            }
        }
        return(len==INT_MIN)?0:len;
    }
};