class Solution {
public:
    bool equal(vector<int>&a,vector<int>&c){
        for(int i=0;i<256;i++){
            if(a[i]<c[i]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int l=0;
        int h=0;
        int res=INT_MAX;
        int k=s.size();
        int j=t.size();
        int start=-1;
        vector<int>a(256,0);
        vector<int>c(256,0);
        if(j>k) return "";
        for(int i=0;i<j;i++){
            c[t[i]]++;
        }
        for(h=0;h<k;h++){
            a[s[h]]++;
            while(equal(a,c)){
                int len=h-l+1;
                if(res>len){
                    res=len;
                    start=l;
                }
                a[s[l]]--;
                l++;
            }
        }
        if(res==INT_MAX) return "";
        return s.substr(start,res);
    }
};