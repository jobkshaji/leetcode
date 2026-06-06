class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int skipS=0;
        int skipT=0;
        int n=s.size();
        int m=t.size();
        int i=n-1;
        int j=m-1;
        while(i>=0 || j>=0){
            while(i>=0){
                if(s[i]=='#'){
                    skipS++;
                    i--;
                }else if(skipS>0){
                    skipS--;
                    i--;
                }else{
                    break;
                }
            }
            while(j>=0){
                if(t[j]=='#'){
                    skipT++;
                    j--;
                }else if(skipT>0){
                    skipT--;
                    j--;
                }else{
                    break;
                }
            }
            if(i>=0 and j>=0){
                if(s[i]!=t[j]) return false;
            }else if(i>=0 || j>=0) return false;
            i--;
            j--;
        }
        return true;
    }
};