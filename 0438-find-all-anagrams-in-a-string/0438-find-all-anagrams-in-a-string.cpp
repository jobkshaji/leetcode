class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>a(26,0);
        vector<int>b(26,0);
        for(int i=0;i<p.size();i++){
            a[p[i]-'a']++;
        }
        int l=0;
        int r=0;
        vector<int>tmp;
        while(r<s.size()){
            b[s[r]-'a']++;
            if(r-l+1 == p.size()){
                if(a==b) tmp.push_back(l);
            }
            if(r-l+1<p.size()) r++;
            else{
                b[s[l]-'a']--;
                l++;
                r++;
            }
        }
        return tmp;
    }
};