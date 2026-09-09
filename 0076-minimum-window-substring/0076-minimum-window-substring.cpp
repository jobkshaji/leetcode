class Solution {
public:
    bool correct(vector<int>&f,vector<int>&m){
        for(int i=0;i<256;i++){
            if(f[i]<m[i]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int l=0;
        int n=s.size();
        int start=0;
        int res=INT_MAX;
        vector<int>m(256);
        for(int i=0;i<t.size();i++){
            m[t[i]-'A']++;
        }
        vector<int>f(256);
        for(int h=0;h<n;h++){
            f[s[h]-'A']++;
            while(correct(f,m)){
                int len=h-l+1;
                if(res>len){
                    res=len;
                    start=l;
                }
                f[s[l]-'A']--;
                l++;
            }
        }
        return (res==INT_MAX)?"":s.substr(start,res);
    }
};