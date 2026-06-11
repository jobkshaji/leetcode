class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        int wordlen=words[0].size();
        int wordcount=words.size();
        unordered_map<string,int>mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        for(int offset=0;offset<wordlen;offset++){
            int l=offset;
            int count=0;
            unordered_map<string,int>seen;
            for(int r=offset;r+wordlen<=s.size();r+=wordlen){
                string a=s.substr(r,wordlen);
                if(mp.count(a)){
                    seen[a]++;
                    count++;
                    while(seen[a]>mp[a]){
                    string left=s.substr(l,wordlen);
                    seen[left]--;
                    count--;
                    l+=wordlen;
                   }
                   if(count==wordcount){
                    ans.push_back(l);
                    string left=s.substr(l,wordlen);
                    seen[left]--;
                    count--;
                    l+=wordlen;
                   }
                }
                else{
                    seen.clear();
                    count=0;
                    l=r+wordlen;
                }

            }
        }
        return ans;
    }
};