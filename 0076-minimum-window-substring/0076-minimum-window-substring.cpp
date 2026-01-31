class Solution {
public:
    bool fine(vector<int>&a,vector<int>&c){
        for(int i=0;i<256;i++){
            if(a[i]<c[i]){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n=t.size();
        int k=s.size();
        vector<int>a(256,0);
        vector<int>c(256,0);
        int res=INT_MAX;
        int l=0,h=0;
        int start=-1;
        if(k<n)
        return "";
        for(int i=0;i<n;i++){
            c[t[i]]++;
        }
        for(h=0;h<k;h++){
            a[s[h]]++;
            while(fine(a,c)){
                int len=h-l+1;
                if(res>len){
                    res=len;
                    start=l;
                }
                a[s[l]]--;
                l++;
            }
        }
        if(res==INT_MAX) return"";
        return s.substr(start,res);
    }
};