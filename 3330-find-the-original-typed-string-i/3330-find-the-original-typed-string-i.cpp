class Solution {
public:
    int possibleStringCount(string word) {
        unordered_map<char,int>mp;
        int res=1;
        int n=word.size();
        for(int i=0;i<n-1;i++){
            if(word[i]==word[i+1]){
                mp[word[i]]++;
            }
        }
        for(auto i:mp){
            if(i.second>=1){
                res=res+i.second;
            }
        }
        return res;
    }
};